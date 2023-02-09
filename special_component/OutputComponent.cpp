/*
** EPITECH PROJECT, 2023
** OutputComponent.cpp
** File description:
** OutputComponent
*/

#include "OutputComponent.hpp"

nts::OutpoutComponent::OutpoutComponent() : AComponent(1)
{
}

nts::OutpoutComponent::~OutpoutComponent()
{
}

nts::Tristate nts::OutpoutComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw nts::Error("Invalid pin on Output component.");
    if (!pins[pin].targetComp)
        throw nts::Error("Output not link.");
    return pins[pin].targetComp->compute(pins[pin].targetPin);
}