/*
** EPITECH PROJECT, 2023
** 4081Component.cpp
** File description:
** 4081Component
*/

#include "4081Component.hpp"

nts::FourAndComponent::FourAndComponent() : AComponent(14)
{
    ands.push_back(nts::AndComponent());
    ands.push_back(nts::AndComponent());
    ands.push_back(nts::AndComponent());
    ands.push_back(nts::AndComponent());
}

nts::FourAndComponent::~FourAndComponent()
{
}

void nts::FourAndComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
        switch (pin) {
            case 3: ands[0].setLink(3, other, otherPin); break;
            case 4: ands[1].setLink(3, other, otherPin);break;
            case 10: ands[2].setLink(3, other, otherPin);break;
            case 11: ands[3].setLink(3, other, otherPin);break;
        }
    }
    if (pin == 1 || pin == 5 || pin == 8 || pin == 12) {
        switch (pin) {
            case 1: ands[0].setLink(1, other, otherPin); break;
            case 5: ands[1].setLink(1, other, otherPin);break;
            case 8: ands[2].setLink(1, other, otherPin);break;
            case 12: ands[3].setLink(1, other, otherPin);break;
        }
    }
    if (pin == 2 || pin == 6 || pin == 9 || pin == 13) {
        switch (pin) {
            case 2: ands[0].setLink(2, other, otherPin); break;
            case 6: ands[1].setLink(2, other, otherPin);break;
            case 9: ands[2].setLink(2, other, otherPin);break;
            case 13: ands[3].setLink(2, other, otherPin);break;
        }
    }
}


nts::Tristate nts::FourAndComponent::compute(std::size_t pin)
{
    if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
        switch (pin) {
            case 3: return ands[0].compute(3);
            case 4: return ands[1].compute(3);
            case 10: return ands[2].compute(3);
            case 11: return ands[3].compute(3);
        }
    }
    if (pin == 1 || pin == 5 || pin == 8 || pin == 12) {
        switch (pin) {
            case 1: return ands[0].compute(1);
            case 5: return ands[1].compute(1);
            case 8: return ands[2].compute(1);
            case 12: return ands[3].compute(1);
        }
    }
    if (pin == 2 || pin == 6 || pin == 9 || pin == 13) {
        switch (pin) {
            case 2: return ands[0].compute(2);
            case 6: return ands[1].compute(2);
            case 9: return ands[2].compute(2);
            case 13: return ands[3].compute(2);
        }
    }
    return nts::Undefined;
}