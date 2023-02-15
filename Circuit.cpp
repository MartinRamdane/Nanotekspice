/*
** EPITECH PROJECT, 2023
** Circuit.cpp
** File description:
** Circuit.hpp
*/

#include "Circuit.hpp"

using namespace nts;

Circuit::Circuit(size_t nbPins) : AComponent(nbPins)
{
}

Circuit::~Circuit()
{
}

nts::Tristate Circuit::compute(std::size_t pin)
{
    return (pins[pin].targetComp->compute(1));
}

void Circuit::addComponent(std::string key, std::unique_ptr<nts::IComponent> component, std::size_t pin)
{
    for (auto it = chipsets.begin() ; it != chipsets.end(); ++it) {
        if (it->first == key)
            throw Error("Same component name.");
    }
    chipsets[key].comp.swap(component);
    chipsets[key].pin = pin;
}

void Circuit::simulate(std::size_t tick)
{
    for (auto it = chipsets.begin() ; it != chipsets.end(); ++it)
        (it->second).comp->simulate(tick);
}