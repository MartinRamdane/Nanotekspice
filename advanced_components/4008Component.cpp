/*
** EPITECH PROJECT, 2023
** 4008Component.cpp
** File description:
** 4008Component
*/

#include "4008Component.hpp"

nts::FourAdderComponent::FourAdderComponent() : AComponent(16)
{
    adders.push_back(std::make_unique<nts::AdderComponent>());
    adders.push_back(std::make_unique<nts::AdderComponent>());
    adders.push_back(std::make_unique<nts::AdderComponent>());
    adders.push_back(std::make_unique<nts::AdderComponent>());
    adders[1]->setLink(3, *adders[0], 4);
    adders[2]->setLink(3, *adders[1], 4);
    adders[3]->setLink(3, *adders[2], 4);
}

nts::FourAdderComponent::~FourAdderComponent()
{
    adders.clear();
}

void nts::FourAdderComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin < 1 || pin > 15 || pin == 8)
        throw Error("Invalid pin on 4008 component.");
    switch (pin) {
        case 15: adders[3]->setLink(2, other, otherPin); break;
        case 1: adders[3]->setLink(1, other, otherPin); break;
        case 2: adders[2]->setLink(2, other, otherPin); break;
        case 3: adders[2]->setLink(1, other, otherPin); break;
        case 4: adders[1]->setLink(2, other, otherPin); break;
        case 5: adders[1]->setLink(1, other, otherPin); break;
        case 6: adders[0]->setLink(2, other, otherPin); break;
        case 7: adders[0]->setLink(1, other, otherPin); break;
        case 9: adders[0]->setLink(3, other, otherPin); break;
        case 10: adders[0]->setLink(5, other, otherPin); break;
        case 11: adders[1]->setLink(5, other, otherPin); break;
        case 12: adders[2]->setLink(5, other, otherPin); break;
        case 13: adders[3]->setLink(5, other, otherPin); break;
        case 14: adders[3]->setLink(4, other, otherPin); break;
        default:
            break;
    }
}

nts::Tristate nts::FourAdderComponent::compute(std::size_t pin)
{
    if (pin < 1 || pin > 15 || pin == 8)
        throw Error("Invalid pin on 4008 component.");
    switch (pin) {
        case 15: return adders[3]->compute(2);
        case 1: return adders[3]->compute(1);
        case 2: return adders[2]->compute(2);
        case 3: return adders[2]->compute(1);
        case 4: return adders[1]->compute(2);
        case 5: return adders[1]->compute(1);
        case 6: return adders[0]->compute(2);
        case 7: return adders[0]->compute(1);
        case 9: return adders[0]->compute(3);
        case 10: return adders[0]->compute(5);
        case 11: return adders[1]->compute(5);
        case 12: return adders[2]->compute(5);
        case 13: return adders[3]->compute(5);
        case 14: return adders[3]->compute(4);
        default:
            break;
    }
    return nts::Undefined;
};