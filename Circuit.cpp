/*
** EPITECH PROJECT, 2023
** Circuit.cpp
** File description:
** Circuit.hpp
*/

#include "Circuit.hpp"

Circuit::Circuit(const std::string filename)
{
    tick = 0;
    parseFile(filename);
    mainLoop();
}

Circuit::~Circuit()
{
}

void Circuit::mainLoop()
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
            std::string val = input.substr(target.size() + 1);
            nts::Tristate value = val == "U" ? nts::Undefined : (stoi(val) == 0 ? nts::False : nts::True);
            inputs[target] = value;
        }
        if (input == "exit")
            break;
        std::cout << "> ";
    }
}

void Circuit::display()
{
    std::cout << "tick: " << tick << std::endl;
    std::cout << "input(s):" << std::endl;
    std::sort(inputsSorted.begin(), inputsSorted.end(), [](std::string a, std::string b) {return a<b;});
    for (auto itInputs = inputsSorted.begin() ; itInputs != inputsSorted.end() ; ++itInputs) {
        std::cout << "  " << *(itInputs) << ": " << chipsets[*itInputs]->compute(1) << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    std::sort(outputsSorted.begin(), outputsSorted.end(), [](std::string a, std::string b) {return a<b;});
    for (auto itOutputs = outputsSorted.begin() ; itOutputs != outputsSorted.end() ; ++itOutputs) {
        std::cout << "  " << *(itOutputs) << ": " << chipsets[*itOutputs]->compute(1) << std::endl;
    }
}

void Circuit::parseFile(const std::string filename)
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
        if (chip && tab[0] != ".links:") {
            chipsets[tab[1]] = createComponent(tab[0]);
            if (tab[0] == "input" || tab[0] == "clock")
                inputsSorted.push_back(tab[1]);
            if (tab[0] == "output")
                outputsSorted.push_back(tab[1]);
         }
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

void Circuit::createLink(std::string source, std::string target)
{
    std::string srcName = source.substr(0, source.find(":"));
    int srcPin = stoi(source.substr(srcName.size() + 1));
    std::string targetName = target.substr(0, target.find(":"));
    int targetPin = stoi(target.substr(targetName.size() + 1));
    chipsets[targetName]->setLink(targetPin, *(chipsets[srcName].get()), srcPin);
    chipsets[srcName]->setLink(srcPin, *(chipsets[targetName]), targetPin);
}

std::unique_ptr<nts::IComponent> Circuit::createComponent(const std::string &type)
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
    if (type == "4001")
        return (std::make_unique<nts::FourTComponent<nts::NorComponent>>());
    if (type == "4011")
        return (std::make_unique<nts::FourTComponent<nts::NandComponent>>());
    if (type == "4081")
        return (std::make_unique<nts::FourTComponent<nts::AndComponent>>());
    if (type == "4071")
        return (std::make_unique<nts::FourTComponent<nts::OrComponent>>());
    if (type == "4030")
        return (std::make_unique<nts::FourTComponent<nts::XorComponent>>());
    if (type == "4069")
        return (std::make_unique<nts::SixNotComponent>());
    return nullptr;
}

void Circuit::assignValue()
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

void Circuit::simulate()
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

void Circuit::loop() {
    while (stopLoop != 1) {
        signal(SIGINT, checkIfSig);
        simulate();
        display();
    }
}