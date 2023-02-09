/*
** EPITECH PROJECT, 2023
** FourTComponent.hpp
** File description:
** FourTComponent
*/

#ifndef FOUR_T_COMPONENT
    #define FOUR_T_COMPONENT

#include "../AComponent.hpp"
#include <iostream>
#include <memory>

namespace nts
{
    template<typename T>
    class FourTComponent: public nts::AComponent {
        public:
            FourTComponent() : AComponent(14) {
                components.push_back(T());
                components.push_back(T());
                components.push_back(T());
                components.push_back(T());
            };
            ~FourTComponent() {components.clear();};

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override {
                if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
                    switch (pin) {
                        case 3: components[0].setLink(3, other, otherPin); break;
                        case 4: components[1].setLink(3, other, otherPin);break;
                        case 10: components[2].setLink(3, other, otherPin);break;
                        case 11: components[3].setLink(3, other, otherPin);break;
                    }
                }
                if (pin == 1 || pin == 5 || pin == 8 || pin == 12) {
                    switch (pin) {
                        case 1: components[0].setLink(1, other, otherPin); break;
                        case 5: components[1].setLink(1, other, otherPin);break;
                        case 8: components[2].setLink(1, other, otherPin);break;
                        case 12: components[3].setLink(1, other, otherPin);break;
                    }
                }
                if (pin == 2 || pin == 6 || pin == 9 || pin == 13) {
                    switch (pin) {
                        case 2: components[0].setLink(2, other, otherPin); break;
                        case 6: components[1].setLink(2, other, otherPin);break;
                        case 9: components[2].setLink(2, other, otherPin);break;
                        case 13: components[3].setLink(2, other, otherPin);break;
                    }
                }
            };
            nts::Tristate compute(std::size_t pin) {
                if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
                    switch (pin) {
                        case 3: return components[0].compute(3);
                        case 4: return components[1].compute(3);
                        case 10: return components[2].compute(3);
                        case 11: return components[3].compute(3);
                    }
                }
                if (pin == 1 || pin == 5 || pin == 8 || pin == 12) {
                    switch (pin) {
                        case 1: return components[0].compute(1);
                        case 5: return components[1].compute(1);
                        case 8: return components[2].compute(1);
                        case 12: return components[3].compute(1);
                    }
                }
                if (pin == 2 || pin == 6 || pin == 9 || pin == 13) {
                    switch (pin) {
                        case 2: return components[0].compute(2);
                        case 6: return components[1].compute(2);
                        case 9: return components[2].compute(2);
                        case 13: return components[3].compute(2);
                    }
                }
                return nts::Undefined;
            };
        private:
            std::vector<T> components;
    };
}

#endif /* !FOUR_T_COMPONENT */
