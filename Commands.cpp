/*
** EPITECH PROJECT, 2023
** Commands.cpp
** File description:
** Commands
*/

#include "Commands.hpp"

Commands::Commands(nts::Circuit &circuit) : _circuit(circuit)
{
    tick = 0;
}

Commands::~Commands()
{
}

void Commands::mainLoop()
{
    std::string input;
    std::cout << "> ";
    while (std::getline (std::cin, input)) {
        if (input == "display")
            display();
        else if (input == "loop")
            loop();
        else if (input == "simulate")
            simulate();
        else if (input.find("=") != std::string::npos)
            _circuit.assignValue(input);
        else if (input == "exit")
            break;
        std::cout << "> ";
    }
}

void Commands::simulate()
{
    tick += 1;
    _circuit.simulate(tick);
}

void Commands::display()
{
    std::cout << "tick: " << tick << std::endl;
    std::cout << "input(s):" << std::endl;
    _circuit.displayInputsComponent();
    std::cout << "output(s):" << std::endl;
    _circuit.displayOutputsComponent();
}

volatile sig_atomic_t stopLoop;

void checkIfSig(int signum) {
    if (signum == SIGINT)
        stopLoop = 1;
}

void Commands::loop()
{
    while (stopLoop != 1) {
        signal(SIGINT, checkIfSig);
        simulate();
        display();
    }
}