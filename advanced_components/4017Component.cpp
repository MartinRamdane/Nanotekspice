    /*
** EPITECH PROJECT, 2023
** 4017.cpp
** File description:
** 4017
*/

#include "4017Component.hpp"

nts::JonhsonCounter::JonhsonCounter() : AComponent(16)
{
    counter = -1;
    prevTick = 0;
    _oldInput1State = Undefined;
    _oldInput2State = Undefined;
    for (std::size_t i=1; i < 12; i++) {
        if (i != 8)
            savedState[i] = nts::Undefined;
    }
}

void nts::JonhsonCounter::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin < 1 || pin > 15 || pin == 8)
        throw Error("Invalid pin on 4017 component.");
    pins[pin].targetPin = otherPin;
    pins[pin].targetComp = &other;
}

nts::Tristate nts::JonhsonCounter::getPinValue(std::size_t targetPin)
{
        nts::Tristate result = nts::False;
        if (counter == 0 && targetPin == 3) {
            result = nts::True;
        }
        if (counter == 1 && targetPin == 2) {
            result = nts::True;
        }
        if (counter == 2 && targetPin == 4) {
            result = nts::True;
        }
        if (counter == 3 && targetPin == 7) {
            result = nts::True;
        }
        if (counter == 4 && targetPin == 10) {
            result = nts::True;
        }
        if (counter == 5 && targetPin == 1) {
            result = nts::True;
        }
        if (counter == 6 && targetPin == 5) {
            result = nts::True;
        }
        if (counter == 7 && targetPin == 6) {
            result = nts::True;
        }
        if (counter == 8 && targetPin == 9) {
            result = nts::True;
        }
        if (counter == 9 && targetPin == 11) {
            result = nts::True;
        }
        savedState[targetPin] = result;
        return result;
}

void nts::JonhsonCounter::simulate(std::size_t tick)
{
    nts::Tristate Cl = pins[14].targetComp->compute(pins[pins[14].targetPin].targetPin);
    nts::Tristate i1 = pins[13].targetComp->compute(pins[pins[13].targetPin].targetPin);
    if (tick != prevTick && (((Cl == True && _oldInput1State == False) && i1 == False) || ((i1 == False && _oldInput1State == True) && Cl == True))) {
        counter++;
    }
    if (counter == 10)
        counter = 0;
    _oldInput1State = Cl;
    std::cout << "old i1: " << _oldInput2State << std::endl;
    _oldInput2State = i1;
    std::cout << "old i1: " << _oldInput2State << std::endl;
    std::cout << "counter: " << counter << std::endl;
    prevTick = tick;
}

nts::Tristate nts::JonhsonCounter::compute(std::size_t pin)
{
    if (pin < 1 || pin > 15 || pin == 8)
        throw Error("Invalid pin on 4017 component.");
    nts::Tristate Cl = pins[14].targetComp->compute(pins[pins[14].targetPin].targetPin);
    nts::Tristate i1 = pins[13].targetComp->compute(pins[pins[13].targetPin].targetPin);
    nts::Tristate R = pins[15].targetComp->compute(pins[pins[15].targetPin].targetPin);
    nts::Tristate result;
    if (i1 == True)
        return (savedState[pin]);
    if (R == True || counter == 10)
        counter = 0;
    if (pin != 13 && pin != 14 && pin != 15 &&  pin != 12) {
        if (Cl == nts::True) {
            result = getPinValue(pin);
        } else {
            result = (savedState[pin]);
        }
        return result;
    }
    if (pin == 12) {
        if (counter < 5)
            return nts::True;
        else
            return nts::False;
    }
    return (pins[pin].targetComp->compute(pins[pins[pin].targetPin].targetPin));
};