/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (fiction (L2) source file)
 *****************************************************************************/

#include "fiction.hpp"

/*******************************************************************************
 ** constructor
*******************************************************************************/
Fiction::Fiction() : Space() {
    this->level = 2;
    
    this->up = nullptr;
    this->down = nullptr;
    this->elevator = nullptr;
    this->exit = nullptr;
    
    //set up collections
    //teen books
    teen.addItem("Coldest Girl in Coldtown");
    teen.addItem("The Maze Runner");
    teen.addItem("Dread Nation");
    teen.addItem("A Court of Thornes and Roses");
    teen.addItem("The Sacred Lies of Minnow Bly");
    teen.addItem("The Hate U Give");
    //classics display
    classics.addItem("Jane Eyre");
    classics.addItem("Rebecca");
    classics.addItem("One Hundred Years of Solitude");
    classics.addItem("To Kill a Mockingbird");
    classics.addItem("Nineteen Eighty-four");
    classics.addItem("Catcher in the Rye");
    //fiction collection
    fic.addItem("A Man Called Ove");
    fic.addItem("All the Light We Cannot See");
    fic.addItem("Ocean at the End of the Lane");
    fic.addItem("Girl on the Train");
    fic.addItem("The Kite Runner");
    fic.addItem("The First Fifteen Lives of Harry August");
    fic.addItem("Name of the Wind");
    fic.addItem("The Martian");
}

/*******************************************************************************
 ** description: prints description of the level
*******************************************************************************/
void Fiction::description(){
    std::cout << "The City Library has a dedicated teen area, a great ficton "
    "collection, and\nan extensive collection of newspapers and magazines "
    "dating back to the\n19th century. The CanTEENa, an area dedicated to "
    "teens, contains young \nadult fiction, study areas, a TV where teens can "
    "watch \n movies or play\nvideo games. " << std::endl;
}

/******************************************************************************
 ** move: prints level description and map and lets player know what they can
 ** see. Then gets players choice of what they would like to do on that level
******************************************************************************/
Space* Fiction::move(Player* p){
    int dir;
    
    //print level and player update
    std::cout << "\n\n\t-- Welcome to level 2: Fiction, Teen, Periodicals --\n"
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
                std::cout << "You climb the stairs to level 3" << std::endl;
                p->decEnergy(); //player loses 1 energy by climbing the stairs
                return up;
                break;
            case 2: //down
                std::cout << "You go down the stairs to level 1" << std::endl;
                return down;
                break;
            case 3: //left
                lookAround(p);
                break;
            default:
                std::cout << "direction error" << std::endl;
                break;
        }
    }
}

/*******************************************************************************
 ** lookAround: gives a description of what the player can see and gives
 ** options to investigate different areas
*******************************************************************************/
void Fiction::lookAround(Player* p){
    std::cout << "To the left you see the teen section. Straight ahead is a "
    "display filled \nwith classic literature. There are lots and lots of "
    "shelving for fiction \nbooks. Toward the back right you see a sign that "
    "says \'PERIODICALS\'. What would you like to do?" << std::endl;
    std::cout << "\t(1) look at the classics display" << '\n';
    std::cout << "\t(2) look at the teen section" << '\n';
    std::cout << "\t(3) look at the fiction section" << '\n';
    std::cout << "\t(4) find out what periodicals means" << '\n';
    std::cout << "\t(5) do nothing" << std::endl;
    int look = validateChoice(1, 5);
    
    switch(look){
        case 1:
            std::cout << "Looking at the display you find some "
            "interesting things: " << std::endl;
            classics.examine(p); //examine the classics display
            break;
        case 2:
            std::cout << "Browsing the teen section you find some "
            "interesting things: " << std::endl;
            teen.examine(p); //examine teen books
            break;
        case 3:
            std::cout << "Browsing the fiction section you find some "
            "interesting things: " << std::endl;
            fic.examine(p); //examine the classics display
            break;
        case 4:
            std::cout << "This treasure trove of information is the only "
            "resource of its kind \nbetween Denver and San Francisco. The "
            "oldest magaize is from 1820 and the \noldest newspaper is from "
            "1860. You gain an energy point." << std::endl;
            p->incEnergy();
            std::cout << "You have the energy to walk up " <<
            p->getEnergy() << " more flights of stairs." << std::endl;
            break;
        default:
            //do nothing
            break;
    }
}
