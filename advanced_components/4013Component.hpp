/*
** EPITECH PROJECT, 2023
** 4013.hpp
** File description:
** 4013
*/

#ifndef DUAL_FLIPFLOP
    #define DUAL_FLIPFLOP

#include "../AComponent.hpp"
#include <iostream>
#include <memory>
#include "../IComponent.hpp"
#include "AdderComponent.hpp"

namespace nts
{
    class DualDFlipFlopComponent: public nts::AComponent {
        public:
            DualDFlipFlopComponent();
            ~DualDFlipFlopComponent(){};

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            nts::Tristate compute(std::size_t pin);
            nts::Tristate checkTruthTable(std::size_t targetPin);
        private:
            std::vector<nts::Tristate> saveOutput;
    };
}

#endif /* !DUAL_FLIPFLOP */
