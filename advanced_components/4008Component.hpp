/*
** EPITECH PROJECT, 2023
** 4008Component.hpp
** File description:
** 4008Component
*/

#ifndef FOUR_BITS_ADDER
    #define FOUR_BITS_ADDER

#include "../AComponent.hpp"
#include <iostream>
#include <memory>
#include "../IComponent.hpp"
#include "AdderComponent.hpp"

namespace nts
{
    class FourAdderComponent: public nts::AComponent {
        public:
            FourAdderComponent();
            ~FourAdderComponent();

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            nts::Tristate compute(std::size_t pin);
        private:
            std::vector<std::unique_ptr<nts::AdderComponent>> adders;
    };
}

#endif /* !FOUR_BITS_ADDER */
