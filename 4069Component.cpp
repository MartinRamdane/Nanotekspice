/*
** EPITECH PROJECT, 2023
** 4069Component.cpp
** File description:
** 4069Component
*/

#include "4069Component.hpp"

nts::SixNotComponent::SixNotComponent() : AComponent(14)
{
    nots.push_back(nts::NotComponent());
    nots.push_back(nts::NotComponent());
    nots.push_back(nts::NotComponent());
    nots.push_back(nts::NotComponent());
    nots.push_back(nts::NotComponent());
    nots.push_back(nts::NotComponent());
}

nts::SixNotComponent::~SixNotComponent()
{
}

void nts::SixNotComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin % 2 == 0) {
        switch (pin) {
            case 2: nots[0].setLink(2, other, otherPin); break;
            case 4: nots[1].setLink(2, other, otherPin);break;
            case 6: nots[2].setLink(2, other, otherPin);break;
            case 8: nots[3].setLink(2, other, otherPin);break;
            case 10: nots[4].setLink(2, other, otherPin);break;
            case 12: nots[5].setLink(2, other, otherPin);break;
        }
    }
    else {
        switch (pin) {
            case 1: nots[0].setLink(1, other, otherPin); break;
            case 3: nots[1].setLink(1, other, otherPin);break;
            case 5: nots[2].setLink(1, other, otherPin);break;
            case 9: nots[3].setLink(1, other, otherPin);break;
            case 11: nots[4].setLink(1, other, otherPin);break;
            case 13: nots[5].setLink(1, other, otherPin);break;
        }
    }
}


nts::Tristate nts::SixNotComponent::compute(std::size_t pin)
{
    if (pin % 2 == 0) {
        switch (pin) {
            case 2: return nots[0].compute(2);
            case 4: return nots[1].compute(2);
            case 6: return nots[2].compute(2);
            case 8: return nots[3].compute(2);
            case 10: return nots[4].compute(2);
            case 12: return nots[5].compute(2);
        }
    }
    else {
        switch (pin) {
            case 1: return nots[0].compute(1);
            case 3: return nots[1].compute(1);
            case 5: return nots[2].compute(1);
            case 9: return nots[3].compute(1);
            case 11: return nots[4].compute(1);
            case 13: return nots[5].compute(1);
        }
    }
    return nts::Undefined;
}