/*
** EPITECH PROJECT, 2023
** Graph.cpp
** File description:
** Graph.hpp
*/

#include "Graph.hpp"

std::ostream &operator<<( std :: ostream & s , nts :: Tristate v )
{
    s << (v != nts::Undefined ? (v == nts::True ? 1 : 0) : 'U');
    return s;
}

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
        // std::cout << "value :" << (it->second)->compute(1) << std::endl;
        // add test if is input
        if ((it->first) == "i1" || (it->first) == "i2" )
            std::cout << "  " << (it->first) << ": " << (it->second)->compute(1) << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (auto it = chipsets.begin() ; it != chipsets.end() ; ++it) {
        // add test if is output
       // std::cout << it->first << ": " << (it->second)->compute() << std::endl;
        if ((it->first) == "no")
            std::cout << "  " <<  "result: " << (it->second)->compute(2) << std::endl;
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
            chipsets[tab[1]] = createComponent(tab[0]);
        if (link)
            createLink(tab[0], tab[1]);
        if (tab[0] == ".chipsets:") {
            chip = true; link = false;
        }
        if (tab[0] == ".links:") {
            link = true;
            chip = false;
        }
    }
    // for(auto it = chipsets.begin() ; it != chipsets.end() ; ++it) {
    //     std::cout << "key: " << it->first << " ";
    //     std::cout << "value :" << it->second << std::endl;
    // }
}

void Graph::createLink(std::string source, std::string target)
{
    std::string srcName = source.substr(0, source.find(":"));
    int srcPin = stoi(source.substr(srcName.size() + 1));
    std::string targetName = target.substr(0, target.find(":"));
    int targetPin = stoi(target.substr(targetName.size() + 1));
    chipsets[targetName]->setLink(targetPin, *(chipsets[srcName].get()), srcPin);
}

std::unique_ptr<nts::IComponent> Graph::createComponent(const std::string &type)
{
    if (type == "false")
        return (std::make_unique<nts::FalseComponent>());
    if (type == "true")
        return (std::make_unique<nts::TrueComponent>());
    if (type == "and")
        return (std::make_unique<nts::AndComponent>());
    if (type == "not")
        return (std::make_unique<nts::NotComponent>());
    return nullptr;
}