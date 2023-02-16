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
#include <map>
#include <memory>

namespace nts
{
    class JonhsonCounter: public nts::AComponent {
        public:
            JonhsonCounter();
            ~JonhsonCounter(){};

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            nts::Tristate checkTruthTable(std::size_t targetPin);
            nts::Tristate getPinValue(std::size_t targetPin);
        private:
            std::size_t prevTick;
            int counter;
            std::map<std::size_t, nts::Tristate> savedState;
    };
}

#endif /* !JONHSONCOUNTER */
