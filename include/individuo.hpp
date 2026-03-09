#ifndef INDIVIDUO_HPP
#define INDIVIDUO_HPP

//Criaçao da estrutura do individuo, onde serao armazenados os valores de a, b e o fitness do individuo
//Nesse projeto cada individuo represeenta uma reta, y = ax + b
//a representa o coeficiente angular da reta, b representa o coeficiente linear da reta
//Fitness é o valor do individuo, ou seja, o quao bom ele é em representar os dados de entrada

struct Individuo{
    double a;
    double b;
    double Fitness;
};

#endif