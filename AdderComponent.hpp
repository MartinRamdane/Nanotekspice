/*
** EPITECH PROJECT, 2023
** AdderComponent.hpp
** File description:
** AdderComponent
*/

#ifndef ADDER_COMPONENT
    #define ADDER_COMPONENT

#include "AComponent.hpp"
#include <iostream>
#include <memory>
#include "IComponent.hpp"
#include "XorComponent.hpp"
#include "AndComponent.hpp"
#include "OrComponent.hpp"

namespace nts
{
    class AdderComponent: public nts::AComponent {
        public:
            AdderComponent();
            ~AdderComponent();

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            nts::Tristate compute(std::size_t pin);
        private:
            std::vector<std::unique_ptr<nts::IComponent>> comps;
    };
}

#endif /* !ADDER_COMPONENT */
