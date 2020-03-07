/*******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (player header file) 
*******************************************************************************/

#ifndef player_hpp
#define player_hpp

#include <string>
#include <vector>

class Player {
    
private:
    std::string name;
    int energy;
    std::vector<std::string> tote;
    
public:
    Player();
    Player(std::string);
    ~Player();
    
    int getEnergy();
    std::string getName();
    std::vector<std::string> getTote();
    
    void incEnergy();
    void decEnergy();
    void printTote();
    void addToteItem(std::string);
    void removeToteItem();
};

#endif /* player_hpp */
