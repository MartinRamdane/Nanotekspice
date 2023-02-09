/*
** EPITECH PROJECT, 2023
** FalseComponent.cpp
** File description:
** FalseComponent
*/

#include "FalseComponent.hpp"


nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw nts::Error("Invalid pin on False component.");
    return False;
}