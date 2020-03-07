/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (main)
 *****************************************************************************/

#include <iostream>
#include "game.hpp"

int main() {
    
    //create game
    Game game;
    
    Player* p = game.getPlayer();
    bool play = true;
    
    //play until user choses to exit the library or causes game over
    while(play) {
        play = game.explore();
        if(p->getEnergy() == 0){
            std::cout << "You are out of energy. You have collapsed in the "
            "library. Game over." << std::endl;
            play = false;
        }
    }
    
    //check win condidtions
    bool win = game.checkWin();
    if (win){
        if(p->getEnergy() == 0){
            //you do not win whether or not you have the correct
            //combination of items
        }
        else {
            std::cout << "\t**** CONGRATULATIONS " << p->getName() <<" **** \n"
            "You have completed all the goals in the adventure! YOU WIN!!!"
            << std::endl;
        }
    }
    else{
        std::cout << "You have left the library without completing all the "
        "goals. \nYou have lost the game." << std::endl;
    }

    
}
