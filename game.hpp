/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (game header file)
 *****************************************************************************/

#ifndef game_hpp
#define game_hpp

#include "player.hpp"
#include "space.hpp"

class Game {
    
private:
    Player* patron;
    Space* currentLocation;
    Space* chi;
    Space* av;
    Space* fic;
    Space* NF;
    Space* art;
    Space* roof;
    Space* libSquare;
    
public:
    Game();
    ~Game();
    
    Player* getPlayer();
    Space* getLocation();
    void setLoction(Space*);
    Player* instructions();
    bool explore();
    bool checkWin();
    void printGoals();
};

#endif /* game_hpp */
