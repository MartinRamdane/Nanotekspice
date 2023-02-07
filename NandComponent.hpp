/*
** EPITECH PROJECT, 2023
** AndComponent.hpp
** File description:
** AndComponent
*/

#ifndef NAND_COMPONENT
    #define NAND_COMPONENT

#include "AComponent.hpp"
#include <iostream>

namespace nts
{
    class NandComponent: public nts::AComponent {
        public:
            NandComponent() : AComponent(3) {};
            ~NandComponent() {};

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !AND_COMPONENT */
