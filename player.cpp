/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (player source file)
*******************************************************************************/

#include "player.hpp"
#include "helper.hpp"
#include <iostream>

//constuctor
Player::Player(){}
Player::Player(std::string n){
    this->name = n;
    this->energy = 3;
}
//destructor
Player::~Player(){}

//getters
int Player::getEnergy(){return this->energy;}
std::string Player::getName(){return this->name;}
std::vector<std::string> Player::getTote() {return this->tote;}

/*******************************************************************************
 ** inc and dec Energy:increase and decrease player energy
*******************************************************************************/
void Player::incEnergy(){
    this->energy++;
}
void Player::decEnergy(){
    this->energy--;
}

/*******************************************************************************
 ** printTote:print the contents of the players tote bag
*******************************************************************************/
void Player::printTote(){
    if(tote.size() == 0){
        std::cout << "\tYour tote bag is empty. Pick out some materials." <<
        std::endl;
    }
    else {
        for(int i = 0; i < tote.size(); i++){
            std::cout << "\t(" << i + 1 << ") " << tote.at(i) << std::endl;
        }
        if (tote.size() == 5){
            std::cout << "Your tote bag is full." << std::endl;
        }
    }
    std::cout << std::endl;
}

/*******************************************************************************
 ** removeToteItem: adds item to the contents of the players tote bag
 ** MAX tote size is 5 items
*******************************************************************************/
void Player::addToteItem(std::string s){
    if (tote.size() < 5){
        tote.push_back(s);
    }
    else {
        std::cout << "Your tote bag is full. Would you like to check and an "
        "item back in?" << std::endl;
        std::cout << "  (1) yes" << std::endl;
        std::cout << "  (2) no" << std::endl;
        int remove = validateChoice(1, 2);
        if (remove == 1){
            //remove old item and add new item
            removeToteItem();
            if (tote.size() < 5){ //make sure item was removed
                tote.insert(tote.begin(), s);
            }
        }
        else{
            //do nothing
        }
    }
}

/*******************************************************************************
 ** removeToteItem: deletes an item from the tote bag
 ** resource:http://www.cplusplus.com/reference/vector/vector/erase/
*******************************************************************************/
void Player::removeToteItem(){
    std::cout << "Which item would you like to return?" << std::endl;
    printTote();
    int index = validateChoice(1, tote.size()+1);
    index--;
    std::cout << "Are you sure you would like to delete " << tote.at(index) <<
    ". If you chose to \nreturn the item it will be placed on a shelving cart "
    "and you will not be\n able to check it out again." << std::endl;
    std::cout << "  (1) yes, return the item\n  (2) no, do NOT return the "
    "item" << std::endl;
    int ret = validateChoice(1, 2);
    if (ret == 1){
        std::cout << "Item: " << tote.at(index) << " was returned." <<
        std::endl;
        tote.erase(tote.begin() + index);
    }
    else {
        std::cout << tote.at(index) << " was not returned." << std::endl;
    }
}

