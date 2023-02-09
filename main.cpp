#include "Circuit.hpp"
#include "Parser.hpp"

int main(int ac, char **av)
{
    if (ac > 1) {
        Circuit circuit = Circuit();
        Parser parser(av[1]);
        parser.parseFile(circuit);
        circuit.mainLoop();
    }
}
