/*
** EPITECH PROJECT, 2023
** 4011Component.cpp
** File description:
** 4011Component
*/

#include "4011Component.hpp"

nts::FourNandComponent::FourNandComponent() : AComponent(14)
{
    nands.push_back(nts::NandComponent());
    nands.push_back(nts::NandComponent());
    nands.push_back(nts::NandComponent());
    nands.push_back(nts::NandComponent());
}

nts::FourNandComponent::~FourNandComponent()
{
}

void nts::FourNandComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
        switch (pin) {
            case 3: nands[0].setLink(3, other, otherPin); break;
            case 4: nands[1].setLink(3, other, otherPin);break;
            case 10: nands[2].setLink(3, other, otherPin);break;
            case 11: nands[3].setLink(3, other, otherPin);break;
        }
    }
    if (pin == 1 || pin == 5 || pin == 8 || pin == 12) {
        switch (pin) {
            case 1: nands[0].setLink(1, other, otherPin); break;
            case 5: nands[1].setLink(1, other, otherPin);break;
            case 8: nands[2].setLink(1, other, otherPin);break;
            case 12: nands[3].setLink(1, other, otherPin);break;
        }
    }
    if (pin == 2 || pin == 6 || pin == 9 || pin == 13) {
        switch (pin) {
            case 2: nands[0].setLink(2, other, otherPin); break;
            case 6: nands[1].setLink(2, other, otherPin);break;
            case 9: nands[2].setLink(2, other, otherPin);break;
            case 13: nands[3].setLink(2, other, otherPin);break;
        }
    }
}


nts::Tristate nts::FourNandComponent::compute(std::size_t pin)
{
    if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
        switch (pin) {
            case 3: return nands[0].compute(3);
            case 4: return nands[1].compute(3);
            case 10: return nands[2].compute(3);
            case 11: return nands[3].compute(3);
        }
    }
    if (pin == 1 || pin == 5 || pin == 8 || pin == 12) {
        switch (pin) {
            case 1: return nands[0].compute(1);
            case 5: return nands[1].compute(1);
            case 8: return nands[2].compute(1);
            case 12: return nands[3].compute(1);
        }
    }
    if (pin == 2 || pin == 6 || pin == 9 || pin == 13) {
        switch (pin) {
            case 2: return nands[0].compute(2);
            case 6: return nands[1].compute(2);
            case 9: return nands[2].compute(2);
            case 13: return nands[3].compute(2);
        }
    }
    return nts::Undefined;
}