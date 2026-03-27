#include "../include/populacao.hpp"
#include "../include/fitness.hpp"

#include <algorithm>
#include <cstdlib>
#include <iostream>

void gerarPopulacao(std::vector <Individuo>& populacao, int tamanhoPopulacao, double menorA,
double maiorA, double menorB, double maiorB){
    populacao.resize(tamanhoPopulacao);
    for(int i = 0; i < tamanhoPopulacao; i++){
        Individuo &Individuo = populacao[i];
        Individuo.a = menorA + (double)rand() / RAND_MAX * (maiorA - menorA);
        Individuo.b = menorB + (double)rand() / RAND_MAX * (maiorB - menorB);
        Individuo.Fitness = 0.0;
    }
}

void AvaliarPopulacao(std::vector <Individuo>& populacao, const std::vector<double>& x, 
const std::vector<double>& y){
    for (Individuo& individuo : populacao){
        individuo.Fitness = calcularFitness(individuo, x, y);
    }
}

Individuo MelhorIndividuo(const std::vector <Individuo>& populacao){
    return *std::max_element(
        populacao.begin(), populacao.end(), [](const Individuo& a, const Individuo& b){
        return a.Fitness < b.Fitness;
    });
}
Individuo SegundoMelhorIndividuo(const std::vector<Individuo>& populacao){
    std::vector<Individuo> OrdenarPop = populacao;
    std::sort(OrdenarPop.begin(), OrdenarPop.end(), [](const Individuo& a, const Individuo& b){
        return a.Fitness > b.Fitness;
    });
    return OrdenarPop[1];
}
int PiorIndividuo(const std::vector <Individuo>& populacao){
    int pior = 0;
    for (int i = 1; i < (int)populacao.size(); i++){
        if (populacao[i].Fitness < populacao[pior].Fitness){
            pior = i;
        }
    }
    return pior;
}
void SubsPior(std::vector <Individuo>& populacao, const Individuo& individuo){
    int pior = PiorIndividuo(populacao);
    populacao[pior] = individuo;
}

void calcularIntervalos(const std::vector<double>& dataX,
                        const std::vector<double>& dataY,
                        double& minA, double& maxA,
                        double& minB, double& maxB)
{

    double minX = *std::min_element(dataX.begin(), dataX.end());
    double maxX = *std::max_element(dataX.begin(), dataX.end());

    double minY = *std::min_element(dataY.begin(), dataY.end());
    double maxY = *std::max_element(dataY.begin(), dataY.end());

    double rangeX = maxX - minX;
    double rangeY = maxY - minY;

    if (rangeX == 0)
    {
        std::cerr << "Erro: todos os X iguais!\n";
        rangeX = 1;
    }

    minA = -(rangeY / rangeX);
    maxA =  (rangeY / rangeX);

    minB = minY;
    maxB = maxY;

    double margem = 1.5;

    minA *= margem;
    maxA *= margem;
    minB *= margem;
    maxB *= margem;
}