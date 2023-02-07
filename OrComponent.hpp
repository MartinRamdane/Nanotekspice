/*
** EPITECH PROJECT, 2023
** OrComponent.hpp
** File description:
** OrComponent
*/

#ifndef OR_COMPONENT
    #define OR_COMPONENT

#include "AComponent.hpp"
#include <iostream>

namespace nts
{
    class OrComponent: public nts::AComponent {
        public:
            OrComponent() : AComponent(3){};
            ~OrComponent(){};

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !OR_COMPONENT */
