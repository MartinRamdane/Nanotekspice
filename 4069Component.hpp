/*
** EPITECH PROJECT, 2023
** SixNotComponent.hpp
** File description:
** SixNotComponent
*/

#ifndef SIXNOT_COMPONENT
    #define SIXNOT_COMPONENT

#include "AComponent.hpp"
#include <iostream>
#include <memory>
#include "NotComponent.hpp"

namespace nts
{
    class SixNotComponent: public nts::AComponent {
        public:
            SixNotComponent();
            ~SixNotComponent();

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            nts::Tristate compute(std::size_t pin);
        private:
            std::vector<nts::NotComponent> nots;
    };
}

#endif /* !SIXNOT_COMPONENT */
