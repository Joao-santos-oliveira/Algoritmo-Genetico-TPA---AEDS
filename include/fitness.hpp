#ifndef FITNESS_HPP
#define FITNESS_HPP

#include <vector>
#include "individuo.hpp"

double calcularFitness(const Individuo& individuo, const std::vector<double>& x, const std::vector<double>& y);

#endif