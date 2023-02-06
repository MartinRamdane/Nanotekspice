/*
** EPITECH PROJECT, 2023
** TrueComponent.hpp
** File description:
** TrueComponent
*/

#ifndef TRUE_COMPONENT
    #define TRUE_COMPONENT

#include "AComponent.hpp"
#include <iostream>

namespace nts
{
    class TrueComponent: public nts::AComponent {
        public:
            TrueComponent() : AComponent(1) {};
            ~TrueComponent() {};

            nts::Tristate compute(std::size_t pin);

        protected:
        private:
    };
}

#endif /* !TRUE_COMPONENT */
