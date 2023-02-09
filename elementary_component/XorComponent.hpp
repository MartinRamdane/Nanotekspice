/*
** EPITECH PROJECT, 2023
** XOrComponent.hpp
** File description:
** XOrComponent
*/

#ifndef XOR_COMPONENT
    #define XOR_COMPONENT

#include "../AComponent.hpp"
#include <iostream>

namespace nts
{
    class XorComponent: public nts::AComponent {
        public:
            XorComponent() : AComponent(3){};
            ~XorComponent(){};

            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !XOR_COMPONENT */
