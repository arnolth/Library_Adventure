/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (childrens source file)
 *****************************************************************************/

#include "childrens.hpp"

/*******************************************************************************
 ** constructor
*******************************************************************************/
Childrens::Childrens() : Space() {
    this->level = -1;
    
    this->up = nullptr;
    this->down = nullptr;
    this->elevator = nullptr;
    this->exit = nullptr;
    
    //set up collections
    dvds.addItem("My Neighbor Totoro");
    dvds.addItem("Avatar: the Last Airbender");
    dvds.addItem("Bill Nye the Science Guy");
    dvds.addItem("Cool Runnings");
    
    nf.addItem("Drawing fairies and mermaids");
    nf.addItem("My encyclopedia of very important animals");
    nf.addItem("Minecraft: guide to enchantments & potions");
    nf.addItem("Guinness world records 2019");
    nf.addItem("Ruth Bader Ginsburg: R.B.G. vs inequality");
    
    books.addItem("Harry Potter");
    books.addItem("The Giver");
    books.addItem("The Crossover");
    books.addItem("Esperanza Rising");
    books.addItem("Percy Jackson");
    
    picture.addItem("The cat in the hat");
    picture.addItem("The Wolf the Duck and the Mouse");
    picture.addItem("Where the Wild Things are");
    picture.addItem("Hello Lighthouse");
}

/*******************************************************************************
 ** description: prints description of the level
*******************************************************************************/
void Childrens::description(){
    std::cout << "This is the Children’s library! The Children's Library is a "
    "light-filled,\nfive-story atrium which may be observed from all of the "
    "floors above. Cloth\n\'clouds\' or \'sails\' may be pulled across the "
    "space to provide shade when \nnecessary.It contains the kid versions of "
    "all the library has to offer from \nbiographies to books in other "
    "languages. This is the lowest level in the \nlibrary. There is no "
    "exit." << std::endl;
}

/******************************************************************************
 ** move: prints level description and map and lets player know what they can
 ** see. Then gets players choice of what they would like to do on that level
*******************************************************************************/
Space* Childrens::move(Player* p){
    int dir;
    
    //print level and player update
    std::cout << "\n\n\t-- Welcome to level -1: Children's Library --\n"
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
                std::cout << "You climb the stairs to level 1" << std::endl;
                p->decEnergy(); //player loses 1 energy by climbing the stairs
                return up;
                break;
            case 2: //down
                std::cout << "You are on the lowest level of the library, you "
                "can't go down." << std::endl;
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
void Childrens::lookAround(Player* p){
    std::cout << "You see the nonfiction collection and the DVDs. There is a "
    "door,\nit looks like there is a waterfall outside. There are also two "
    "doors in the back wall, they \nare labeled Grandmother's Attic and the "
    "Wild Woods. You also see signs for chapter \nbooks, picture books, fairy "
    "tales, and kids books in languages other than english. \nWhat would you "
    "like to do?" << std::endl;
    std::cout << "\t(1) look at the nonfiction books " << '\n';
    std::cout << "\t(2) look at the kids DVDs" << '\n';
    std::cout << "\t(3) explore the terrace" << '\n';
    std::cout << "\t(4) look at the chapter books " << '\n';
    std::cout << "\t(5) look at the picture books" << '\n';
    std::cout << "\t(6) explore Grandms's Attic" << '\n';
    std::cout << "\t(7) explore the Wild Woods" << '\n';
    std::cout << "\t(8) do nothing" << std::endl;
    int look = validateChoice(1, 8);
    
    switch(look){
        case 1:
            std::cout << "Browsing the nonfiction section you find some "
            "interesting things: " << std::endl;
            nf.examine(p); //examine the nonfiction section
            break;
        case 2:
            std::cout << "Browsing the DVD section you find some interesting "
            "things: " << std::endl;
            dvds.examine(p); //examine the DVD section
            break;
        case 3:
            std::cout << "You go outside but it is too cold and the waterfall "
            "is off. It is boring so you go back inside." << std::endl;
        case 4:
            std::cout << "Browsing the chapter books you find some interesting "
            "things: " << std::endl;
            books.examine(p);
            break;
        case 5:
            std::cout << "Browsing the picture books you find some interesting "
            "things: " << std::endl;
            picture.examine(p);
            break;
        case 6:
            std::cout << "Grandma's Attic is filled with wood beams, stuffed "
            "animals, and plenty of places to curl \nup with a book. You get "
            "think this is super cool and reminds you of a tree house. You "
            "gain \nan energy point." << std::endl;
            p->incEnergy();
            std::cout << "You have the energy to walk up " << p->getEnergy() <<
            " more flights of stairs." << std::endl;
            break;
        case 7:
            std::cout <<
            "The Wild Woods spark a sense of adventure and imagination. You "
            "love a good sense of \nadventure. You gain an energy point." <<
            std::endl;
            p->incEnergy();
            std::cout << "You have the energy to walk up " << p->getEnergy() <<
            " more flights of stairs." << std::endl;
            break;
        default:
            //do nothing
            break;
    }
}
