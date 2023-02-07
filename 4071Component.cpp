/*
** EPITECH PROJECT, 2023
** 4071Component.cpp
** File description:
** 4071Component
*/

#include "4071Component.hpp"

nts::FourOrComponent::FourOrComponent() : AComponent(14)
{
    ors.push_back(nts::OrComponent());
    ors.push_back(nts::OrComponent());
    ors.push_back(nts::OrComponent());
    ors.push_back(nts::OrComponent());
}

nts::FourOrComponent::~FourOrComponent()
{
}

void nts::FourOrComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
        switch (pin) {
            case 3: ors[0].setLink(3, other, otherPin); break;
            case 4: ors[1].setLink(3, other, otherPin);break;
            case 10: ors[2].setLink(3, other, otherPin);break;
            case 11: ors[3].setLink(3, other, otherPin);break;
        }
    }
    if (pin == 1 || pin == 5 || pin == 8 || pin == 12) {
        switch (pin) {
            case 1: ors[0].setLink(1, other, otherPin); break;
            case 5: ors[1].setLink(1, other, otherPin);break;
            case 8: ors[2].setLink(1, other, otherPin);break;
            case 12: ors[3].setLink(1, other, otherPin);break;
        }
    }
    if (pin == 2 || pin == 6 || pin == 9 || pin == 13) {
        switch (pin) {
            case 2: ors[0].setLink(2, other, otherPin); break;
            case 6: ors[1].setLink(2, other, otherPin);break;
            case 9: ors[2].setLink(2, other, otherPin);break;
            case 13: ors[3].setLink(2, other, otherPin);break;
        }
    }
}


nts::Tristate nts::FourOrComponent::compute(std::size_t pin)
{
    if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
        switch (pin) {
            case 3: return ors[0].compute(3);
            case 4: return ors[1].compute(3);
            case 10: return ors[2].compute(3);
            case 11: return ors[3].compute(3);
        }
    }
    if (pin == 1 || pin == 5 || pin == 8 || pin == 12) {
        switch (pin) {
            case 1: return ors[0].compute(1);
            case 5: return ors[1].compute(1);
            case 8: return ors[2].compute(1);
            case 12: return ors[3].compute(1);
        }
    }
    if (pin == 2 || pin == 6 || pin == 9 || pin == 13) {
        switch (pin) {
            case 2: return ors[0].compute(2);
            case 6: return ors[1].compute(2);
            case 9: return ors[2].compute(2);
            case 13: return ors[3].compute(2);
        }
    }
    return nts::Undefined;
}