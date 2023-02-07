/*
** EPITECH PROJECT, 2023
** 4001Component.hpp
** File 4001Component:
** 4001Component
*/

#ifndef FOURNOR_COMPONENT
    #define FOURNOR_COMPONENT

#include "AComponent.hpp"
#include <iostream>
#include <memory>
#include "NorComponent.hpp"

namespace nts
{
    class FourNorComponent: public nts::AComponent {
        public:
            FourNorComponent();
            ~FourNorComponent();

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            nts::Tristate compute(std::size_t pin);
        private:
            std::vector<nts::NorComponent> nors;
    };
}

#endif /* !FOURNOR_COMPONENT */
