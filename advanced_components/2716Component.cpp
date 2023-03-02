/*
** EPITECH PROJECT, 2023
** ROM
** File description:
** Rom
*/

#include "2716Component.hpp"

nts::ROM::ROM() : AComponent(24) {
    _charToBin = "Undefined";
    for (std::size_t i=1; i < 16; i++) {
        if (i != 8 && i != 10 && i != 11)
            savedState[i] = nts::Undefined;
    }
}

void nts::ROM::getValueFromBinary() {
    char binary = 0;
    int i = 8;
    int a = 1;
    for (; i > 0; i--, a++) {
        nts::Tristate state = pins[i].targetComp->compute(1);
        binary |= (state == True ? 1 : 0) << (a-1);
    }
    nts::Tristate state = pins[23].targetComp->compute(1);
    binary |= (state == True ? 1 : 0) << (8);
    state = pins[22].targetComp->compute(1);
    binary |= (state == True ? 1 : 0) << (9);
    state = pins[19].targetComp->compute(1);
    binary |= (state == True ? 1 : 0) << (10);
    _charToRead = (int)binary;
}

void nts::ROM::readChar() {
    std::ifstream file("rom.bin");
    file.seekg(_charToRead, std::ios::beg);
    char c;
    file.get(c);
    _charToInt = c;
}

void nts::ROM::charToBin()
{
    std::string binary = "";
    int i = 0;
    int a = 1;
    for (; i < 8; i++, a++) {
        binary += ((_charToInt & (1 << i)) ? "1" : "0");
    }
    _charToBin = binary;
}

void nts::ROM::simulate(std::size_t tick) {
    if (tick != 0 && pins[20].targetComp->compute(1) == True) {
        getValueFromBinary();
        readChar();
    }
    if (tick != 0 && pins[18].targetComp->compute(1) == True) {
        charToBin();
    }
}

void nts::ROM::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin < 1 || pin > 23 || pin == 21 || pin == 12)
        throw Error("Invalid pin on 2716 component.");
    pins[pin].targetPin = otherPin;
    pins[pin].targetComp = &other;
}

nts::Tristate nts::ROM::getPinValue(std::size_t pin)
{
    for (int i = 1; i < 9; i++) {
        if (pins[i].targetComp->compute(1) == nts::Undefined)
            return (nts::Undefined);
    }
    for (int i = 19; i < 24; i++) {
        if (i == 20 || i == 21 )
            continue;
        if (pins[i].targetComp->compute(1) == nts::Undefined)
            return (nts::Undefined);
    }
    if (_charToBin == "Undefined")
        return Undefined;
    switch (pin) {
        case 17:
            return (_charToBin[0] == '1' ? True : False);
        case 16:
            return (_charToBin[1] == '1' ? True : False);
        case 15:
            return (_charToBin[2] == '1' ? True : False);
        case 14:
            return (_charToBin[3] == '1' ? True : False);
        case 13:
            return (_charToBin[4] == '1' ? True : False);
        case 11:
            return (_charToBin[5] == '1' ? True : False);
        case 10:
            return (_charToBin[6] == '1' ? True : False);
        case 9:
            return (_charToBin[7] == '1' ? True : False);
    }
    return (nts::Undefined);
}

nts::Tristate nts::ROM::compute(std::size_t pin)
{
    if (pin < 1 || pin > 23 || pin == 21 || pin == 12)
        throw Error("Invalid pin on 2716 component.");
    if (pin < 9 && pin > 17)
        return (pins[pin].targetComp->compute(pins[pins[pin].targetPin].targetPin));
    if (pin >= 9 && pin <= 17)
        return (getPinValue(pin));
    return (nts::Undefined);
};