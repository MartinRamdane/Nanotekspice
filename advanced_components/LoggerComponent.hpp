/*
** EPITECH PROJECT, 2023
** LoggerComponent.hpp
** File description:
** LoggerComponent
*/

#ifndef LOGGER_COMPONENT
    #define LOGGER_COMPONENT

#include "../AComponent.hpp"
#include "../special_component/OutputComponent.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

namespace nts {
    class LoggerComponent : public AComponent {
        public:
            LoggerComponent();
            ~LoggerComponent();

            nts::Tristate compute(std::size_t pin);
            int TristateToInt(nts::Tristate value);
    };
}

#endif /* !LOGGER_COMPONENT */
