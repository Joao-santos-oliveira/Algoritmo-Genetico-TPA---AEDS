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

std::string NomeOutput()
{
    std::time_t now = std::time(nullptr);
    std::tm* t = std::localtime(&now);

    std::ostringstream oss;
    oss << "output_"
        << (t->tm_year + 1900)
        << (t->tm_mon + 1)
        << t->tm_mday << "_"
        << t->tm_hour
        << t->tm_min
        << t->tm_sec
        << ".dat";

    return oss.str();
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