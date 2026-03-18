#ifndef OPERACOES_HPP
#define OPERACOES_HPP

#include "individuo.hpp"
#include <vector>

Individuo selecionarPais(const std::vector<Individuo>& pop, double cutRate);
void mutacao(Individuo& individuo, double taxaMutacao);
std::vector<Individuo> crossover(const Individuo& pai1, const Individuo& pai2);

#endif