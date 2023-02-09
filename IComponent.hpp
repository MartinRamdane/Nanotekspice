/*
** EPITECH PROJECT, 2023
** IComponent
** File description:
** IComponent
*/

#ifndef ICOMPONENT
    #define ICOMPONENT

#include <iostream>
#include <exception>

namespace nts
{
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    class Error: public std::exception {
        public:
            Error(const std::string msg) : _msg(msg) {};
            ~Error(){};

            const char *what() const noexcept override {return _msg.c_str();};

        private:
            std::string _msg;
    };
    class IComponent {
        public :
            virtual ~IComponent() = default;
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
    };
}

#endif /* !ICOMPONENT */
