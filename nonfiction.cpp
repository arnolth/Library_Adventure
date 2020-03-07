/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (nonfiction (L3) source file)
 *****************************************************************************/

#include "nonfiction.hpp"

/*******************************************************************************
 ** constructor
*******************************************************************************/
Nonfiction::Nonfiction() : Space() {
    this->level = 3;
    
    this->up = nullptr;
    this->down = nullptr;
    this->elevator = nullptr;
    this->exit = nullptr;
    
    //set up collections
    //science and tech books
    science.addItem("The immortal life of Henrietta Lacks");
    science.addItem("A Brief History of Time");
    science.addItem("Stiff: The Curious Lives of Human Cadavers");
    science.addItem("What If?: Serious Scientific Answers to Absurd "
                    "Hypothetical Questions");
    science.addItem("The mystery of the exploding teeth : and other curiosities"
                    " from the history of medicine");
    //cookbook display
    cook.addItem("The Complete Vegetarian Cookbook");
    cook.addItem("Plenty More: Vibrant Vegetable Cooking from London's "
                 "Ottolenghi");
    cook.addItem("Vegetarian Cooking for Everyone");
    cook.addItem("The Simply Vegetarian Cookbook");
    cook.addItem("Bowl: vegetarian recipes for ramen, pho, bibimbap, dumplings,"
                 " and other one-dish meals");
    //nonfiction collection
    nf.addItem("Learning Python with Raspberry Pi");
    nf.addItem("David and Goliath: underdogs, misfits, and the art of battling "
               "giants");
    nf.addItem("I'll be Gone in the Dark");
    nf.addItem("The stranger beside me");
    nf.addItem("Shady characters: the secret life of punctuation, symbols, & "
               "other typographical marks");
}

/*******************************************************************************
 ** description: prints description of the level
*******************************************************************************/
void Nonfiction::description(){
    std::cout << "As the population of Salt Lake City becomes more diverse, "
    "the need for \nmaterials in other languages has steadily increased. The "
    "foregin language \nsection on level 3 provides books, magazines, and "
    "newspapers in 25 \nlanguages. The rest of floor is filled with books in "
    "between 0-699 \naccording to the Dewey Decimal system." << std::endl;
}

/******************************************************************************
 ** move: prints level description and map and lets player know what they can
 ** see. Then gets players choice of what they would like to do on that level
*******************************************************************************/
Space* Nonfiction::move(Player* p){
    int dir;
   
    //print level and player update
    std::cout << "\n\n\t-- Welcome to level 3: Nonfiction, Foregin Language --\n"
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
                    std::cout << "You climb the stairs to level 4" << std::endl;
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
                std::cout << "You go down the stairs to level 2" << std::endl;
                return down;
                break;
            case 3:
                lookAround(p);
                break;
            default:
                break;
        }
    }
}

/*******************************************************************************
 ** lookAround: gives a description of what the player can see and gives
 ** options to investigate different areas
*******************************************************************************/
void Nonfiction::lookAround(Player* p){
    std::cout << "Off to the left you see a display with a bunch of cookbooks. "
    "You find \nscience and technology really interesting and know that those "
    "subjects are \nin the 500s and 600s in the Decimal system. To the right "
    "you see a sign \nfor books written in a language besides english. What "
    "would you like to do?" << std::endl;
    std::cout << "\t(1) look at the cookbook display" << '\n';
    std::cout << "\t(2) look at the science section " << '\n';
    std::cout << "\t(3) look at the other books on this level" << '\n';
    std::cout << "\t(4) look at the foregin language books" << '\n';
    std::cout << "\t(5) do nothing" << std::endl;
    int look = validateChoice(1, 5);
    
    switch(look){
        case 1:
            std::cout << "It turns out to be a vegetarian cookbook display. "
            "Some of the books you \nnotice are: " << std::endl;
            cook.examine(p);
            break;
        case 2:
            std::cout << "Browsing the 500s and 600s you find some interesting "
            "things: " << std::endl;
            science.examine(p);
            break;
        case 3:
            std::cout << "Browsing the other areas you find some interesting "
            "things:" << std::endl;
            nf.examine(p);
            break;
        case 4:
            std::cout << "You only speak English You don't know what to do "
            "with books in any \n other language butb you find out that you "
            "can access Mango Languages to \nlearn a new language for free "
            "with your library card. You gain an enery \npoint." << std::endl;
            p->incEnergy();
            std::cout << "You have the energy to walk up " <<
            p->getEnergy() << " more flights of stairs." << std::endl;
            break;
        default:
            //do nothing
            break;
    }
}

