#include "../include/read.hpp"
#include <fstream>
#include <iostream>
#include <ctime>
#include <sstream>

EntradadaDados LerArquivo(const std::string& filename)
{
    EntradadaDados input;

    std::ifstream file(filename);

    if(!file)
    {
        std::cerr << "Erro ao abrir arquivo\n";
        return input;
    }

    file >> input.n >> input.tamanhoPopulacao >> input.geracoes;

    Pontos p;

    for(int i = 0; i < input.n; i++)
    {
        file >> p.x >> p.y;
        input.data.push_back(p);
    }

    file.close();

    return input;
}

void SalvarDados(std::ofstream& file, int generacao, double fitness, double erro, double a, double b) {
    file << generacao << " " 
    << fitness << " " 
    << erro << " " 
    << a << " " 
    << b << "\n";
    }