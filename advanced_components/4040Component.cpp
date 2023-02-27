    /*
** EPITECH PROJECT, 2023
** 4040.cpp
** File description:
** 4040°
*/

#include "4040Component.hpp"

nts::RippleCounter::RippleCounter() : AComponent(16)
{
    _pinsOn = 0;
    _counter = 0;
    for (std::size_t i=1; i < 16; i++) {
        if (i != 8 && i != 10 && i != 11)
            savedState[i] = nts::Undefined;
    }
}

void nts::RippleCounter::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin < 1 || pin > 15 || pin == 8)
        throw Error("Invalid pin on 4040 component.");
    pins[pin].targetPin = otherPin;
    pins[pin].targetComp = &other;
}

nts::Tristate nts::RippleCounter::getPinValue(std::size_t targetPin)
{
        nts::Tristate result = nts::False;
        savedState[targetPin] = result;
        switch (targetPin) {
            case 9:
                if (_pinsOn >= 0 || savedState[targetPin] == nts::True)
                    result = nts::True;
                break;
            case 7:
                if (_pinsOn >= 1 || savedState[targetPin] == nts::True)
                    result = nts::True;
                break;
            case 6:
                if (_pinsOn >= 2 || savedState[targetPin] == nts::True)
                    result = nts::True;
                break;
            case 5:
                if (_pinsOn >= 3 || savedState[targetPin] == nts::True)
                    result = nts::True;
                break;
            case 3:
                if (_pinsOn >= 4 || savedState[targetPin] == nts::True)
                    result = nts::True;
                break;
            case 2:
                if (_pinsOn >= 5 || savedState[targetPin] == nts::True)
                    result = nts::True;
                break;
            case 4:
                if (_pinsOn >= 6 || savedState[targetPin] == nts::True)
                    result = nts::True;
                break;
            case 13:
                if (_pinsOn >= 7 || savedState[targetPin] == nts::True)
                    result = nts::True;
                break;
            case 12:
                if (_pinsOn >= 8 || savedState[targetPin] == nts::True)
                    result = nts::True;
                break;
            case 14:
                if (_pinsOn >= 9 || savedState[targetPin] == nts::True)
                    result = nts::True;
                break;
            case 15:
                if (_pinsOn >= 10 || savedState[targetPin] == nts::True)
                    result = nts::True;
                break;
            case 1:
                if (_pinsOn >= 11 || savedState[targetPin] == nts::True)
                    result = nts::True;
                break;
            default:
                result = nts::False;
                break;
        }
        savedState[targetPin] = result;
        return result;
}

void nts::RippleCounter::simulate(std::size_t tick)
{
    // increase or not pinsOn
    if (tick == 0)
        return;
}

nts::Tristate nts::RippleCounter::compute(std::size_t pin)
{
    if (pin < 1 || pin > 15 || pin == 8)
        throw Error("Invalid pin on 4013 component.");
    nts::Tristate Cl = pins[14].targetComp->compute(pins[pins[14].targetPin].targetPin);
    nts::Tristate i1 = pins[13].targetComp->compute(pins[pins[13].targetPin].targetPin);
    nts::Tristate R = pins[15].targetComp->compute(pins[pins[15].targetPin].targetPin);
    nts::Tristate result;
    if (i1 == True)
        return (savedState[pin]);
    if (R == True || _counter == 10)
        _counter = 0;
    if (pin != 13 && pin != 14 && pin != 15 &&  pin != 12) {
        if (Cl ==  nts::True) {
            result = getPinValue(pin);
        } else {
            result = (savedState[pin]);
        }
        return result;
    }
    if (pin == 12) {
        if (_counter < 5)
            return nts::True;
        else
            return nts::False;
    }
    return (pins[pin].targetComp->compute(pins[pins[pin].targetPin].targetPin));
};