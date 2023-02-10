/*
** EPITECH PROJECT, 2023
** Circuit.hpp
** File description:
** Circuit
*/

#ifndef CIRCUIT
    #define CIRCUIT

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <algorithm>
#include <exception>
#include "IComponent.hpp"
#include "special_component/FalseComponent.hpp"
#include "special_component/TrueComponent.hpp"
#include "elementary_component/AndComponent.hpp"
#include "elementary_component/OrComponent.hpp"
#include "elementary_component/XorComponent.hpp"
#include "elementary_component/NorComponent.hpp"
#include "elementary_component/NandComponent.hpp"
#include "special_component/InputComponent.hpp"
#include "special_component/OutputComponent.hpp"
#include "elementary_component/NotComponent.hpp"
#include "special_component/ClockComponent.hpp"
#include "elementary_component/XorComponent.hpp"
#include "gates_component/FourTComponent.hpp"
#include "gates_component/4069Component.hpp"
#include "advanced_components/4008Component.hpp"
#include "advanced_components/LoggerComponent.hpp"

namespace nts
{
    class Circuit: public AComponent {
        public:
            class Error: public std::exception {
                public:
                    Error(const std::string msg) : _msg(msg) {};
                    ~Error(){};

                    const char *what() const noexcept override {return _msg.c_str();};
                private:
                    std::string _msg;
            };

            Circuit(size_t nbPins = 2);
            ~Circuit();

            void createLink(std::string source, std::string target);
            void display();
            void assignValue(const std::string name, nts::Tristate value);
            void simulate();
            void mainLoop();
            void loop();
            nts::Tristate compute(std::size_t pin);
            std::unique_ptr<nts::IComponent> createComponent(const std::string &type, size_t pin, std::string name);
            void setChipsetsMap(std::string key, const std::string type, size_t pin);

        private:
            std::map<std::string, std::unique_ptr<nts::IComponent>> chipsets;
            std::map<std::string, nts::Tristate> inputs;
            std::map<std::string, size_t> inputsSorted;
            std::map<std::string, size_t> outputsSorted;
            static std::map<std::string, std::function<std::unique_ptr<IComponent>()>> dico;
            int tick;
    };
}

std::ostream &operator<<( std :: ostream & s , nts :: Tristate v );

#endif /* !CIRCUIT */
