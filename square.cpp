/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (Library Square source file) the exit space
 *****************************************************************************/

#include "square.hpp"


LibSquare::LibSquare(){
    this->level = 99;
    
    this->up = nullptr;
    this->down = nullptr;
    this->elevator = nullptr;
    this->exit = nullptr;
}

void LibSquare::description() {}
Space* LibSquare::move(Player* p) {
    return exit;
}
void LibSquare::lookAround(Player* p){}

