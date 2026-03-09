# Algortitmo-Genetico-TPA---AEDS
Implementação de um algoritmo genético em C/C++ para ajustar uma função linear, 𝑦 = 𝑎𝑥 + 𝑏y, um conjunto de dados.

## Cálculo do Fitness

O algoritmo genético utiliza uma função de **fitness** para avaliar a qualidade de cada indivíduo da população.  
No problema de regressão linear, cada indivíduo representa uma reta da forma:

y = ax + b

onde:

- **a** representa o coeficiente angular (inclinação da reta)
- **b** representa o coeficiente linear (intercepto)

O objetivo do algoritmo é encontrar os valores de **a** e **b** que melhor se ajustem ao conjunto de dados fornecido.

---

## Erro Quadrático Médio (MSE)

Para medir o erro entre a reta gerada por um indivíduo e os dados reais, é utilizado o **Mean Squared Error (MSE)** ou **Erro Quadrático Médio**.

O MSE mede a média dos quadrados das diferenças entre os valores observados e os valores previstos pelo modelo.

A fórmula é dada por:

MSE = (1/n) * Σ (yi - (axi + b))²

onde:

- **n** é o número total de pontos no conjunto de dados  
- **xi** é o valor da variável independente  
- **yi** é o valor real observado  
- **axi + b** é o valor previsto pela reta do indivíduo  

Quanto **menor o valor do MSE**, melhor é o ajuste da reta aos dados.

---

## Cálculo do Fitness

Como algoritmos genéticos normalmente trabalham **maximizando o fitness**, o erro precisa ser transformado em uma métrica onde **valores maiores representam soluções melhores**.

Para isso, o fitness é definido como:

fitness = 1 / (1 + MSE)

Essa transformação garante que:

- **erros menores gerem valores de fitness maiores**
- **erros maiores resultem em fitness menores**
- o fitness sempre permaneça positivo

Assim, indivíduos que produzem retas mais próximas dos dados reais possuem **maior probabilidade de serem selecionados para reprodução nas próximas gerações**.
