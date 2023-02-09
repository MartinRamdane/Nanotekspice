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

            // void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            nts::Tristate compute(std::size_t pin);
            int TristateToInt(nts::Tristate value);

        private:
            // std::vector<std::unique_ptr<nts::OutpoutComponent>> outputs;
    };
}

#endif /* !LOGGER_COMPONENT */
