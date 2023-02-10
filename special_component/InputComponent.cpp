/*
** EPITECH PROJECT, 2023
** InputComponent.cpp
** File description:
** InputComponent
*/

#include "InputComponent.hpp"

nts::InputComponent::InputComponent() : AComponent(1)
{
    valueOuput[0] = Undefined;
    nextValue = Undefined;
}

nts::InputComponent::~InputComponent()
{
}

void nts::InputComponent::simulate(std::size_t tick)
{
    if (tick > 0)
        valueOuput[0] = nextValue;
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw nts::Error("Invalid pin on Input component.");
    return valueOuput[pin - 1];
};


void nts::InputComponent::changeValue(Tristate targetValue)
{
    nextValue = targetValue;
}
