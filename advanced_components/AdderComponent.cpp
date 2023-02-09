/*
** EPITECH PROJECT, 2023
** AdderComponent.cpp
** File description:
** AdderComponent
*/

#include "AdderComponent.hpp"

nts::AdderComponent::AdderComponent() : AComponent(5)
{
    comps.push_back(std::make_unique<nts::XorComponent>());
    comps.push_back(std::make_unique<nts::AndComponent>());
    comps.push_back(std::make_unique<nts::XorComponent>());
    comps.push_back(std::make_unique<nts::AndComponent>());
    comps.push_back(std::make_unique<nts::OrComponent>());
    comps[2]->setLink(1, *comps[0], 3);
    comps[3]->setLink(2, *comps[0], 3);
    comps[4]->setLink(1, *comps[1], 3);
    comps[4]->setLink(2, *comps[3], 3);
}

nts::AdderComponent::~AdderComponent()
{
    comps.clear();
}

void nts::AdderComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin < 1 || pin > 5)
        throw Error("Invalid pin on Adder component.");
    switch (pin) {
        case 1:
            comps[0]->setLink(1, other, otherPin);
            comps[1]->setLink(1, other, otherPin);
            break;
        case 2:
            comps[0]->setLink(2, other, otherPin);
            comps[1]->setLink(2, other, otherPin);
            break;
        case 3:
            comps[2]->setLink(2, other, otherPin);
            comps[3]->setLink(1, other, otherPin);
            break;
        case 4:
            comps[4]->setLink(3, other, otherPin);
            break;
        case 5:
            comps[2]->setLink(3, other, otherPin);
            break;
        default:
            break;
    }
}

nts::Tristate nts::AdderComponent::compute(std::size_t pin)
{
    if (pin < 1 || pin > 5)
        throw Error("Invalid pin on Adder component.");
    switch (pin) {
        case 1: return comps[0]->compute(1);
        case 2: return comps[0]->compute(2);
        case 3: return comps[2]->compute(2);
        case 4: return comps[4]->compute(3);
        case 5: return comps[2]->compute(3);
        default:
            break;
    }
    return nts::Undefined;
}