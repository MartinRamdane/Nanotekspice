/*
** EPITECH PROJECT, 2023
** OrComponent.hpp
** File description:
** OrComponent
*/

#ifndef AND_COMPONENT
    #define AND_COMPONENT

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

#endif /* !AND_COMPONENT */
