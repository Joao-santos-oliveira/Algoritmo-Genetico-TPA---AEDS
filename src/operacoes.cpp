#include "../include/operacoes.hpp"
#include <algorithm>
#include <cstdlib>

Individuo selecionarPais(const std::vector<Individuo>& pop, double cutRate)
{
    std::vector<Individuo> temp = pop;

    std::sort(temp.begin(), temp.end(),
        [](const Individuo& a, const Individuo& b)
        {
            return a.Fitness > b.Fitness;
        });

    int eliteSize = temp.size() * cutRate;

    if(eliteSize < 2)
        eliteSize = 2;

    return temp[rand() % eliteSize];
}


std::vector<Individuo> crossover(const Individuo& p1, const Individuo& p2)
{
    Individuo child1;
    Individuo child2;

    child1.a = p1.a;
    child1.b = p2.b;

    child2.a = p2.a;
    child2.b = p1.b;

    child1.Fitness = 0.0;
    child2.Fitness = 0.0;

    return {child1, child2};
}

void mutacao(Individuo& ind, double mutationRate)
{
    if(((double)rand()/RAND_MAX) < mutationRate)
            ind.a += ((double)rand()/RAND_MAX - 0.5);

    if(((double)rand()/RAND_MAX) < mutationRate)
            ind.b += ((double)rand()/RAND_MAX - 0.5);
    }