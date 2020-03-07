/******************************************************************************
 ** Program Name: Final Project
 ** Author: Theodora Arnold
 ** Due Date: 03.19.2019
 ** Description: prints map with X marking current location
 *****************************************************************************/

#include "map.hpp"
#include <iostream>

/*******************************************************************************
 ** printMap: takes the current level (int) and prints the corresponding map
*******************************************************************************/
void printMap(int lvl){
    std::cout << "\n              -- MAP --" << std::endl;
    std::cout << "\n               LIBRARY" << std::endl;
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

