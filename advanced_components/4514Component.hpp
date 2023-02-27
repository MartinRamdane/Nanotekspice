/*
** EPITECH PROJECT, 2023
** 4013.hpp
** File description:
** 4013
*/

#ifndef FOUR_BITS_DECODER
    #define FOUR_BITS_DECODER

#include "../AComponent.hpp"
#include <iostream>
#include <memory>

namespace nts
{
    class FourBitsDecoder: public nts::AComponent {
        public:
            FourBitsDecoder();
            ~FourBitsDecoder(){};

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin);
            nts::Tristate checkTruthTable(size_t pin, Tristate A, Tristate B, Tristate C, Tristate D, Tristate Strobe);
        private:
            nts::Tristate a;
            nts::Tristate b;
            nts::Tristate c;
            nts::Tristate d;
            nts::Tristate strobe;
            nts::Tristate inhibit;
            bool toChangeStrobe;
    };
}

#endif /* !FOUR_BITS_DECODER */
