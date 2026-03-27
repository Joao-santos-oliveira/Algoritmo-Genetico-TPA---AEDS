#ifndef POPULACAO_HPP
#define POPULACAO_HPP

#include <vector>
#include "individuo.hpp"

void gerarPopulacao(std::vector <Individuo>& populacao, int tamanhoPopulacao, double menorA,
double maiorA, double menorB, double maiorB);

void AvaliarPopulacao( std::vector <Individuo>& populacao, const std::vector<double>& x, 
const std::vector<double>& y);

Individuo MelhorIndividuo(const std::vector <Individuo>& populacao);
Individuo SegundoMelhorIndividuo(const std::vector <Individuo>& populacao);
int PiorIndividuo(const std::vector <Individuo>& populacao);
void SubsPior(std::vector <Individuo>& populacao, const Individuo& individuo);
void calcularIntervalos(const std::vector<double>& dataX,const std::vector<double>& dataY,double& minA, double& maxA,double& minB, double& maxB);

#endif 