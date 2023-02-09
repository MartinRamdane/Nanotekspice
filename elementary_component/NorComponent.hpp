/*
** EPITECH PROJECT, 2023
** OrComponent.hpp
** File description:
** OrComponent
*/

#ifndef NOR_COMPONENT
    #define NOR_COMPONENT

#include <iostream>
#include "../AComponent.hpp"

namespace nts
{
    class NorComponent: public nts::AComponent {
        public:
            NorComponent() : AComponent(3){};
            ~NorComponent(){};

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !NOR_COMPONENT */
