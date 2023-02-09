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
    if (!file.is_open())
        throw Error("Error to open " + _filename + " file.");
    if (file.peek() == std::ifstream::traits_type::eof())
        throw Error("Empty file");
    std::string line;
    bool chip = false;
    bool link = false;
    bool hasLinks = false;
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
            if (tab.size() > 2)
                throw Error("Invalid informations on Chipset.");
            circuit.setChipsetsMap(tab[1], tab[0]);
            if (tab[0] == "input" || tab[0] == "clock")
                circuit.setInputsList(tab[1]);
            if (tab[0] == "output")
               circuit.setOutputsList(tab[1]);
        }
        if (link) {
            hasLinks = true;
            if (tab.size() > 2)
                throw Error("Invalid informations on links.");
            circuit.createLink(tab[0], tab[1]);
        }
        if (tab[0] == ".chipsets:") {
            chip = true;
            link = false;
        }
        if (tab[0] == ".links:") {
            link = true;
            chip = false;
        }
    }
    if (!hasLinks)
        throw Error("There are no links.");
    if (circuit.getChipsetsMapSize() == 0)
        throw Error("No chipsets in the circuit.");
}