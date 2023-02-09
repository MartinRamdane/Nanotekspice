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
            OutpoutComponent();
            ~OutpoutComponent();

            nts::Tristate compute(std::size_t pin);

        protected:
        private:
    };
}

#endif /* !OUTPUT_COMPONENT */
