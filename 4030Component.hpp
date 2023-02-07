/*
** EPITECH PROJECT, 2023
** 4001Component.hpp
** File 4001Component:
** 4001Component
*/

#ifndef FOURXOR_COMPONENT
    #define FOURXOR_COMPONENT

#include "AComponent.hpp"
#include <iostream>
#include <memory>
#include "XorComponent.hpp"

namespace nts
{
    class FourXorComponent: public nts::AComponent {
        public:
            FourXorComponent();
            ~FourXorComponent();

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            nts::Tristate compute(std::size_t pin);
        private:
            std::vector<nts::XorComponent> xors;
    };
}

#endif /* !FOURNOR_COMPONENT */
