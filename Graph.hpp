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

    private:
        std::map<std::string, std::string> chipsets;
        int tick;
};

#endif /* !GRAPH */
