#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

#include "../include/read.hpp"
#include "../include/populacao.hpp"
#include "../include/fitness.hpp"
#include "../include/operacoes.hpp"

int main()
{
    std::cout << "Executando algoritmo genetico...\n";

    // semente fixa para reproduzir resultados
    srand(42);

    EntradadaDados input = LerArquivo("data/input.dat");

    int populationSize = input.tamanhoPopulacao;
    int generations = input.geracoes;

    std::vector<Pontos> data = input.data;

    std::vector<double> dataX;
    std::vector<double> dataY;

    for(const auto& ponto : data)
    {
        dataX.push_back(ponto.x);
        dataY.push_back(ponto.y);
    }

    std::vector<Individuo> pop;
    gerarPopulacao(pop, populationSize, -50, 50, -50, 50);

    double cutRate = 0.4;
    double mutationRate = 0.05;

    for(int gen = 0; gen < generations; gen++)
    {
        AvaliarPopulacao(pop, dataX, dataY);

        std::sort(pop.begin(), pop.end(),
        [](const Individuo& a, const Individuo& b)
        {
            return a.Fitness > b.Fitness;
        });

        int eliteSize = pop.size() * cutRate;

        if(eliteSize < 2)
            eliteSize = 2;

        for(int i = 0; i < eliteSize; i++)
        {
            SalvarDados(
                "output/output.dat",
                gen,
                pop[i].a,
                pop[i].b,
                pop[i].Fitness
            );
        }

        for(int i = 0; i < populationSize / 2; i++)
        {
            // selecionar pais
            Individuo p1 = selecionarPais(pop, cutRate);
            Individuo p2 = selecionarPais(pop, cutRate);

            // crossover
            auto children = crossover(p1, p2);

            // mutação
            mutacao(children[0], mutationRate);
            mutacao(children[1], mutationRate);

            // avaliar filhos
            children[0].Fitness = calcularFitness(children[0], dataX, dataY);
            children[1].Fitness = calcularFitness(children[1], dataX, dataY);

            // substituir piores
            SubsPior(pop, children[0]);
            SubsPior(pop, children[1]);
        }
    }

    // avaliação final
    AvaliarPopulacao(pop, dataX, dataY);

    Individuo best = MelhorIndividuo(pop);

    std::cout << "\nMelhor solucao encontrada:\n";
    std::cout << "y = " << best.a << "x + " << best.b << std::endl;
    std::cout << "fitness = " << best.Fitness << std::endl;

    return 0;
}