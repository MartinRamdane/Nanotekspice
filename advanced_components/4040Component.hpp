/*
** EPITECH PROJECT, 2023
** 4040.hpp
** File description:
** 4040
*/

#ifndef BITSCOUNTERA
    #define BITSCOUNTERA

#include "../AComponent.hpp"
#include <iostream>
#include <map>
#include <memory>

namespace nts
{
    class RippleCounter: public nts::AComponent {
        public:
            RippleCounter();
            ~RippleCounter(){};

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            nts::Tristate checkTruthTable(std::size_t targetPin);
            nts::Tristate getPinValue(std::size_t targetPin);
        private:
            std::map<std::size_t, nts::Tristate> savedState;
            int _pinsOn;
            int _counter;
    };
}

#endif /* !JONHSONCOUNTER */
