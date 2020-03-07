/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (nonfiction (L3) header file)
 *****************************************************************************/

#ifndef nonfiction_hpp
#define nonfiction_hpp

#include "space.hpp"
#include "collections.hpp"

class Nonfiction : public Space {
    
private:
    Collection science;
    Collection cook;
    Collection nf;
    
public:
    Nonfiction();
    
    virtual void description();
    virtual Space* move(Player*);
    virtual void lookAround(Player*);
};

#endif /* nonfiction_hpp */
