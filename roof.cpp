/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (roof (L5) source file)
******************************************************************************/

#include "roof.hpp"

Roof::Roof() : Space() {
    this->level = 5;
    
    this->up = nullptr;
    this->down = nullptr;
    this->elevator = nullptr;
    this->exit = nullptr;
}

/******************************************************************************
 ** description: prints description of the level
******************************************************************************/
void Roof::description(){
    std::cout << "The Rooftop Terrace, accessible from outside by walking the "
    "five-story \ncurving Crescent Wall or inside the library on the 5th floor,"
    " features \nstunning 360-degree views of the Salt Lake Valley and Wasatch "
    "Mountains.\nThe Main Library's Rooftop Terrace is home to multiple "
    "beehives that are \nkept by the Salt Lake City Beekeeper." << std::endl;
}

/******************************************************************************
 ** move: prints level description and map and lets player know what they can
 ** see. Then gets players choice of what they would like to do on that level
******************************************************************************/
Space* Roof::move(Player* p){
    int dir;
    
    //print level and player update
    std::cout << "\n\n\t---- Welcome to level 5: Rooftop Terrace ----\n"
    "You have the energy to walk up " << p->getEnergy() <<
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
                std::cout << "You are on the roof you can't go up." << std::endl;
                break;
            case 2: //down
                std::cout << "You go down the stairs to level 4." << std::endl;
                return down;
                break;
            case 3: //left
                lookAround(p);
                break;
            case 4: //right
                return exit;
                break;
            case 5:
                
                break;
        }
    }
}

/*******************************************************************************
 ** lookAround: gives a description of what the player can see and gives
 ** options to investigate different areas
*******************************************************************************/
void Roof::lookAround(Player* p){
    std::cout << "You can see the behives and path that leads through the "
    "garden. What \nwould you like to do?" << std::endl;
    std::cout << "\t(1) look at the beehives" << '\n';
    std::cout << "\t(2) expore the garden" << '\n';
    std::cout << "\t(3) do nothing" << std::endl;
    int look = validateChoice(1, 3);
    
    switch(look){
        case 1:
            std::cout << "The hives produce anywhere from 75 to 250 pounds of "
            "honey each year. You \nlearn an interesting bee fact: Honey bees "
            "are great flyers. They fly at a \nspeed of around 25km\n per hour "
            "and beat their wings 200 times per second! \nYou gain an energy "
            "point." << std::endl;
            p->incEnergy();
            std::cout << "You have the energy to walk up " << p->getEnergy() <<
            " more flights of stairs." << std::endl;
            break;
        case 2:
            std::cout << "The garden is beeautiful! There are new flowers that "
            "are just atarting to \nbloom. But, you stay outside for too long "
            "and get sunburnt. You lose an \nenergy point." << std::endl;
            p->decEnergy();
            std::cout << "You have the energy to walk up " << p->getEnergy() <<
            " more flights of stairs." << std::endl;
            break;
        case 3:
        default:
            //do nothing
            break;
    }
}
