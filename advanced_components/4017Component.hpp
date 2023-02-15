/*
** EPITECH PROJECT, 2023
** 4017.hpp
** File description:
** 4017
*/

#ifndef JONHSONCOUNTER
    #define JONHSONCOUNTER

#include "../AComponent.hpp"
#include <iostream>
#include <memory>

namespace nts
{
    class JonhsonCounter: public nts::AComponent {
        public:
            JonhsonCounter();
            ~JonhsonCounter(){};

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            nts::Tristate compute(std::size_t pin);
            nts::Tristate checkTruthTable(std::size_t targetPin);
        private:
            int counter;
    };
}

#endif /* !JONHSONCOUNTER */
