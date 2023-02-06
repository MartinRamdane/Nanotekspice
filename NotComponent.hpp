/*
** EPITECH PROJECT, 2023
** NotComponent.hpp
** File description:
** NotComponent
*/

#ifndef NOT_COMPONENT
    #define NOT_COMPONENT

#include "AComponent.hpp"
#include <iostream>

namespace nts
{
    class NotComponent: public nts::AComponent {
        public:
            NotComponent(): AComponent(2) {};
            ~NotComponent() {};

            nts::Tristate compute(std::size_t pin);

        protected:
        private:
    };
}

#endif /* !NOT_COMPONENT */
