/*
** EPITECH PROJECT, 2023
** AComponent
** File description:
** AComponent
*/

#ifndef ACOMPONENT
    #define ACOMPONENT

#include "IComponent.hpp"
#include <iostream>
#include <vector>
#include <memory>

namespace nts
{
    class AComponent: public IComponent {

        struct pinInfo {
            IComponent *targetComp;
            std::size_t targetPin;
        };

        public:
            AComponent(std::size_t nbPins);
            ~AComponent();

            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void simulate(std::size_t tick) {tick += 1;};
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            nts::Tristate getLink(std::size_t pin) const;

        protected:
            std::vector<pinInfo> pins;

    };
}

std::ostream &operator<<( std :: ostream & s , nts :: Tristate v );

#endif /* !ACOMPONENT */
