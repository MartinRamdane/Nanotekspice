/*
** EPITECH PROJECT, 2023
** Clock.cpp
** File description:
** Clock
*/

#include "ClockComponent.hpp"

nts::ClockComponent::ClockComponent() : AComponent(1)
{
    valueOutput[0] = Undefined;
    nextValue = Undefined;
    haveToAssign = false;
}

nts::ClockComponent::~ClockComponent()
{
}

void nts::ClockComponent::changeValue(nts::Tristate value)
{
    nextValue = value;
    haveToAssign = true;
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    if (tick < 1)
        return;
    if (haveToAssign) {
        valueOutput[0] = nextValue;
        nextValue = Undefined;
        haveToAssign = false;
        return;
    }
    if (valueOutput[0] == nts::True) {
        valueOutput[0] = nts::False;
    } else {
        valueOutput[0] = nts::True;
    }
}