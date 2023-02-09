/*
** EPITECH PROJECT, 2023
** OutpoutComponent.hpp
** File description:
** OutpoutComponent
*/

#ifndef OUTPUT_COMPONENT
    #define OUTPUT_COMPONENT

#include "../AComponent.hpp"

namespace nts
{
    class OutpoutComponent : public AComponent {
        public:
            OutpoutComponent() : AComponent(1) {};
            ~OutpoutComponent() {};

            nts::Tristate compute(std::size_t pin) {return pins[pin].targetComp->compute(pins[pin].targetPin);};

        protected:
        private:
    };
}

#endif /* !OUTPUT_COMPONENT */
