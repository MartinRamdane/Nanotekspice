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
#include "IComponent.hpp"
#include "FalseComponent.hpp"
#include "TrueComponent.hpp"
#include "AndComponent.hpp"
#include "NotComponent.hpp"

class Graph {
    public:
        Graph(const std::string filename);
        ~Graph();

        void parseFile(const std::string filename);
        void createLink(std::string source, std::string target);
        void display();
        void assignValue(nts::IComponent &target, nts::Tristate value); // only for input and clocks
        void simulate() {tick += 1;};
        void mainLoop();
        void loop();
        std::unique_ptr<nts::IComponent> createComponent(const std::string &type);

    private:
        std::map<std::string, std::unique_ptr<nts::IComponent>> chipsets;
        int tick;
};

std::ostream &operator<<( std :: ostream & s , nts :: Tristate v );

#endif /* !GRAPH */
