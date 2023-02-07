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
#include "IComponent.hpp"
#include "FalseComponent.hpp"
#include "TrueComponent.hpp"
#include "AndComponent.hpp"
#include "InputComponent.hpp"
#include "OutputComponent.hpp"
#include "NotComponent.hpp"
#include "ClockComponent.hpp"
#include "XorComponent.hpp"
#include "4081Component.hpp"
#include "4071Component.hpp"
#include "4001Component.hpp"
#include "4011Component.hpp"
#include "4030Component.hpp"
#include "4069Component.hpp"


class Circuit {
    public:
        Circuit(const std::string filename);
        ~Circuit();

        void parseFile(const std::string filename);
        void createLink(std::string source, std::string target);
        void display();
        void assignValue(); // only for input and clocks
        void simulate();
        void mainLoop();
        void loop();
        std::unique_ptr<nts::IComponent> createComponent(const std::string &type);

    private:
        std::map<std::string, std::unique_ptr<nts::IComponent>> chipsets;
        std::map<std::string, nts::Tristate> inputs;
        std::vector<std::string> inputsSorted;
        std::vector<std::string> outputsSorted;
        int tick;
};

std::ostream &operator<<( std :: ostream & s , nts :: Tristate v );

#endif /* !CIRCUIT */
