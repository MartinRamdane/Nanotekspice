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
            assignValue(input);
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
    for (auto it = _circuit.chipsets.begin(); it != _circuit.chipsets.end(); it++) {
        nts::InputComponent *castInput = dynamic_cast<nts::InputComponent *>(_circuit.chipsets[it->first].comp.get());
        nts::ClockComponent *castClock = dynamic_cast<nts::ClockComponent *>(_circuit.chipsets[it->first].comp.get());
        if (castInput || castClock)
            std::cout << "  " << (it->first) << ": " << _circuit.compute(_circuit.chipsets[it->first].pin) << std::endl;

    }
    std::cout << "output(s):" << std::endl;
    for (auto it = _circuit.chipsets.begin(); it != _circuit.chipsets.end(); it++) {
        nts::OutpoutComponent *castOutput = dynamic_cast<nts::OutpoutComponent *>(_circuit.chipsets[it->first].comp.get());
        if (castOutput)
            std::cout << "  " << (it->first) << ": " << _circuit.compute(_circuit.chipsets[it->first].pin) << std::endl;
    }
}

void Commands::assignValue(const std::string input)
{
    bool inputIsFind = false;
    std::string target = input.substr(0, input.find("="));
    for (auto it = _circuit.chipsets.begin() ; it != _circuit.chipsets.end() ; ++it) {
        nts::InputComponent *castInput = dynamic_cast<nts::InputComponent *>(_circuit.chipsets[it->first].comp.get());
        nts::ClockComponent *castclock = dynamic_cast<nts::ClockComponent *>(_circuit.chipsets[it->first].comp.get());
        if ((castInput || castclock) && it->first == target)
            inputIsFind = true;
    }
    if (!inputIsFind)
        return;
    inputIsFind = false;
    std::string val = input.substr(target.size() + 1);
    val.erase(std::remove_if(val.begin(), val.end(), ::isspace), val.end());
    if (val != "0" && val != "1" && val != "U") {
        return;
    }
    nts::Tristate value = val == "U" ? nts::Undefined : (stoi(val) == 0 ? nts::False : nts::True);
    nts::InputComponent *inputCast = dynamic_cast<nts::InputComponent *>(_circuit.chipsets[target].comp.get());
    nts::ClockComponent *clockCast = dynamic_cast<nts::ClockComponent *>(_circuit.chipsets[target].comp.get());
    if (inputCast)
        inputCast->changeValue(value);
    else if (clockCast)
        clockCast->changeValue(value);
    return;
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