/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (space header file) abstract class 
 *****************************************************************************/

#ifndef space_hpp
#define space_hpp

#include <string>
#include <iostream>
#include "helper.hpp"
#include "map.hpp"

class Space {
protected:
    int level;
    Space* up;
    Space* down;
    Space* elevator;
    Space* exit;
    
public:
    Space();
    virtual ~Space();
    
    virtual void description() = 0;
    virtual Space* move(Player*) = 0;
    virtual int getLevel();
    virtual void setUp(Space*);
    virtual void setDown(Space*);
    virtual void setExit(Space*);
    virtual void lookAround(Player*) = 0;
    
};


#endif /* space_hpp */
