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
}

nts::InputComponent::~InputComponent()
{
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw nts::Error("Invalid pin on Input component.");
    return valueOuput[pin - 1];
};


void nts::InputComponent::changeValue(Tristate targetValue)
{
    valueOuput[0] = targetValue;
}
