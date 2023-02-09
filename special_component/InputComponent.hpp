/*
** EPITECH PROJECT, 2023
** InputComponent.hpp
** File description:
** InputComponent
*/

#ifndef INPUT_COMPONENT
    #define INPUT_COMPONENT

#include "../AComponent.hpp"

namespace nts
{
    class InputComponent : public AComponent {
        public:
            InputComponent();
            ~InputComponent();

            nts::Tristate compute(std::size_t pin);
            void changeValue(Tristate targetValue);

        protected:
        private:
            Tristate valueOuput[1];
    };
}

#endif /* !INPUT_COMPONENT */
