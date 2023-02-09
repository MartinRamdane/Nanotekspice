/*
** EPITECH PROJECT, 2023
** NotComponent.cpp
** File description:
** NotComponent
*/

#include "NotComponent.hpp"

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (pin < 1 || pin > 2)
        throw nts::Error("Invalid pin on Not component.");
    if (!pins[1].targetComp)
            throw nts::Error("Pin 1 on Nor component is not link.");
    if (pin == 1)
        return pins[1].targetComp->compute(pins[1].targetPin);
    nts::Tristate firstValue = pins[1].targetComp->compute(pins[1].targetPin);
    if (firstValue == nts::True)
        return nts::False;
    if (firstValue == nts::False)
        return nts::True;
    return nts::Undefined;
}

