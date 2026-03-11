#include "../include/individuo.hpp"
#include <iostream>

void printIndividual(const Individuo& ind)
{
    std::cout << "a: " << ind.a
              << " b: " << ind.b
              << " fitness: " << ind.Fitness
              << std::endl;
}