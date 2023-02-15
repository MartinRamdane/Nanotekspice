/*
** EPITECH PROJECT, 2023
** Commands.hpp
** File description:
** Commands
*/

#ifndef COMMANDS
    #define COMMANDS

#include <iostream>
#include "Circuit.hpp"

class Commands {
    public:
        Commands(nts::Circuit &circuit);
        ~Commands();

        void mainLoop();
        void display();
        void simulate();
        void loop();
        int assignValue(const std::string input);

    private:
        nts::Circuit &_circuit;
        size_t tick;
};

#endif /* !COMMANDS */
