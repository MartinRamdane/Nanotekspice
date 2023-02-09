/*
** EPITECH PROJECT, 2023
** Parser.cpp
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser(const std::string filename)
{
    _filename = filename;
}

Parser::~Parser()
{
}

void Parser::parseFile(Circuit &circuit)
{
    std::ifstream file(_filename.c_str());
    if (!file.is_open()) {
        std::cout << "error opening file" << std::endl;
        exit(84);
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
        if (chip && tab[0] != ".links:") {
            circuit.setChipsetsMap(tab[1], tab[0]);
            if (tab[0] == "input" || tab[0] == "clock")
                circuit.setInputsList(tab[1]);
            if (tab[0] == "output")
               circuit.setOutputsList(tab[1]);
         }
        if (link)
            circuit.createLink(tab[0], tab[1]);
        if (tab[0] == ".chipsets:") {
            chip = true; link = false;
        }
        if (tab[0] == ".links:") {
            link = true;
            chip = false;
        }
    }
}