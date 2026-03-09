#ifndef OPERACOES_HPP
#define OPERACOES_HPP

#include "individuo.hpp"

void mutacao(Individuo& individuo, double taxaMutacao);
Individuo crossover(const Individuo& pai1, const Individuo& pai2);

#endif