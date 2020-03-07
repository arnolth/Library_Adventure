/*******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (space source file) abstract class
*******************************************************************************/

#include "space.hpp"

//default constructor and destructor
Space::Space(){}
Space::~Space(){}

//getter
int Space::getLevel(){return this->level;}

//setters
void Space::setUp(Space* s) {
    this->up = s;
}
void Space::setDown(Space* s) {
    this->down = s;
}
void Space::setExit(Space* s) {
    this->exit = s;
}
