/*
** EPITECH PROJECT, 2023
** Graph.hpp
** File description:
** Graph
*/

#ifndef GRAPH
    #define GRAPH

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "IComponent.hpp"
#include "FalseComponent.hpp"
#include "TrueComponent.hpp"
#include "AndComponent.hpp"
#include "InputComponent.hpp"
#include "OutputComponent.hpp"
#include "NotComponent.hpp"
#include "ClockComponent.hpp"
#include "XorComponent.hpp"

class Graph {
    public:
        Graph(const std::string filename);
        ~Graph();

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
        int tick;
};

std::ostream &operator<<( std :: ostream & s , nts :: Tristate v );

#endif /* !GRAPH */
