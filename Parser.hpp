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
#include "Circuit.hpp"

class Parser {
    public:
        Parser(const std::string filename);
        ~Parser();

        void parseFile(Circuit &circuit);

    protected:
    private:
        std::string _filename;
};

#endif /* !PARSER */
