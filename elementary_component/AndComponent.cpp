/*
** EPITECH PROJECT, 2023
** AndComponent.cpp
** File description:
** AndComponent
*/

#include "AndComponent.hpp"

nts::Tristate nts::AndComponent::compute(std::size_t pin)
{
    if (pin > 3 || pin < 1)
        throw nts::Error("Invalid pin on And component.");
    if (pin == 1 || pin == 2) {
        if (!pins[pin].targetComp)
            throw nts::Error("Pin " + std::to_string(pin) + " on And component is not link.");
        return pins[pin].targetComp->compute(pins[pin].targetPin);
    }
    if (!pins[1].targetComp)
            throw nts::Error("Pin 1 on And component is not link.");
    if (!pins[2].targetComp)
            throw nts::Error("Pin 2 on And component is not link.");
    nts::Tristate firstValue = pins[1].targetComp->compute(pins[1].targetPin);
    nts::Tristate secondValue = pins[2].targetComp->compute(pins[2].targetPin);
    if (firstValue == nts::False || secondValue == nts::False)
        return nts::False;
    if (firstValue == nts::True && secondValue == nts::True)
        return nts::True;
    return nts::Undefined;
}