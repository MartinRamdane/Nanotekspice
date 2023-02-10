#include "Circuit.hpp"
#include "Parser.hpp"

int main(int ac, char **av)
{
    if (ac > 1) {
        Parser parser(av[1]);
        try {
            parser.parseFile();
            nts::Circuit circuit(parser.getNbPins());
            parser.createCircuit(circuit);
            circuit.mainLoop();
        } catch(std::exception &e) {
            std::cout << e.what() << std::endl;
            return 84;
        }
    }
    return 0;
}
