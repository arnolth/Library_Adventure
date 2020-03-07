/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (fiction (L2) header file)
 *****************************************************************************/

#ifndef fiction_hpp
#define fiction_hpp

#include "space.hpp"
#include "collections.hpp"

class Fiction : public Space {
    
private:
    Collection teen;
    Collection classics;
    Collection fic;
    
public:
    Fiction();
    
    virtual void description();
    virtual Space* move(Player*);
    virtual void lookAround(Player*);
};

#endif /* fiction_hpp */
