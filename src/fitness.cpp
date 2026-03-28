#include "../include/fitness.hpp"

double calcularMSE(const Individuo& individuo, const std::vector<double>& x, const std::vector<double>& y)
{
    double mse = 0.0;
    int n = x.size();

      for (int i = 0; i < n; i++){
        double y_previsto = individuo.a * x[i] + individuo.b;
        double erro = y_previsto - y[i];
        mse += erro * erro;
    }
    mse /= n;
    return mse / n;
}

double calcularFitness(const Individuo& individuo, const std::vector<double>& x, const std::vector<double>& y)
{
    return 1.0 / (1.0 + calcularMSE(individuo, x, y));
}