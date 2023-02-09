/*
** EPITECH PROJECT, 2023
** Clock.cpp
** File description:
** Clock
*/

#include "ClockComponent.hpp"


void nts::ClockComponent::changeValue(nts::Tristate value) {
    valueOutput[0] = value;
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    if (tick < 1)
        return;
    if (valueOutput[0] == nts::True) {
        valueOutput[0] = nts::False;
    } else {
        valueOutput[0] = nts::True;
    }
}