/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (game source file)
******************************************************************************/

#include "game.hpp"
#include "childrens.hpp"
#include "ground.hpp"
#include "fiction.hpp"
#include "nonfiction.hpp"
#include "artgallery.hpp"
#include "roof.hpp"
#include "square.hpp"
#include <algorithm>

//constructor
Game::Game(){
    this->chi = new Childrens();
    this->av = new Ground();
    this->fic = new Fiction();
    this->NF = new Nonfiction();
    this->art = new Art();
    this->roof = new Roof();
    this->libSquare = new LibSquare();
    
    currentLocation = av;
    
    //set directions
    chi->setUp(av);
    
    av->setDown(chi);
    av->setUp(fic);
    av->setExit(libSquare);
    
    fic->setDown(av);
    fic->setUp(NF);
    
    NF->setDown(fic);
    NF->setUp(art);
    
    art->setDown(NF);
    art->setUp(roof);
    
    roof->setDown(art);
    roof->setExit(libSquare);
    
    libSquare->setExit(libSquare);
    
    //set player
    this->patron = instructions();
}

//destructor
Game::~Game(){
    delete chi;
    delete av;
    delete fic;
    delete NF;
    delete art;
    delete roof;
    delete libSquare;
    delete patron;
}

//getters
Space* Game::getLocation(){return this->currentLocation;}
Player* Game::getPlayer() {return this->patron;}

//setters
void Game::setLoction(Space* s){
    this->currentLocation = s;
}

/*******************************************************************************
 ** explore: moves the player through the game. Returns true to continue game
 ** unless player is in the library square then it returns false. 
*******************************************************************************/
bool Game::explore(){
    printGoals();
    this->currentLocation = currentLocation->move(patron);
    if (currentLocation->getLevel() == 99){
        return false;
    } else {return true;}
}

/*******************************************************************************
 ** instructions: prints the instructions for the game and creates the player
 ** returns the new player
*******************************************************************************/
Player* Game::instructions(){
    std::cout << std::string(80, '=') << std::endl << std::endl;
    std::cout << std::string(30, ' ') << " Library Adventure!\n" << std::endl;
    std::cout << std::string(80, '=') << std::endl;
    
    //get user name and create player
    std::cout << "What is your name?  ";
    std::string name;
    getline(std::cin, name);
    Player* player = new Player(name);
    
    //Welcome
    std::cout << "\nHello " << player->getName() << "! Welcome to the Salt "
    "Lake City Public Library! \nYou are on a quest to explore the library. "
    "Here are some rules to keep in mind.\n" <<std::endl;
    
    //energy instructions
    std::cout << "\t- 1 - Energy Level:\n"
    "The elevator at the library is a glass elevator and that completely\n"
    "freaks you out. Because you will not take the elevator you have to keep\n"
    "careful track of your energy level. You start with enough energy to walk\n"
    "up 3 flights of stairs. The main way to lose energy is to climb a flight\n"
    "of stairs. You gain energy by discovering interesting things in the\n"
    "library. Be careful, there are various things around the library that\n"
    "can cost you energy as well. If you ever reach zero energy, you collapse\n"
    "in the library and automatically lose. \n" << std::endl;
    
    //checkout
    std::cout << "\t- 2 - Check Out:\n"
    "In order to check out materials all you have to do is add them to your \n"
    "tote bag. You need to have a certain combination of items in your tote \n"
    "bag when you exit the library in order to win the game. (See Goals for \n"
    "the items needed)\n" << std::endl;
    //goals
    std::cout << "\t- 3 - Complete Goals:\n"
    "In order to win the game, you must exit the library with a full tote\n"
    "bag, 5 items, 3 of which must match items 1-3 below.\n";

    return player;
}

/*******************************************************************************
 ** checkWin: determines if player has completed all four goals, returns true if
 ** complete and false if incomplete
 ** resource: https://stackoverflow.com/questions/6277646/in-c-check-if-stdvectorstring-contains-a-certain-value
*******************************************************************************/
bool Game::checkWin(){
    int winCount = 0;
    std::vector<std::string> t = patron->getTote();
    
    //check goal 1 -- 'the boy who lived'
    if (std::find(t.begin(), t.end(), "Harry Potter") != t.end()){
        winCount++;
    }
    //check goal 2 met -- biography
    if (std::find(t.begin(), t.end(),
                  "Ruth Bader Ginsburg: R.B.G. vs inequality") != t.end() ||
        std::find(t.begin(), t.end(),
                  "I Know Why the Caged Bird Sings") != t.end() ||
        std::find(t.begin(), t.end(),
                  "The glass castle: a memoir") != t.end() ||
        std::find(t.begin(), t.end(),
                  "Educated: a memoir") != t.end()){
            winCount++;
    }
    //check goal 3 -- teen book to movie
    if (std::find(t.begin(), t.end(),
                  "The Hate U Give") != t.end() ||
        std::find(t.begin(), t.end(),
                  "The Sacred Lies of Minnow Bly") != t.end() ||
        std::find(t.begin(), t.end(),
                  "The Maze Runner") != t.end())
    {
            winCount++;
    }
    //check goal 4 -- 5 items in tote bag
    if (t.size() == 5){
        winCount++;
    }
    
    //check for game win
    if (winCount == 4){
        //all 4 win conditions are met
        return true;
    }
    else {
        return false;
    }
}

/*******************************************************************************
 ** printGoals: prints goals
*******************************************************************************/
void Game::printGoals(){
    std::cout << "Goals: \n"
    "  [1] a book about \'the boy who lived\'\n" //harry potter in childrens
    "  [2] a biography about a woman \n" //level 4 or childrens
    "  [3] a teen book made into a movie \n" //Level 2
    "  [4] have a full tote bag" << std::endl;
}
