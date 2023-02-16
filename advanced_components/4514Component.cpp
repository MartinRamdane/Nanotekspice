/*
** EPITECH PROJECT, 2023
** 4013
** File description:
** 4013
*/

#include "4514Component.hpp"

nts::FourBitsDecoder::FourBitsDecoder() : AComponent(23)
{
}

void nts::FourBitsDecoder::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin < 1 || pin > 23 || pin == 12)
        throw Error("Invalid pin on 4514 component.");
    pins[pin].targetPin = otherPin;
    pins[pin].targetComp = &other;
}

nts::Tristate nts::FourBitsDecoder::checkTruthTable(std::size_t pin)
{
    Tristate Inhibit = pins[23].targetComp->compute(1);
    if (Inhibit == True)
        return False;
    Tristate LE = pins[1].targetComp->compute(1);
    if (Inhibit == False && LE == False)
        return Undefined;
    Tristate A = pins[2].targetComp->compute(1);
    Tristate B = pins[3].targetComp->compute(1);
    Tristate C = pins[21].targetComp->compute(1);
    Tristate D = pins[22].targetComp->compute(1);
    if (LE == True && Inhibit == False) {
        switch (pin) {
            case 11: return ((A == False && B == False && C == False && D == False) ? True : Undefined);
            case 9: return ((A == True && B == False && C == False && D == False) ? True : Undefined);
            case 10: return ((A == False && B == True && C == False && D == False) ? True : Undefined);
            case 8: return ((A == True && B == True && C == False && D == False) ? True : Undefined);
            case 7: return ((A == False && B == False && C == True && D == False) ? True : Undefined);
            case 6: return ((A == True && B == False && C == True && D == False) ? True : Undefined);
            case 5: return ((A == False && B == True && C == True && D == False) ? True : Undefined);
            case 4: return ((A == True && B == True && C == True && D == False) ? True : Undefined);
            case 18: return ((A == False && B == False && C == False && D == True) ? True : Undefined);
            case 17: return ((A == True && B == False && C == False && D == True) ? True : Undefined);
            case 20: return ((A == False && B == True && C == False && D == True) ? True : Undefined);
            case 19: return ((A == True && B == True && C == False && D == True) ? True : Undefined);
            case 14: return ((A == False && B == False && C == True && D == True) ? True : Undefined);
            case 13: return ((A == True && B == False && C == True && D == True) ? True : Undefined);
            case 16: return ((A == False && B == True && C == True && D == True) ? True : Undefined);
            case 15: return ((A == True && B == True && C == True && D == True) ? True : Undefined);
        }
    }
   return Undefined;
}

nts::Tristate nts::FourBitsDecoder::compute(std::size_t pin)
{
    if (pin < 1 || pin > 23 || pin == 12)
        throw Error("Invalid pin on 4514 component.");
    if (pin >= 4 && pin <= 20)
        return checkTruthTable(pin);
    return (pins[pin].targetComp->compute(pins[pins[pin].targetPin].targetPin));
};
