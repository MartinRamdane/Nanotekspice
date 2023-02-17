/*
** EPITECH PROJECT, 2023
** 4512Component.hpp
** File description:
** 4512 Component
*/

#ifndef SELECTOR
    #define SELECTOR

#include "../AComponent.hpp"
#include <iostream>
#include <memory>

namespace nts
{
    class Selector: public nts::AComponent {
        public:
            Selector();
            ~Selector(){};

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            nts::Tristate compute(std::size_t pin);
            nts::Tristate checkTruthTable();
        private:
    };
}

#endif /* !SELECTOR */
