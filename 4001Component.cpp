/*
** EPITECH PROJECT, 2023
** 4001Component.cpp
** File description:
** 4001Component
*/

#include "4001Component.hpp"

nts::FourNorComponent::FourNorComponent() : AComponent(14)
{
    nors.push_back(nts::NorComponent());
    nors.push_back(nts::NorComponent());
    nors.push_back(nts::NorComponent());
    nors.push_back(nts::NorComponent());
}

nts::FourNorComponent::~FourNorComponent()
{
}

void nts::FourNorComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
        switch (pin) {
            case 3: nors[0].setLink(3, other, otherPin); break;
            case 4: nors[1].setLink(3, other, otherPin);break;
            case 10: nors[2].setLink(3, other, otherPin);break;
            case 11: nors[3].setLink(3, other, otherPin);break;
        }
    }
    if (pin == 1 || pin == 5 || pin == 8 || pin == 12) {
        switch (pin) {
            case 1: nors[0].setLink(1, other, otherPin); break;
            case 5: nors[1].setLink(1, other, otherPin);break;
            case 8: nors[2].setLink(1, other, otherPin);break;
            case 12: nors[3].setLink(1, other, otherPin);break;
        }
    }
    if (pin == 2 || pin == 6 || pin == 9 || pin == 13) {
        switch (pin) {
            case 2: nors[0].setLink(2, other, otherPin); break;
            case 6: nors[1].setLink(2, other, otherPin);break;
            case 9: nors[2].setLink(2, other, otherPin);break;
            case 13: nors[3].setLink(2, other, otherPin);break;
        }
    }
}


nts::Tristate nts::FourNorComponent::compute(std::size_t pin)
{
    if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
        switch (pin) {
            case 3: return nors[0].compute(3);
            case 4: return nors[1].compute(3);
            case 10: return nors[2].compute(3);
            case 11: return nors[3].compute(3);
        }
    }
    if (pin == 1 || pin == 5 || pin == 8 || pin == 12) {
        switch (pin) {
            case 1: return nors[0].compute(1);
            case 5: return nors[1].compute(1);
            case 8: return nors[2].compute(1);
            case 12: return nors[3].compute(1);
        }
    }
    if (pin == 2 || pin == 6 || pin == 9 || pin == 13) {
        switch (pin) {
            case 2: return nors[0].compute(2);
            case 6: return nors[1].compute(2);
            case 9: return nors[2].compute(2);
            case 13: return nors[3].compute(2);
        }
    }
    return nts::Undefined;
}