/*
** EPITECH PROJECT, 2023
** AndComponent.hpp
** File description:
** AndComponent
*/

#ifndef AND_COMPONENT
    #define AND_COMPONENT

#include "AComponent.hpp"
#include <iostream>

namespace nts
{
    class AndComponent: public nts::AComponent {
        public:
            AndComponent() : AComponent(3) {};
            ~AndComponent() {};

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !AND_COMPONENT */
