/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (Library Square header file) the exit space
 *****************************************************************************/

#ifndef square_hpp
#define square_hpp

#include "space.hpp"

class LibSquare : public Space {
    
private:
    
public:
    LibSquare();
    
    virtual void description();
    virtual Space* move(Player*);
    virtual void lookAround(Player*);
    
};

#endif /* art_hpp */
