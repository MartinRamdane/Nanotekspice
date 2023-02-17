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

bool Parser::checkSpaces(const char *str)
{
    for (size_t i = 0; i < strlen(str); i++) {
        if (!isspace(str[i]))
            return false;
    }
    return true;
}

std::string Parser::checkComment(std::string str)
{
    size_t index = str.find("#");
    if (index != std::string::npos) {
        str = (str.substr(0, index));
        str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
    }
    return str;
}

int Parser::checkErrorOnLine(std::string line)
{
    if (line.size() == 0)
        return 1;
    if (line.c_str()[0] == '#')
        return 1;
    if (checkSpaces(line.c_str()))
        return 1;
    return 0;
}

std::vector<std::string> Parser::getAllWordsOnLine(std::string line)
{
    std::istringstream iss(line);
    std::string word;
    std::vector<std::string> tab;
    while(iss >> word) {
        if (word.find("#") != std::string::npos) {
            word = checkComment(word);
            if (word.size() > 0)
                tab.push_back(word);
            break;
        }
        tab.push_back(word);
    }
    return tab;
}

void Parser::addChipsetsAndLinks(bool chip, bool link, std::vector<std::string> tab)
{
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
}

void Parser::parseFile()
{
    std::ifstream file(_filename.c_str());
    if (!file.is_open())
        throw Error("Error to open " + _filename + " file.");
    if (file.peek() == std::ifstream::traits_type::eof())
        throw Error("Empty file");
    std::string line;
    bool chip = false, link = false;
    while(getline(file, line)) {
        if (checkErrorOnLine(line) == 1)
            continue;
        std::vector<std::string> tab = getAllWordsOnLine(line);
        if (tab.size() < 1)
            continue;
        addChipsetsAndLinks(chip, link, tab);
        if (tab[0] == ".chipsets:") {
            chip = true; link = false;
        }
        if (tab[0] == ".links:") {
            link = true; chip = false;
        }
    }
    if (_links.size() == 0)
        throw Error("There are no links.");
    if (_chipsets.size() == 0)
        throw Error("No chipsets in the circuit.");
}

void Parser::createCircuit(nts::Circuit &circuit)
{
    size_t pin = 1;
    for (auto chipset: _chipsets) {
        circuit.addComponent(chipset[1], createComponent(chipset[0]), pin);
        if (chipset[0] == "input" || chipset[0] == "clock") {
            circuit.setLink(pin, *(circuit.chipsets[chipset[1]].comp.get()), 1);
            pin++;
        }
        if (chipset[0] == "output") {
            circuit.setLink(pin, *(circuit.chipsets[chipset[1]].comp.get()), 1);
            pin++;
        }
    }
    setLinks(circuit);
}

void Parser::setLinks(nts::Circuit &circuit)
{
    for (auto link: _links) {
        bool srcNameExists = false;
        bool targetNameExists = false;
        std::string srcName = link[0].substr(0, link[0].find(":"));
        std::string targetName = link[1].substr(0, link[1].find(":"));
        for (auto it = circuit.chipsets.begin() ; it != circuit.chipsets.end(); ++it) {
            if (it->first == srcName)
                srcNameExists = true;
            if (it->first == targetName)
                targetNameExists = true;
        }
        if (!srcNameExists)
            throw Error("Can\'t link component " + srcName + ": does not exist.");
        if (!targetNameExists)
            throw Error("Can\'t link component " + targetName + ": does not exist.");
        int targetPin = stoi(link[1].substr(targetName.size() + 1));
        int srcPin = stoi(link[0].substr(srcName.size() + 1));
        circuit.chipsets[targetName].comp->setLink(targetPin, *(circuit.chipsets[srcName].comp.get()), srcPin);
        circuit.chipsets[srcName].comp->setLink(srcPin, *(circuit.chipsets[targetName].comp.get()), targetPin);
    }
}

std::unique_ptr<nts::IComponent> Parser::createComponent(const std::string &type)
{
    if (type.find(":") != std::string::npos)
        throw Error(".links is misplaced or not exists.");
    if (dico.find(type) == dico.end())
        throw Error("Unknown component.");
    return dico[type]();
}

std::map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> Parser::dico = {
    { "false", [](){ return (std::make_unique<nts::FalseComponent>());}},
    { "true", [](){ return (std::make_unique<nts::TrueComponent>());}},
    { "and", [](){ return (std::make_unique<nts::AndComponent>());}},
    { "not", [](){ return (std::make_unique<nts::NotComponent>());}},
    { "or", [](){ return (std::make_unique<nts::OrComponent>());}},
    { "xor", [](){ return (std::make_unique<nts::XorComponent>());}},
    { "input", [](){ return (std::make_unique<nts::InputComponent>());}},
    { "output", [](){ return (std::make_unique<nts::OutpoutComponent>());}},
    { "clock", [](){ return (std::make_unique<nts::ClockComponent>());}},
    { "4001", [](){ return (std::make_unique<nts::FourTComponent<nts::NorComponent>>());}},
    { "4011", [](){ return (std::make_unique<nts::FourTComponent<nts::NandComponent>>());}},
    { "4081", [](){ return (std::make_unique<nts::FourTComponent<nts::AndComponent>>());}},
    { "4071", [](){ return (std::make_unique<nts::FourTComponent<nts::OrComponent>>());}},
    { "4030", [](){ return (std::make_unique<nts::FourTComponent<nts::XorComponent>>());}},
    { "4069", [](){ return (std::make_unique<nts::SixNotComponent>());}},
    { "4008", [](){ return (std::make_unique<nts::FourAdderComponent>());}},
    { "4013", [](){ return (std::make_unique<nts::DualDFlipFlopComponent>());}},
    { "4017", [](){ return (std::make_unique<nts::JonhsonCounter>());}},
    { "logger", [](){ return (std::make_unique<nts::LoggerComponent>());}},
    { "4514", [](){ return (std::make_unique<nts::FourBitsDecoder>());}}
};
