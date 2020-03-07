/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (ground floor (L1) source file)
 *****************************************************************************/

#include "ground.hpp"

/*******************************************************************************
 ** constructor
*******************************************************************************/
Ground::Ground() : Space() {
    this->level = 1;
    
    this->up = nullptr;
    this->down = nullptr;
    this->elevator = nullptr;
    this->exit = nullptr;
    
    //set up collections
    dvds.addItem("Downton Abbey");
    dvds.addItem("Stranger Things");
    dvds.addItem("Psyco Pass");
    dvds.addItem("Hot Fuzz");
    dvds.addItem("Moonrise Kingdom");
    dvds.addItem("Before Sunrise");
    dvds.addItem("Jurassic Park");
    dvds.addItem("Amelie");
    
    cds.addItem("The classical cello collection - Yo-Yo Ma");
    cds.addItem("Delta - Mumford & Sons");
    cds.addItem("1000 forms of fear - Sia");
    cds.addItem("Whistle down the wind - Joan Baez");
    cds.addItem("Classic Queen - Queen");
    
    lab.addItem("print a poster");
    lab.addItem("make a sticker");
    lab.addItem("use the sewing machine");
    lab.addItem("play a VR game");
    lab.addItem("use the 3D printer");
}

/******************************************************************************
 ** description: prints description of the level
******************************************************************************/
void Ground::description(){
    std::cout << "The Library is pleased to be able to provide a space where "
    "you can enjoy a\ndrink or snack from The Library Cafe. The audiovisual "
    "collection, including \nCDs, DVDs, and more, houses the most popular items"
    " in the library, according \nto circulation statistics. The main entrance "
    "(and exit) is on this level." << std::endl;
}

/******************************************************************************
 ** move: prints level description and map and lets player know what they can
 ** see. Then gets players choice of what they would like to do on that level
*******************************************************************************/
Space* Ground::move(Player* p){
    int dir;
    
    //print level and player update
    std::cout << "\n\n\t-- Welcome to level 1: Cafe, Audiovisual, Creative Lab"
    "--\nYou have the energy to walk up " << p->getEnergy() <<
    " more flights of stairs.\n"
    "Your tote bag contains: " <<std::endl;
    p->printTote();
    
    //print description of the level and map showing location in the buiding.
    description();
    printMap(level);
    
    while (true){
        dir = directionMenuExit();
        switch(dir){
            case 1: //up
                std::cout << "You climb the stairs to level 2" << std::endl;
                p->decEnergy(); //player loses 1 energy climbing the stairs
                return up;
                break;
            case 2: //down
                std::cout << "\nYou go down the stairs to level -1" << std::endl;
                return down;
                break;
            case 3: //left
                lookAround(p);
                break;
            case 4:
                return exit;
            default:
                break;
        }
    }
}

/*******************************************************************************
 ** lookAround: gives a description of what the player can see and gives
 ** options to investigate different areas
*******************************************************************************/
void Ground::lookAround(Player* p){
    std::cout << "You see the cafe and some comfy chairs next to the magazine "
    "racks. You\nsee shelves full of DVDs and drawers full of CDs Behind a "
    "glass wall is a \nbunch of tech stuff, it must be the creative lab.\n"
    "What would you like to do?" << std::endl;
    std::cout << "\t(1) get something from the cafe" << '\n';
    std::cout << "\t(2) read a magazine" << '\n';
    std::cout << "\t(3) look at the DVDs " << '\n';
    std::cout << "\t(4) look at the CDs" << '\n';
    std::cout << "\t(5) explore the creative lab" << '\n';
    std::cout << "\t(6) do nothing" << std::endl;
    int look = validateChoice(1, 7);
    
    switch(look){
        case 1: {
            std::cout << "What would you like?" << std::endl;
            std::cout << "\t(1) coffee" << '\n';
            std::cout << "\t(2) tea" << '\n';
            std::cout << "\t(3) hot chocolate" << '\n';
            std::cout << "\t(4) pastery" << '\n';
            std::cout << "\t(5) water" << std::endl;
            int cafe = validateChoice(1, 5);
            switch(cafe){
                case 1:
                    std::cout << "You enjoy a hot cup of coffee." <<std::endl;
                    break;
                case 2:
                    std::cout << "You have a tastey cup of green tea." <<std::endl;
                    break;
                case 3:
                    std::cout << "You enjoy a rich mug of hot cocoa. You feel "
                    "all cozy and sleepy. You lose an energy point." << std::endl;
                    p->decEnergy();
                    std::cout << "You have the energy to walk up " <<
                    p->getEnergy() << " more flights of stairs." << std::endl;
                    break;
                case 4:
                    std::cout << "You just ate a really yummy croissant. "
                    "You gain an energy point." <<std::endl;
                    p->incEnergy();
                    std::cout << "You have the energy to walk up " <<
                    p->getEnergy() << " more flights of stairs." << std::endl;
                    break;
                case 5:
                    std::cout << "You are refreshed by some ice cold water. "
                    "You gain an energy point." <<std::endl;
                    p->incEnergy();
                    std::cout << "You have the energy to walk up " <<
                    p->getEnergy() << " more flights of stairs." << std::endl;
                    break;
            }
            break;
        }
        case 2:
            std::cout << "There are too many magazines to choose from. You "
            "decide that you would \nrather do something else." << std::endl;
            break;
        case 3:
            std::cout << "Browsing the DVD section you find some "
            "interesting things: " << std::endl;
            dvds.examine(p); //examine the DVD section
            break;
        case 4:
            std::cout << "Browsing the CD section you find some "
            "interesting things: " << std::endl;
            cds.examine(p); //examine the CD section
            break;
        case 5: {
            std::cout << "You go into the creative lab and see some really cool"
                            " stuff." << std::endl;
            lab.printColl();
            int lab = validateChoice(1, 5);
            switch(lab){
                case 1:
                    std::cout << "You print a poster size version of your"
                    " latest drawing." << std::endl;
                    break;
                case 2:
                    std::cout << "You make a cool sticker and add it to your "
                    "waterbottle. You gain an energy point." << std::endl;
                    p->incEnergy();
                    break;
                case 3:
                    std::cout << "Next time you need to use a sewing machine "
                    "you'll come here." << std::endl;
                    break;
                case 4:
                    std::cout << "Playing VR makes you kind of nauseous. You"
                    " lose an energy point." << std::endl;
                    p->decEnergy();
                    std::cout << "You have the energy to walk up " <<
                    p->getEnergy() << " more flights of stairs." << std::endl;
                    break;
                case 5:
                    std::cout << "You make a keychain using the 3D printer. "
                    "You gain an energy point." << std::endl;
                    p->incEnergy();
                    break;
            }
            break;
        }
        default:
            //do mothing
            break;
    }
}
