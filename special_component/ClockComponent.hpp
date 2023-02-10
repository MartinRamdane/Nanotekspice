/*
** EPITECH PROJECT, 2023
** Clock.hpp
** File description:
** Clock
*/

#ifndef CLOCK
    #define CLOCK

#include "../AComponent.hpp"
namespace nts {
    class ClockComponent : public AComponent {
        public:
            ClockComponent();
            ~ClockComponent();

            nts::Tristate compute(std::size_t pin) {return valueOutput[pin - 1];};
            void changeValue(nts::Tristate value = Undefined);
            void simulate(std::size_t tick) override;

        protected:
        private:
            Tristate valueOutput[1];
            Tristate nextValue;
            bool haveToAssign;
    };
}

#endif /* !CLOCK */
