#ifndef FITNESS_HPP
#define FITNESS_HPP

#include <vector>
#include "individuo.hpp"

double calcularMSE(const Individuo& individuo, const std::vector<double>& x, const std::vector<double>& y);
double calcularFitness(const Individuo& individuo, const std::vector<double>& x, const std::vector<double>& y);

#endif