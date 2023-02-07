/*
** EPITECH PROJECT, 2023
** 4001Component.cpp
** File description:
** 4001Component
*/

#include "4030Component.hpp"

nts::FourXorComponent::FourXorComponent() : AComponent(14)
{
    xors.push_back(nts::XorComponent());
    xors.push_back(nts::XorComponent());
    xors.push_back(nts::XorComponent());
    xors.push_back(nts::XorComponent());
}

nts::FourXorComponent::~FourXorComponent()
{
}

void nts::FourXorComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
        switch (pin) {
            case 3: xors[0].setLink(3, other, otherPin); break;
            case 4: xors[1].setLink(3, other, otherPin);break;
            case 10: xors[2].setLink(3, other, otherPin);break;
            case 11: xors[3].setLink(3, other, otherPin);break;
        }
    }
    if (pin == 1 || pin == 5 || pin == 8 || pin == 12) {
        switch (pin) {
            case 1: xors[0].setLink(1, other, otherPin); break;
            case 5: xors[1].setLink(1, other, otherPin);break;
            case 8: xors[2].setLink(1, other, otherPin);break;
            case 12: xors[3].setLink(1, other, otherPin);break;
        }
    }
    if (pin == 2 || pin == 6 || pin == 9 || pin == 13) {
        switch (pin) {
            case 2: xors[0].setLink(2, other, otherPin); break;
            case 6: xors[1].setLink(2, other, otherPin);break;
            case 9: xors[2].setLink(2, other, otherPin);break;
            case 13: xors[3].setLink(2, other, otherPin);break;
        }
    }
}


nts::Tristate nts::FourXorComponent::compute(std::size_t pin)
{
    if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
        switch (pin) {
            case 3: return xors[0].compute(3);
            case 4: return xors[1].compute(3);
            case 10: return xors[2].compute(3);
            case 11: return xors[3].compute(3);
        }
    }
    if (pin == 1 || pin == 5 || pin == 8 || pin == 12) {
        switch (pin) {
            case 1: return xors[0].compute(1);
            case 5: return xors[1].compute(1);
            case 8: return xors[2].compute(1);
            case 12: return xors[3].compute(1);
        }
    }
    if (pin == 2 || pin == 6 || pin == 9 || pin == 13) {
        switch (pin) {
            case 2: return xors[0].compute(2);
            case 6: return xors[1].compute(2);
            case 9: return xors[2].compute(2);
            case 13: return xors[3].compute(2);
        }
    }
    return nts::Undefined;
}