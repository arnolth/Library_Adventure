/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (childrens (L -1) header file)
 *****************************************************************************/

#ifndef childrens_hpp
#define childrens_hpp

#include "space.hpp"
#include "collections.hpp"

class Childrens : public Space {
    
private:
    Collection dvds;
    Collection nf;
    Collection books;
    Collection picture;
    
public:
    Childrens();
    virtual void description();
    virtual Space* move(Player*);
    virtual void lookAround(Player*);
};

#endif /* childrens_hpp */
