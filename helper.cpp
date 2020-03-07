/*******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: (helper source file) valitate entry in range and display menus
*******************************************************************************/

#include "helper.hpp"

#include <iostream>
#include <sstream>

/*******************************************************************************
 ** validateChoice: validate an integer choice between a starting value and
 ** an ending value
 ** parameters: int s = smallest accepted value (starting value)
 **             int e = largest accepted value (ending value)
*******************************************************************************/
int validateChoice(int s, int e){
    int choice;
    std::string entry;
    
    while (true) {
        std::getline(std::cin, entry);
        std::stringstream ss(entry);//covert input to stream for int conversion
        if(ss >> choice && !(ss >> entry)) {
            if (choice < s || choice > e) {
                //do nothing, int was entered but not within bounds
            }
            else {
                std::cout << std::endl;
                return choice;
            }
        }
        std::cin.clear();
        std::cout << "Invalid input. Please try again." << std::endl;
    }
}

/*******************************************************************************
 ** directionMenu: lists options of what the player can do on that floor
*******************************************************************************/
int directionMenu(){
    std::cout << "\nWhat will you do?\n"
    "  (1) go up a floor\n"
    "  (2) go down a floor\n"
    "  (3) look around\n";
    return validateChoice(1, 4);
}

/*******************************************************************************
 ** directionMenuExit: lists options of what the player can do on that floor
 ** including exit the building(ending the game)
*******************************************************************************/
int directionMenuExit(){
    std::cout << "\nWhat will you do?\n"
    "  (1) go up a floor\n"
    "  (2) go down a floor\n"
    "  (3) look around\n"
    "  (4) exit\n";
    return validateChoice(1, 4);
}



/*******************************************************************************
 ** printMap: takes the current level (int) and prints the corresponding map
*******************************************************************************/
void printMap(int lvl){
    std::cout << "\n         SLC PUBLIC LIBRARY -- MAP" << std::endl;
    switch (lvl)
    {
        case -1:
            std::cout <<
            "|-----------------------------------------|\n"
            "|     Rooftop Terrace                     |\n"
            "|-----------------------------------------|\n"
            "|     Nonfiction(700-999), Art Gallery    |\n"
            "|-----------------------------------------|\n"
            "|     Nonfiction(0-699), Foregin Language |\n"
            "|-----------------------------------------|\n"
            "|     Fiction, Teen, Periodicals          |\n"
            "|-----------------------------------------|\n"
            "|     Cafe, Audiovisual, Creative Lab     |\n"
            "|-----------------------------------------|\n"
            "|  X  Children's Library                  |\n"
            "|-----------------------------------------|\n";
            break;
        case 1:
            std::cout <<
            "|-----------------------------------------|\n"
            "|     Rooftop Terrace                     |\n"
            "|-----------------------------------------|\n"
            "|     Nonfiction(700-999), Art Gallery    |\n"
            "|-----------------------------------------|\n"
            "|     Nonfiction(0-699), Foregin Language |\n"
            "|-----------------------------------------|\n"
            "|     Fiction, Teen, Periodicals          |\n"
            "|-----------------------------------------|\n"
            "|  X  Cafe, Audiovisual, Creative Lab     |\n"
            "|-----------------------------------------|\n"
            "|     Children's Library                  |\n"
            "|-----------------------------------------|\n";
            break;
        case 2:
            std::cout <<
            "|-----------------------------------------|\n"
            "|     Rooftop Terrace                     |\n"
            "|-----------------------------------------|\n"
            "|     Nonfiction(700-999), Art Gallery    |\n"
            "|-----------------------------------------|\n"
            "|     Nonfiction(0-699), Foregin Language |\n"
            "|-----------------------------------------|\n"
            "|  X  Fiction, Teen, Periodicals          |\n"
            "|-----------------------------------------|\n"
            "|     Cafe, Audiovisual, Creative Lab     |\n"
            "|-----------------------------------------|\n"
            "|     Children's Library                  |\n"
            "|-----------------------------------------|\n";
            break;
        case 3:
            std::cout <<
            "|-----------------------------------------|\n"
            "|     Rooftop Terrace                     |\n"
            "|-----------------------------------------|\n"
            "|     Nonfiction(700-999), Art Gallery    |\n"
            "|-----------------------------------------|\n"
            "|  X  Nonfiction(0-699), Foregin Language |\n"
            "|-----------------------------------------|\n"
            "|     Fiction, Teen, Periodicals          |\n"
            "|-----------------------------------------|\n"
            "|     Cafe, Audiovisual, Creative Lab     |\n"
            "|-----------------------------------------|\n"
            "|     Children's Library                  |\n"
            "|-----------------------------------------|\n";
            break;
        case 4:
            std::cout <<
            "|-----------------------------------------|\n"
            "|     Rooftop Terrace                     |\n"
            "|-----------------------------------------|\n"
            "|  X  Nonfiction(700-999), Art Gallery    |\n"
            "|-----------------------------------------|\n"
            "|     Nonfiction(0-699), Foregin Language |\n"
            "|-----------------------------------------|\n"
            "|     Fiction, Teen, Periodicals          |\n"
            "|-----------------------------------------|\n"
            "|     Cafe, Audiovisual, Creative Lab     |\n"
            "|-----------------------------------------|\n"
            "|     Children's Library                  |\n"
            "|-----------------------------------------|\n";
            break;
        case 5:
            std::cout <<
            "|-----------------------------------------|\n"
            "|  X  Rooftop Terrace                     |\n"
            "|-----------------------------------------|\n"
            "|     Nonfiction(700-999), Art Gallery    |\n"
            "|-----------------------------------------|\n"
            "|     Nonfiction(0-699), Foregin Language |\n"
            "|-----------------------------------------|\n"
            "|     Fiction, Teen, Periodicals          |\n"
            "|-----------------------------------------|\n"
            "|     Cafe, Audiovisual, Creative Lab     |\n"
            "|-----------------------------------------|\n"
            "|     Children's Library                  |\n"
            "|-----------------------------------------|\n";
            break;
    }
    
    std::cout << "   X marks your current location." << std::endl;
}


