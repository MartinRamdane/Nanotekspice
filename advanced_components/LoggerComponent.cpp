/*
** EPITECH PROJECT, 2023
** LoggerComponent.cpp
** File description:
** LoggerComponent
*/

#include "LoggerComponent.hpp"

nts::LoggerComponent::LoggerComponent() : AComponent(10)
{
}

nts::LoggerComponent::~LoggerComponent()
{
}

nts::Tristate nts::LoggerComponent::compute(std::size_t pin)
{
    if (pin < 1 || pin > 10)
        throw Error("Invalid pin on Logger component.");
    for (int i = 1; i <= 10; i++) {
        if (!pins[i].targetComp)
            throw Error("Pin " + std::to_string(i) + "on Logger component is not link.");
    }
    if (pins[9].targetComp->compute(1) == nts::True && pins[10].targetComp->compute(1) == nts::False) {
        char binary = 0;
        for (int i = 1; i <= 8; i++) {
            nts::Tristate state = pins[i].targetComp->compute(1);
            if (state == Undefined)
                return nts::Undefined;
            binary |= (state == True ? 1 : 0) << (i-1);
        }
        std::ofstream out;
        out.open("./log.bin", std::ios::app);
        if (!out.is_open())
            throw Error("Error to open './log.bin' file.");
        out << binary;
        out.close();
    }
    return nts::True;
}