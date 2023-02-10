/*
** EPITECH PROJECT, 2023
** Circuit.cpp
** File description:
** Circuit.hpp
*/

#include "Circuit.hpp"

using namespace nts;

Circuit::Circuit(size_t nbPins) : AComponent(nbPins)
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
                std::cout << "> ";
                continue;
            }
            inputIsFind = false;
            std::string val = input.substr(target.size() + 1);
            val.erase(std::remove_if(val.begin(), val.end(), ::isspace), val.end());
            if (val != "0" && val != "1" && val != "U") {
                std::cout << "> ";
                continue;
            }
            nts::Tristate value = val == "U" ? nts::Undefined : (stoi(val) == 0 ? nts::False : nts::True);
            assignValue(target, value);
        }
        else if (input == "exit")
            break;
        std::cout << "> ";
    }
}

nts::Tristate Circuit::compute(std::size_t pin)
{
    for (auto itInputs = inputsSorted.begin() ; itInputs != inputsSorted.end() ; ++itInputs) {
        if (itInputs->second == pin) {
            return chipsets[itInputs->first]->compute(1);
        }
    }
    for (auto itOutputs = outputsSorted.begin() ; itOutputs != outputsSorted.end() ; ++itOutputs) {
        if (itOutputs->second == pin) {
            return chipsets[itOutputs->first]->compute(1);
        }
    }
    return Undefined;
}

void Circuit::display()
{
    std::cout << "tick: " << tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto itInputs = inputsSorted.begin() ; itInputs != inputsSorted.end() ; ++itInputs)
        std::cout << "  " << (itInputs->first) << ": " << compute(itInputs->second) << std::endl;
    std::cout << "output(s):" << std::endl;
    for (auto itOutputs = outputsSorted.begin() ; itOutputs != outputsSorted.end() ; ++itOutputs)
        std::cout << "  " << (itOutputs->first) << ": " << compute(itOutputs->second) << std::endl;
}

void Circuit::setChipsetsMap(std::string key, const std::string type, size_t pin)
{
    for (auto it = chipsets.begin() ; it != chipsets.end(); ++it) {
        if (it->first == key)
            throw Error("Same component name.");
    }
    chipsets[key] = createComponent(type, pin, key);
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
    int targetPin = stoi(target.substr(targetName.size() + 1));
    int srcPin = stoi(source.substr(srcName.size() + 1));
    if (inputsSorted.find(srcName) != inputsSorted.end()) {
        setLink(inputsSorted[srcName], *(chipsets[targetName]), targetPin);
        chipsets[targetName]->setLink(targetPin, *this, inputsSorted[srcName]);
    } else if (inputsSorted.find(targetName) != inputsSorted.end()) {
        setLink(inputsSorted[targetName], *(chipsets[srcName]), srcPin);
        chipsets[srcName]->setLink(srcPin, *this, inputsSorted[targetName]);
    }
    if (outputsSorted.find(srcName) != outputsSorted.end()) {
        setLink(outputsSorted[srcName], *(chipsets[targetName]), targetPin);
        chipsets[targetName]->setLink(targetPin, *this, outputsSorted[srcName]);
    } else if (outputsSorted.find(targetName) != outputsSorted.end()) {
        setLink(outputsSorted[targetName], *(chipsets[srcName]), srcPin);
        chipsets[srcName]->setLink(srcPin, *this, outputsSorted[targetName]);
    }
    chipsets[targetName]->setLink(targetPin, *(chipsets[srcName].get()), srcPin);
    chipsets[srcName]->setLink(srcPin, *(chipsets[targetName]), targetPin);
}

std::unique_ptr<nts::IComponent> Circuit::createComponent(const std::string &type, size_t pin, std::string name)
{
    if (type.find(":") != std::string::npos)
        throw Error(".links is misplaced or not exists.");
    if (dico.find(type) == dico.end())
        throw Error("Unknown component.");
    if (type == "input")
        inputsSorted[name] = pin;
    if (type == "output")
        outputsSorted[name] = pin;
    if (type == "clock")
        inputsSorted[name] = pin;
    return dico[type]();
}

void Circuit::assignValue(const std::string name, nts::Tristate value)
{
    nts::InputComponent *input = dynamic_cast<nts::InputComponent *>(chipsets[name].get());
    nts::ClockComponent *clock = dynamic_cast<nts::ClockComponent *>(chipsets[name].get());
    if (input)
        input->changeValue(value);
    else if (clock)
        clock->changeValue(value);
}

void Circuit::simulate()
{
    tick += 1;
    for (auto it = chipsets.begin() ; it != chipsets.end(); ++it)
        (it->second)->simulate(tick);
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

std::map<std::string, std::function<std::unique_ptr<IComponent>()>> Circuit::dico = {
    { "false", [](){ return (std::make_unique<nts::FalseComponent>());}},
    { "true", [](){ return (std::make_unique<nts::TrueComponent>());}},
    { "and", [](){ return (std::make_unique<nts::AndComponent>());}},
    { "not", [](){ return (std::make_unique<nts::NotComponent>());}},
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
    { "logger", [](){ return (std::make_unique<nts::LoggerComponent>());}}
};