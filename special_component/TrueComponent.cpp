/*
** EPITECH PROJECT, 2023
** TrueComponent.cpp
** File description:
** TrueComponent
*/

#include "TrueComponent.hpp"


nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw nts::Error("Invalid pin on True component.");
    return True;
}