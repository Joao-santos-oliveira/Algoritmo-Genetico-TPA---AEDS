#include "../include/read.hpp"
#include <fstream>
#include <iostream>

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


void SalvarDados(const std::string& filename, int generation, double a, double b, double fitness)
{
    std::ofstream file(filename, std::ios::app);

    file << generation << " "
         << a << " "
         << b << " "
         << fitness << "\n";

    file.close();
}