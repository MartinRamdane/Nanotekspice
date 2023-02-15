/*
** EPITECH PROJECT, 2023
** 4013
** File description:
** 4013
*/

#include "4013Component.hpp"

nts::DualDFlipFlopComponent::DualDFlipFlopComponent() : AComponent(14)
{
    saveOutput.push_back(Undefined);
    saveOutput.push_back(Undefined);
    saveOutput.push_back(Undefined);
    saveOutput.push_back(Undefined);
    saveOutput.push_back(Undefined);
}

void nts::DualDFlipFlopComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin < 1 || pin > 14 || pin == 7 || pin == 14)
        throw Error("Invalid pin on 4013 component.");
    pins[pin].targetPin = otherPin;
    pins[pin].targetComp = &other;
}

nts::Tristate nts::DualDFlipFlopComponent::checkTruthTable(std::size_t targetPin)
{
    nts::Tristate Cl; nts::Tristate R; nts::Tristate D; nts::Tristate S;
    std::size_t savePin = (targetPin == 1 || targetPin == 2 ? targetPin : targetPin == 13 ? 3 : 4);
    nts::Tristate result;
    if (targetPin <= 2) {
        Cl = pins[3].targetComp->compute(pins[pins[3].targetPin].targetPin); R = pins[4].targetComp->compute(pins[pins[4].targetPin].targetPin);
        D = pins[5].targetComp->compute(pins[pins[5].targetPin].targetPin); S = pins[6].targetComp->compute(pins[pins[6].targetPin].targetPin);
    } else {
        Cl = pins[11].targetComp->compute(pins[pins[11].targetPin].targetPin); R = pins[10].targetComp->compute(pins[pins[10].targetPin].targetPin);
        D = pins[9].targetComp->compute(pins[pins[9].targetPin].targetPin); S = pins[8].targetComp->compute(pins[pins[8].targetPin].targetPin);
    }
    if (targetPin == 1 || targetPin == 13) {
        if (Cl == True && D == False && R == False && S == False)
            result = False;
        if (Cl == True && D == True && R == False && S == False)
            result = True;
        if (Cl == False && R == False && S == False)
            return (saveOutput[savePin]);
        if (R == True && S == False)
            result = False;
        if (S == True)
            result = True;
    } else {
        if (Cl == True && D == False && R == False && S == False)
            result = True;
        if (Cl == True && D == True && R == False && S == False)
            result = False;
        if (Cl == False && R == False && S == False)
            return (saveOutput[savePin]);
        if (R == True && S == False)
            result = True;
        if (S == True && R == False)
            result = False;
        if (S == True && R == True)
            result = True;
    }
    saveOutput[savePin] = result;
    return (result);
}

nts::Tristate nts::DualDFlipFlopComponent::compute(std::size_t pin)
{
    if (pin < 1 || pin > 14 || pin == 7 || pin == 14)
        throw Error("Invalid pin on 4013 component.");
    switch (pin) {
        case 1: return (checkTruthTable(1));
        case 2: return (checkTruthTable(2));
        case 13: return (checkTruthTable(13));
        case 12: return (checkTruthTable(12));
        default:
            break;
    }
    return (pins[pin].targetComp->compute(pins[pins[pin].targetPin].targetPin));
};