/*
** EPITECH PROJECT, 2023
** Graph.cpp
** File description:
** Graph.hpp
*/

#include "Graph.hpp"

Graph::Graph(const std::string filename)
{
    tick = 0;
    parseFile(filename);
    mainLoop();
}

Graph::~Graph()
{
}

void Graph::mainLoop()
{
    std::string input;
    std::cout << "> ";
    while (std::getline (std::cin, input)) {
        if (input == "display")
            display();
        if (input == "simulate")
            simulate();
        if (input == "exit")
            break;
        std::cout << "> ";
    }
}

void Graph::display()
{
    std::cout << "tick: " << tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto it = chipsets.begin() ; it != chipsets.end() ; ++it) {
        // add test if is input
       // std::cout << it->first << ": " << (it->second).compute() << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (auto it = chipsets.begin() ; it != chipsets.end() ; ++it) {
        // add test if is output
       // std::cout << it->first << ": " << (it->second).compute() << std::endl;
    }
}

void Graph::parseFile(const std::string filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cout << "erro opening file" << std::endl;
        return;
    }
    std::string line;
    bool chip = false;
    bool link = false;
    while(getline(file, line)) {
        if (line.size() == 0)
            continue;
        if (line.c_str()[0] == '#')
            continue;
        std::istringstream iss(line);
        std::string word;
        std::vector<std::string> tab;
        while(iss >> word)
            tab.push_back(word);
        if (chip && tab[0] != ".links:")
            chipsets[tab[1]] = tab[0];
        if (link)
            std::cout << "create link" << std::endl;
        if (tab[0] == ".chipsets:") {
            chip = true; link = false;
        }
        if (tab[0] == ".links:") {
            link = true;
            chip = false;
        }
    }
    for(auto it = chipsets.begin() ; it != chipsets.end() ; ++it) {
        std::cout << "key: " << it->first << " ";
        std::cout << "value :" << it->second << std::endl;
    }
}

// void Graph::createLink(std::string source, std::string target)
// {
//     std::string srcName = source.substr(source.find(":"));
//     int srcPin = stoi(source.substr(srcName.size()));
//     std::string targetName = target.substr(target.find(":"));
//     int targetPin = stoi(target.substr(targetName.size()));

//     chipsets[srcName].setLink(srcPin, chipsets[targetName], targetPin);
// }
