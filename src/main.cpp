#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <chrono>

#include "../include/read.hpp"
#include "../include/populacao.hpp"
#include "../include/fitness.hpp"
#include "../include/operacoes.hpp"

int main()
{
    auto inicio = std::chrono::steady_clock::now();
    std::string outputFile = NomeOutput();
    std::cout << "Salvando em: " << outputFile << "\n";
    // INICIALIZAÇÃO
    std::cout << "Executando algoritmo genetico...\n";

    // semente fixa para reproduzir resultados
    srand(42);


    // LEITURA DE DADOS
    EntradadaDados input = LerArquivo("data/input.dat");

    int populationSize = input.tamanhoPopulacao;
    int generations = input.geracoes;

    std::vector<Pontos> data = input.data;


    // PRÉ-PROCESSAMENTO
    std::vector<double> dataX;
    std::vector<double> dataY;
    
    

    for (const auto& ponto : data)
    {
        dataX.push_back(ponto.x);
        dataY.push_back(ponto.y);
    }


    // INICIALIZAÇÃO DA POPULAÇÃO
    double minA, maxA, minB, maxB;
    calcularIntervalos(dataX, dataY, minA, maxA, minB, maxB);
    std::vector<Individuo> pop;
    gerarPopulacao(pop, populationSize, minA, maxA, minB, maxB);

    double cutRate = 0.4;
    double mutationRate = 0.05;


    // LOOP PRINCIPAL (AG)
    for(int gen = 0; gen < generations; gen++)
    {
        // Avaliação 
        AvaliarPopulacao(pop, dataX, dataY);


        // Ordenação por fitness
        std::sort(pop.begin(), pop.end(),
        [](const Individuo& a, const Individuo& b)
        {
            return a.Fitness > b.Fitness;
        });


        // Elitismo 
        int eliteSize = pop.size() * cutRate;

        if(eliteSize < 2)
            eliteSize = 2;

        for(int i = 0; i < eliteSize; i++)
        {
            SalvarDados(
                outputFile,
                gen,
                pop[i].a,
                pop[i].b,
                pop[i].Fitness
            );
        }


        // -------- Reprodução --------
        for(int i = 0; i < populationSize / 2; i++)
        {
            // seleção de pais
            Individuo p1 = selecionarPais(pop, cutRate);
            Individuo p2 = selecionarPais(pop, cutRate);

            // crossover
            auto children = crossover(p1, p2);

            // mutação
            mutacao(children[0], mutationRate);
            mutacao(children[1], mutationRate);

            // avaliação dos filhos
            children[0].Fitness = calcularFitness(children[0], dataX, dataY);
            children[1].Fitness = calcularFitness(children[1], dataX, dataY);

            // substituição
            SubsPior(pop, children[0]);
            SubsPior(pop, children[1]);
        }
    }

    auto fim = std::chrono::steady_clock::now();
    auto duracao = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
    AvaliarPopulacao(pop, dataX, dataY);

    Individuo best = MelhorIndividuo(pop);

    std::cout << "\nMelhor solucao encontrada:\n";
    std::cout << "y = " << best.a << "x + " << best.b << std::endl;
    std::cout << "fitness = " << best.Fitness << std::endl;
    std::cout << "Tempo de execucao: " << duracao.count() << " ms" << std::endl;


    return 0;
}