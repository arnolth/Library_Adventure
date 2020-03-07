/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (collections class header file)
******************************************************************************/

#ifndef collections_hpp
#define collections_hpp

#include <vector>
#include "player.hpp"

class Collection {
private:
    std::vector<std::string> coll;
    
public:
    Collection();
    ~Collection();
    
    void examine(Player*);
    void addItem(std::string);
    void printColl();
};

#endif /* collections_hpp */
