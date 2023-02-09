#include "Circuit.hpp"
#include "Parser.hpp"

int main(int ac, char **av)
{
    if (ac > 1) {
        Circuit circuit = Circuit();
        Parser parser(av[1]);
        try {
            parser.parseFile(circuit);
            circuit.mainLoop();
        } catch(std::exception &e) {
            std::cout << e.what() << std::endl;
            return 84;
        }
    }
    return 0;
}
