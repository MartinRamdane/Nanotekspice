/*
** EPITECH PROJECT, 2023
** 4013
** File description:
** 4013
*/

#include "4514Component.hpp"

nts::FourBitsDecoder::FourBitsDecoder() : AComponent(24)
{
}

void nts::FourBitsDecoder::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin < 1 || pin > 23 || pin == 12)
        throw Error("Invalid pin on 4514 component.");
    pins[pin].targetPin = otherPin;
    pins[pin].targetComp = &other;
}

nts::Tristate nts::FourBitsDecoder::checkTruthTable(size_t pin)
{
    Tristate Inhibit = pins[23].targetComp->compute(1);
    if (Inhibit == True)
        return False;
    Tristate LE = pins[1].targetComp->compute(1);
    if (Inhibit == False && LE == False)
        return (pins[1].targetComp->compute(1));
    Tristate A = pins[2].targetComp->compute(1);
    Tristate B = pins[3].targetComp->compute(1);
    Tristate C = pins[21].targetComp->compute(1);
    Tristate D = pins[22].targetComp->compute(1);
    if (Inhibit == False && LE == True) {
        switch (pin) {
            case 11: return (D == False && C == False && B == False && A == False ? True : False);
            case 9: return (D == False && C == False && B == False && A == True ? True : False);
            case 10: return (D == False && C == False && B == True && A == False ? True : False);
            case 8: return (D == False && C == False && B == True && A == True ? True : False);
            case 7: return (D == False && C == True && B == False && A == False ? True : False);
            case 6: return (D == False && C == True && B == False && A == True ? True : False);
            case 5: return (D == False && C == True && B == True && A == False ? True : False);
            case 4: return (D == False && C == True && B == True && A == True ? True : False);
            case 18: return (D == True && C == False && B == False && A == False ? True : False);
            case 17: return (D == True && C == False && B == False && A == True ? True : False);
            case 20: return (D == True && C == False && B == True && A == False ? True : False);
            case 19: return (D == True && C == False && B == True && A == True ? True : False);
            case 14: return (D == True && C == True && B == False && A == False ? True : False);
            case 13: return (D == True && C == True && B == False && A == True ? True : False);
            case 16: return (D == True && C == True && B == True && A == False ? True : False);
            case 15: return (D == True && C == True && B == True && A == True ? True : False);
            default: return Undefined;
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
