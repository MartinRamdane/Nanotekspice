/*
** EPITECH PROJECT, 2023
** 2716Component
** File description:
** 2716
*/

#ifndef ROMCOMPONENT
    #define ROMCOMPONENT

#include "../AComponent.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

namespace nts {
    class ROM: public nts::AComponent {
        public:
            ROM();
            ~ROM(){};

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void simulate(std::size_t tick);
            void readChar();
            void getValueFromBinary();
            void charToBin();
            nts::Tristate compute(std::size_t pin);
            nts::Tristate checkTruthTable(std::size_t targetPin);
            nts::Tristate getPinValue(std::size_t targetPin);
        private:
            std::map<std::size_t, nts::Tristate> savedState;
            int _charToRead;
            int _charToInt;
            std::string _charToBin;
    };
}

#endif /* !ROMCOMPONENT */
