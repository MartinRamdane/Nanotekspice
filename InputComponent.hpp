/*
** EPITECH PROJECT, 2023
** InputComponent.hpp
** File description:
** InputComponent
*/

#ifndef INPUT_COMPONENT
    #define INPUT_COMPONENT

#include "AComponent.hpp"

namespace nts
{
    class InputComponent : public AComponent {
        public:
            InputComponent() : AComponent(1) {valueOuput[0] = Undefined;};
            ~InputComponent() {};

            nts::Tristate compute(std::size_t pin) {return valueOuput[pin - 1];};
            void changeValue(Tristate targetValue) {valueOuput[0] = targetValue;};

        protected:
        private:
            Tristate valueOuput[1];
    };
}

#endif /* !INPUT_COMPONENT */
