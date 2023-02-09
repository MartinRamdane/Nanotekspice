/*
** EPITECH PROJECT, 2023
** Circuit.cpp
** File description:
** Circuit.hpp
*/

#include "Circuit.hpp"

Circuit::Circuit()
{
    tick = 0;
}

Circuit::~Circuit()
{
}

void Circuit::mainLoop()
{
    std::string input;
    bool inputIsFind = false;
    std::cout << "> ";
    while (std::getline (std::cin, input)) {
        if (input == "display")
            display();
        else if (input == "loop")
            loop();
        else if (input == "simulate")
            simulate();
        else if (input.find("=") != std::string::npos) {
            std::string target = input.substr(0, input.find("="));
            for (auto it = chipsets.begin() ; it != chipsets.end() ; ++it) {
                nts::InputComponent *castInput = dynamic_cast<nts::InputComponent *>(chipsets[it->first].get());
                nts::ClockComponent *castclock = dynamic_cast<nts::ClockComponent *>(chipsets[it->first].get());
                if ((castInput || castclock) && it->first == target)
                    inputIsFind = true;
            }
            if (!inputIsFind) {
                std::cout << ("Invalid value: " + target + " does not exist.") << std::endl;
                std::cout << "> ";
                continue;
            }
            inputIsFind = false;
            std::string val = input.substr(target.size() + 1);
            val.erase(std::remove_if(val.begin(), val.end(), ::isspace), val.end());
            if (val != "0" && val != "1" && val != "U") {
                std::cout << ("Invalid value: " + val + " on " + target + " component.") << std::endl;
                std::cout << "> ";
                continue;
            }
            nts::Tristate value = val == "U" ? nts::Undefined : (stoi(val) == 0 ? nts::False : nts::True);
            inputs[target] = value;
        }
        else if (input == "exit")
            break;
        else
            std::cout << "Invalid command." << std::endl;
        std::cout << "> ";
    }
}

void Circuit::display()
{
    std::cout << "tick: " << tick << std::endl;
    std::cout << "input(s):" << std::endl;
    std::sort(inputsSorted.begin(), inputsSorted.end(), [](std::string a, std::string b) {return a<b;});
    for (auto itInputs = inputsSorted.begin() ; itInputs != inputsSorted.end() ; ++itInputs)
        std::cout << "  " << *(itInputs) << ": " << chipsets[*itInputs]->compute(1) << std::endl;
    std::cout << "output(s):" << std::endl;
    std::sort(outputsSorted.begin(), outputsSorted.end(), [](std::string a, std::string b) {return a<b;});
    for (auto itOutputs = outputsSorted.begin() ; itOutputs != outputsSorted.end() ; ++itOutputs)
        std::cout << "  " << *(itOutputs) << ": " << chipsets[*itOutputs]->compute(1) << std::endl;
}

void Circuit::setChipsetsMap(std::string key, const std::string type)
{
    for (auto it = chipsets.begin() ; it != chipsets.end(); ++it) {
        if (it->first == key)
            throw Error("Same component name.");
    }
    chipsets[key] = createComponent(type);
}

void Circuit::setInputsList(std::string value)
{
    inputsSorted.push_back(value);
}

void Circuit::setOutputsList(std::string value)
{
    outputsSorted.push_back(value);
}


void Circuit::createLink(std::string source, std::string target)
{
    bool srcNameExists = false;
    bool targetNameExists = false;
    std::string srcName = source.substr(0, source.find(":"));
    std::string targetName = target.substr(0, target.find(":"));
    for (auto it = chipsets.begin() ; it != chipsets.end(); ++it) {
        if (it->first == srcName)
            srcNameExists = true;
        if (it->first == targetName)
            targetNameExists = true;
    }
    if (!srcNameExists)
        throw Error("Can\'t link component " + srcName + ": does not exist.");
    if (!targetNameExists)
        throw Error("Can\'t link component " + targetName + ": does not exist.");
    int srcPin = stoi(source.substr(srcName.size() + 1));
    int targetPin = stoi(target.substr(targetName.size() + 1));
    chipsets[targetName]->setLink(targetPin, *(chipsets[srcName].get()), srcPin);
    chipsets[srcName]->setLink(srcPin, *(chipsets[targetName]), targetPin);
}

std::unique_ptr<nts::IComponent> Circuit::createComponent(const std::string &type)
{
    if (type.find(":") != std::string::npos)
        throw Error(".links is misplaced or not exists.");
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
    if (type == "4008")
        return (std::make_unique<nts::FourAdderComponent>());
    if (type == "logger")
        return (std::make_unique<nts::LoggerComponent>());
    throw Error("Type " + type + " is not defined.");
}

void Circuit::assignValue()
{
    for (auto it = inputs.begin() ; it != inputs.end() ; ++it) {
        nts::InputComponent *input = dynamic_cast<nts::InputComponent *>(chipsets[it->first].get());
        nts::ClockComponent *clock = dynamic_cast<nts::ClockComponent *>(chipsets[it->first].get());
        if (input)
            input->changeValue(it->second);
        else if (clock)
            clock->changeValue(it->second);
    }
}

void Circuit::simulate()
{
    tick += 1;
    assignValue();
    for (auto it = chipsets.begin() ; it != chipsets.end(); ++it) {
        nts::ClockComponent *clock = dynamic_cast<nts::ClockComponent *>(chipsets[it->first].get());
        nts::LoggerComponent *logger = dynamic_cast<nts::LoggerComponent *>(chipsets[it->first].get());
        if (logger)
            (it->second)->compute(1);
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