// /*
// ** EPITECH PROJECT, 2023
// ** 4017.cpp
// ** File description:
// ** 4017
// */

// #include "4017Component.hpp"

// nts::JonhsonCounter::JonhsonCounter() : AComponent(16)
// {
//     counter = 0;
// }

// void nts::JonhsonCounter::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
// {
//     if (pin < 1 || pin > 15 || pin == 8)
//         throw Error("Invalid pin on 4013 component.");
//     pins[pin].targetPin = otherPin;
//     pins[pin].targetComp = &other;
// }

// nts::Tristate nts::DualDFlipFlopComponent::compute(std::size_t pin)
// {
//     if (pin < 1 || pin > 14 || pin == 7 || pin == 14)
//         throw Error("Invalid pin on 4013 component.");
//     if (pin != 13 && pin != 14 && pin != 15) {
//         if ()
//     }
//     return (pins[pin].targetComp->compute(pins[pins[pin].targetPin].targetPin));
// };