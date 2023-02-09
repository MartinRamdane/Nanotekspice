/*
** EPITECH PROJECT, 2023
** FalseComponent.hpp
** File description:
** FalseComponent
*/

#ifndef FALSE_COMPONENT
    #define FALSE_COMPONENT

#include "../AComponent.hpp"
#include <iostream>

namespace nts
{
    class FalseComponent: public nts::AComponent {
        public:
            FalseComponent() : AComponent(1) {};
            ~FalseComponent() {};

            nts::Tristate compute(std::size_t pin);

        protected:
        private:
    };
}

#endif /* !FALSE_COMPONENT */
