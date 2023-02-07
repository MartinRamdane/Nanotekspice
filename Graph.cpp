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
        if (input == "loop")
            loop();
        if (input == "simulate")
            simulate();
        if (input.find("=") != std::string::npos) {
            std::string target = input.substr(0, input.find("="));
            nts::Tristate value = stoi(input.substr(target.size() + 1)) == 0 ? nts::False : nts::True;
            inputs[target] = value;
        }
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
        auto *checkIfInput = dynamic_cast<nts::InputComponent *>((it->second).get());
        auto *checkIfClock = dynamic_cast<nts::ClockComponent *>((it->second).get());
        if (checkIfInput || checkIfClock)
            std::cout << "  " << (it->first) << ": " << (it->second)->compute(1) << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (auto it = chipsets.begin() ; it != chipsets.end() ; ++it) {
        nts::OutpoutComponent *output = dynamic_cast<nts::OutpoutComponent *>((it->second).get());
        if (output)
            std::cout <<  "  " << it->first << ": " << (it->second)->compute(1) << std::endl;
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
    chipsets[srcName]->setLink(srcPin, *(chipsets[targetName]), targetPin);
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
    if (type == "input")
        return (std::make_unique<nts::InputComponent>());
    if (type == "output")
        return (std::make_unique<nts::OutpoutComponent>());
    if (type == "xor")
        return (std::make_unique<nts::XorComponent>());
    if (type == "clock")
        return (std::make_unique<nts::ClockComponent>());
    return nullptr;
}

void Graph::assignValue()
{
    for (auto it = inputs.begin() ; it != inputs.end() ; ++it) {
        nts::InputComponent *input = dynamic_cast<nts::InputComponent *>(chipsets[it->first].get());
        nts::ClockComponent *clock = dynamic_cast<nts::ClockComponent *>(chipsets[it->first].get());
        if (input)
            input->changeValue(it->second);
        else if (clock) {
            clock->changeValue(it->second);
        }
    }
}

void Graph::simulate()
{
    tick += 1;
    assignValue();
    for (auto it = chipsets.begin() ; it != chipsets.end(); ++it) {
        nts::ClockComponent *clock = dynamic_cast<nts::ClockComponent *>(chipsets[it->first].get());
        if (clock) {
            if (inputs.find(it->first) != inputs.end())
                inputs.erase(it->first);
            else
                clock->simulate(tick);
        }
    }
}

volatile sig_atomic_t stopLoop;

void checkIfSig(int signum) {
    if (signum == SIGINT)
        stopLoop = 1;
}

void Graph::loop() {
    while (stopLoop != 1) {
        signal(SIGINT, checkIfSig);
        simulate();
        display();
    }
}