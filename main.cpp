#include <iostream>
#include <memory>
#include "FalseComponent.hpp"
#include "TrueComponent.hpp"
#include "NotComponent.hpp"
#include "AndComponent.hpp"
#include "InputComponent.hpp"
#include "Graph.hpp"

int main(int ac, char **av)
{
    if (ac > 1)
        Graph graph(av[1]);
}
