/*
** EPITECH PROJECT, 2023
** OrComponent.cpp
** File description:
** OrComponent
*/

#include "OrComponent.hpp"

nts::Tristate nts::OrComponent::compute(std::size_t pin)
{
    if (pin == 1 || pin == 2)
        return pins[pin].targetComp->compute(pins[pin].targetPin);
    nts::Tristate firstValue = pins[1].targetComp->compute(pins[1].targetPin);
    nts::Tristate secondValue = pins[2].targetComp->compute(pins[2].targetPin);
    if (firstValue == nts::True || secondValue == nts::True)
        return nts::True;
    if (firstValue == nts::False && secondValue == nts::False)
        return nts::False;
    return nts::Undefined;
}