/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description:
 *****************************************************************************/

#include "collections.hpp"
#include "helper.hpp"
#include <iostream>

//consrtuctor and desrtuctor
Collection::Collection() {};
Collection::~Collection() {}

/*******************************************************************************
 ** examine: prints the collection and allows the user to pick up an item.
*******************************************************************************/
void Collection::examine(Player* p){
    if(coll.size() != 0){
        for(int i = 0; i < coll.size(); i++){
            std::cout << "\t(" << i + 1 << ") " << coll.at(i) << std::endl;
        }
        std::cout << "Enter the number of the item you would like to pick up. "
        "If don't want any of \nthe items, enter 0." << std::endl;
        int pickUp = validateChoice(0, coll.size() + 1);
        if (pickUp != 0){
            pickUp--;
            p->addToteItem(coll.at(pickUp));
            coll.erase(coll.begin() + pickUp);
            std::cout << "Your tote bag now contains: " << std::endl;
            p->printTote();
        }
        else{
            //player doesn't want to pick anything up
        }
    }
    else {
       std::cout << "You already picked up all the materials in this area."
        << std::endl;
    }
}

/*******************************************************************************
 ** addItem: adds item to the end of the collection
*******************************************************************************/
void Collection::addItem(std::string s){
    coll.push_back(s);
}

/*******************************************************************************
 ** printColl: prints the collection
*******************************************************************************/
void Collection::printColl(){
    for(int i = 0; i < coll.size(); i++){
        std::cout << "\t(" << i + 1 << ") " << coll.at(i) << std::endl;
    }
}
