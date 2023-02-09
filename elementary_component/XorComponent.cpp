/*
** EPITECH PROJECT, 2023
** XorComponent.cpp
** File description:
** XorComponent
*/

#include "XorComponent.hpp"

nts::Tristate nts::XorComponent::compute(std::size_t pin)
{
   if (pin > 3 || pin < 1)
        throw nts::Error("Invalid pin on Xor component.");
    if (pin == 1 || pin == 2) {
        if (!pins[pin].targetComp)
            throw nts::Error("Pin " + std::to_string(pin) + " on Xor component is not link.");
        return pins[pin].targetComp->compute(pins[pin].targetPin);
    }
    if (!pins[1].targetComp)
            throw nts::Error("Pin 1 on Xor component is not link.");
    if (!pins[2].targetComp)
            throw nts::Error("Pin 2 on Xor component is not link.");
    nts::Tristate firstValue = pins[1].targetComp->compute(pins[1].targetPin);
    nts::Tristate secondValue = pins[2].targetComp->compute(pins[2].targetPin);
    if ((firstValue == nts::True && secondValue == nts::True) || (firstValue == nts::False && secondValue == nts::False))
        return nts::False;
    if (firstValue == nts::Undefined || secondValue == nts::Undefined)
        return nts::Undefined;
    return nts::True;
}