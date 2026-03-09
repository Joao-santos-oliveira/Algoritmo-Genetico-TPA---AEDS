#include "../include/populacao.hpp"
#include "../include/fitness.hpp"

#include <algorithm>
#include <cstdlib>

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
    for (int i = 1; i < populacao.size(); i++){
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