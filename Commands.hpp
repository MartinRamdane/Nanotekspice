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
#include "special_component/InputComponent.hpp"
#include "special_component/OutputComponent.hpp"
#include "special_component/ClockComponent.hpp"

class Commands {
    public:
        Commands(nts::Circuit &circuit);
        ~Commands();

        void mainLoop();
        void display();
        void simulate();
        void loop();
        void assignValue(const std::string input);

    private:
        nts::Circuit &_circuit;
        size_t tick;
};

#endif /* !COMMANDS */
