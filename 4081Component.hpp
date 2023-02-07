/*
** EPITECH PROJECT, 2023
** FourAndComponent.hpp
** File description:
** FourAndComponent
*/

#ifndef FOURAND_COMPONENT
    #define FOURAND_COMPONENT

#include "AComponent.hpp"
#include <iostream>
#include <memory>
#include "AndComponent.hpp"

namespace nts
{
    class FourAndComponent: public nts::AComponent {
        public:
            FourAndComponent();
            ~FourAndComponent();

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            nts::Tristate compute(std::size_t pin);
        private:
            std::vector<nts::AndComponent> ands;
    };
}

#endif /* !FOURAND_COMPONENT */
