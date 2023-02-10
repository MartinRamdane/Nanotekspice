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

void Parser::parseFile()
{
    std::ifstream file(_filename.c_str());
    if (!file.is_open())
        throw Error("Error to open " + _filename + " file.");
    if (file.peek() == std::ifstream::traits_type::eof())
        throw Error("Empty file");
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
            if (tab.size() > 2)
                throw Error("Invalid informations on Chipset.");
            if (tab[0] == "input" || tab[0] == "clock" || tab[0] == "output")
                _nbPins++;
            _chipsets.push_back(tab);
        }
        if (link) {
            if (tab.size() > 2)
                throw Error("Invalid informations on links.");
            _links.push_back(tab);
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
    if (_links.size() == 0)
        throw Error("There are no links.");
    if (_chipsets.size() == 0)
        throw Error("No chipsets in the circuit.");
}

void Parser::createCircuit(nts::Circuit &circuit)
{
    size_t size = 1;
    for (auto chipset: _chipsets) {
        circuit.setChipsetsMap(chipset[1], chipset[0], size);
        if (chipset[0] == "output" || chipset[0] == "input" || chipset[0] == "clock")
            size += 1;
    }
    for (auto link: _links)
        circuit.createLink(link[0], link[1]);
}