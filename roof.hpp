/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (roof (L5) header file)
******************************************************************************/

#ifndef roof_hpp
#define roof_hpp

#include "space.hpp"

class Roof : public Space {
    
private:
    
public:
    Roof();
    
    virtual void description();
    virtual Space* move(Player*);
    virtual void lookAround(Player*);
};

#endif /* roof_hpp */
