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
#include "Circuit.hpp"

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

        void parseFile(Circuit &circuit);

    protected:
    private:
        std::string _filename;
};

#endif /* !PARSER */
