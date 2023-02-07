/*
** EPITECH PROJECT, 2023
** FourOrComponent.hpp
** File description:
** FourOrComponent
*/

#ifndef FOUROR_COMPONENT
    #define FOUROR_COMPONENT

#include "AComponent.hpp"
#include <iostream>
#include <memory>
#include "OrComponent.hpp"

namespace nts
{
    class FourOrComponent: public nts::AComponent {
        public:
            FourOrComponent();
            ~FourOrComponent();

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            nts::Tristate compute(std::size_t pin);
        private:
            std::vector<nts::OrComponent> ors;
    };
}

#endif /* !FOUROR_COMPONENT */
