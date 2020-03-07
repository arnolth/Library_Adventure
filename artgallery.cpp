/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (artGallery (L4) source file)
 *****************************************************************************/

#include "artgallery.hpp"

/*******************************************************************************
 ** constructor 
*******************************************************************************/
Art::Art() : Space() {
    this->level = 4;
    
    this->up = nullptr;
    this->down = nullptr;
    this->elevator = nullptr;
    this->exit = nullptr;
    
    //set up collections
    //art books
    art.addItem("Hyperbole and a half");
    art.addItem("Am I there yet?: the loop-de-loop, zigzagging journey"
                "to adulthood");
    art.addItem("Destination art : 500 artworks worth the trip");
    art.addItem("Broad strokes : 15 women who made art and made history "
                "(in that order)");
    art.addItem("The Gothic enterprise: a guide to understanding the Medieval "
                "cathedral");
    art.addItem("Alexander McQueen: savage beauty");
    //travel display
    travel.addItem("The New York Times 36 hours: 150 weekends in the USA "
                   "& Canada");
    travel.addItem("Atlas obscura : an explorer's guide to the world's "
                   "hidden wonders");
    travel.addItem("Rick Steves' Prague & the Czech Republic");
    travel.addItem("The great Atlantic Canada Bucket list: one-of-a-kind travel"
                   " experiences");
    travel.addItem("Journeys of a lifetime: 500 of the world's greatest trips");
    //history books
    hist.addItem("Sapiens: a brief history of humankind");
    hist.addItem("How to behave badly in Elizabethan England");
    hist.addItem("The lost city of the Monkey God: a true story");
    hist.addItem("1491 : new revelations of the Americas before Columbus");
    //biographies
    bio.addItem("Educated: a memoir");
    bio.addItem("The glass castle: a memoir");
    bio.addItem("I Know Why the Caged Bird Sings");
    bio.addItem("Hillbilly Elegy: a memoir of a family and culture in crisis");
}

/*******************************************************************************
 ** description: prints description of the level
*******************************************************************************/
void Art::description(){
    std::cout << "The City Library has a long history of supporting the arts "
    "through a \nprogram of changing exhibits. These exhibits expose thousands "
    "of Salt \nLake City residents to a wide variety of art media, including "
    "paintings, \nwatercolors, drawings, collage, photography, and sculpture. "
    "The rest of \nthe floor contains books with subjects in art, literature "
    "and history, \nbetween 700-999 according to the Dewey Decimal system" <<
    std::endl;
}

/******************************************************************************
 ** move: prints level description and map and lets player know what they can
 ** see. Then gets players choice of what they would like to do on that level
*******************************************************************************/
Space* Art::move(Player* p){
    int dir;
    
    //print level and player update
    std::cout << "\n\n\t---- Welcome to level 4: Nonfiction, Art Gallery ----\n"
    "You have the energy to walk up " << p->getEnergy() <<
    " more flights of stairs.\n"
    "Your tote bag contains: " <<std::endl;
    p->printTote();
    
    //print description of the level and map showing location in the buiding.
    description();
    printMap(level);
    
    while (true){
        dir = directionMenu();
        switch(dir){
            case 1: //up
                if (p->getEnergy() > 0){
                    std::cout << "You climb the stairs to level 5" << std::endl;
                    p->decEnergy(); //player loses 1 energy climbing the stairs
                    return up;
                }
                else{
                    std::cout << "You don't have enough energy to climb the "
                    "stairs. Look around, \nyou might find something "
                    "intereseting that will boost your energy." << std::endl;
                }
                break;
            case 2: //down
                std::cout << "You go down the stairs to level 3" << std::endl;
                break;
            case 3: //left
                lookAround(p);
                break;
        }
    }
}

/*******************************************************************************
 ** lookAround: gives a description of what the player can see and gives
 ** options to investigate different areas
*******************************************************************************/
void Art::lookAround(Player* p){
    std::cout << "To the right you see the entrance to the art gallery. "
    "Straight ahead is \nsome sort of travel display. You can also see areas "
    "where there appear to \nbe art books, biographies and history books. What "
    "would you like to do?" << std::endl;
    std::cout << "\t(1) look at the travel display" << '\n';
    std::cout << "\t(2) look at the art section" << '\n';
    std::cout << "\t(3) explore the art gallery" << '\n';
    std::cout << "\t(4) look at the histroy books" << '\n';
    std::cout << "\t(5) look at the biography section" << '\n';
    std::cout << "\t(6) do nothing" << std::endl;
    int look = validateChoice(1, 6);
    
    
    switch(look){
        case 1:
            std::cout << "Examining the travel display you find some "
            "interesting things: " << std::endl;
            travel.examine(p);
            std::cout << "This makes you sad because you can't afford to go on "
            "vacation. You \nlose an enery point." << std::endl;
            p->decEnergy();
            std::cout << "You have the energy to walk up " << p->getEnergy() <<
            " more flights of stairs." << std::endl;
            break;
        case 2:
            std::cout << "Browsing the art books you find some interesting "
            "things: " << std::endl;
            art.examine(p);
            break;
        case 3:
            std::cout << "The current exhibit in the gallery is TRACING THE "
            "PATH: Chinese Railrod \nWorkers and the First Transcontinental "
            "Railroad. May 10, 2019 is the 150th \naniversary of placing the "
            "Golden Spike connecting the to join the \nrails of the first "
            "transcontinetal railroad. The artist traveled the\nrailroad "
            "matches modern photos with photos that were taken during the\n"
            "railroad's construction. You gain an energy point for learning \n"
            "something new." << std::endl;
            p->incEnergy();
            std::cout << "You have the energy to walk up " << p->getEnergy() <<
            " more flights of stairs." << std::endl;
            break;
        case 4:
            std::cout << "Browsing the history section you find some "
            "interesting things: " << std::endl;
            hist.examine(p);
            break;
        case 5:
            std::cout << "Browsign the biographies you find some interesting "
            "things: " << std::endl;
            bio.examine(p);
            break;
        default:
            //do nothing
            break;
    }
}
