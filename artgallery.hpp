/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (artGallery (L4) header file)
 *****************************************************************************/

#ifndef artgallery_hpp
#define artgallery_hpp

#include "space.hpp"
#include "collections.hpp"

class Art : public Space {
    
private:
    Collection art;
    Collection travel;
    Collection hist;
    Collection bio;
    
public:
    Art();
    
    virtual void description();
    virtual Space* move(Player*);
    virtual void lookAround(Player*);

};

#endif /* art_hpp */
