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

void SalvarDados(std::ofstream& file, int generacao, double fitness, double erro, double a, double b);
#endif