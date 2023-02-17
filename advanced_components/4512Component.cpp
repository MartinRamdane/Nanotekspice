/*
** EPITECH PROJECT, 2023
** 4512Component.cpp
** File description:
** 4512 Component
*/

#include "4512Component.hpp"

nts::Selector::Selector() : AComponent(15)
{
}

void nts::Selector::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin < 1 || pin > 15 || pin == 8)
        throw Error("Invalid pin on 4512 component.");
    pins[pin].targetPin = otherPin;
    pins[pin].targetComp = &other;
}

nts::Tristate nts::Selector::checkTruthTable()
{
    Tristate Enable = pins[15].targetComp->compute(1);
    if (Enable == True)
        return Undefined;
    Tristate Inhibit = pins[10].targetComp->compute(1);
    if (Inhibit == True && Enable == False)
        return False;
    Tristate A = pins[11].targetComp->compute(1);
    Tristate B = pins[12].targetComp->compute(1);
    Tristate C = pins[13].targetComp->compute(1);
    if (Enable == False && Inhibit == False) {
        if (C == False && B == False && A == False)
            return (pins[1].targetComp->compute(1));
        if (C == False && B == False && A == True)
            return (pins[2].targetComp->compute(1));
        if (C == False && B == True && A == False)
            return (pins[3].targetComp->compute(1));
        if (C == False && B == True && A == True)
            return (pins[4].targetComp->compute(1));
        if (C == True && B == False && A == False)
            return (pins[5].targetComp->compute(1));
        if (C == True && B == False && A == True)
            return (pins[6].targetComp->compute(1));
        if (C == True && B == True && A == False)
            return (pins[7].targetComp->compute(1));
        if (C == True && B == True && A == True)
            return (pins[9].targetComp->compute(1));
    }
   return Undefined;
}

nts::Tristate nts::Selector::compute(std::size_t pin)
{
    if (pin < 1 || pin > 15 || pin == 8)
        throw Error("Invalid pin on 4512 component.");
    if (pin == 14)
        return checkTruthTable();
    return (pins[pin].targetComp->compute(pins[pins[pin].targetPin].targetPin));
};
