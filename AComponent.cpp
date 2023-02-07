/*
** EPITECH PROJECT, 2023
** AComponent
** File description:
** AComponent
*/

#include "AComponent.hpp"

using namespace nts;

AComponent::AComponent(std::size_t nbPins)
{
    for (size_t i = 0; i <= nbPins; i++) {
        pinInfo _pinInfo;
        _pinInfo.targetPin = -1;
        _pinInfo.targetComp = nullptr;
        pins.push_back(_pinInfo);
    }
}

AComponent::~AComponent()
{
    pins.clear();
}


void AComponent::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
{
    pins[pin].targetPin = otherPin;
    pins[pin].targetComp = &other;
}

AComponent::pinInfo AComponent::getLink(std::size_t pin) const
{
    return (pins.at(pin));
}

std::ostream &operator<<( std :: ostream & s , nts :: Tristate v )
{
    if (v == nts::Undefined)
        s << 'U';
    else
        s << (v == nts::True ? 1 : 0);
    return s;
}