#ifndef READ_HPP
#define READ_HPP

#include <vector>
#include <string>

struct Pontos
{
    double x;
    double y;
};

struct EntradadaDados
{
    int n;                      
    int tamanhoPopulacao;         
    int geracoes;            

    std::vector<Pontos> data;
};

EntradadaDados LerArquivo(const std::string& filename);

void SalvarDados(const std::string& filename, int generacao, double a, double b, double fitness);

#endif