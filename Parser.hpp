/*
** EPITECH PROJECT, 2023
** Parser.hpp
** File description:
** Parser
*/

#ifndef PARSER
    #define PARSER

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <exception>
#include <cstring>
#include <algorithm>
#include <cctype>
#include "Circuit.hpp"
#include "IComponent.hpp"

class Parser {
    public:
        class Error: public std::exception {
            public:
                Error(const std::string msg) : _msg(msg) {};
                ~Error(){};

                const char *what() const noexcept override {return _msg.c_str();};

            private:
                std::string _msg;
        };
        Parser(const std::string filename);
        ~Parser();
        void parseFile();
        size_t getNbPins() const {return _nbPins;};
        void createCircuit(nts::Circuit &circuit);
        void setLinks(nts::Circuit &circuit);
        std::unique_ptr<nts::IComponent> createComponent(const std::string &type);
        bool checkSpaces(const char *str);
        std::string checkComment(std::string str);

    private:
        std::string _filename;
        size_t _nbPins = 2;
        static std::map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> dico;
        std::vector<std::vector<std::string>> _chipsets;
        std::vector<std::vector<std::string>> _links;
};

#endif /* !PARSER */
