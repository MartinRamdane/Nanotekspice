/*
** EPITECH PROJECT, 2023
** 4011Component.hpp
** File 4011Component:
** 4011Component
*/

#ifndef FOURNAND_COMPONENT
    #define FOURNAND_COMPONENT

#include "AComponent.hpp"
#include <iostream>
#include <memory>
#include "NandComponent.hpp"

namespace nts
{
    class FourNandComponent: public nts::AComponent {
        public:
            FourNandComponent();
            ~FourNandComponent();

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            nts::Tristate compute(std::size_t pin);
        private:
            std::vector<nts::NandComponent> nands;
    };
}

#endif /* !FOURNAND_COMPONENT */
