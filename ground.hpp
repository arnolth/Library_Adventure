/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (ground floor (L1) header file)
 *****************************************************************************/

#ifndef ground_hpp
#define ground_hpp

#include "space.hpp"
#include "collections.hpp"

class Ground : public Space {
    
private:
    Collection dvds;
    Collection cds;
    Collection lab;
    
public:
    Ground();
    
    virtual void description();
    virtual Space* move(Player*);
    virtual void lookAround(Player*);
};

#endif /* ground_hpp */
