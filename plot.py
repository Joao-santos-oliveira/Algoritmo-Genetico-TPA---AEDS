import matplotlib.pyplot as plt
import numpy as np


x, y = [], []

with open("data/input.dat") as f:
    f.readline()
    for linha in f:
        xi, yi = map(float, linha.split())
        x.append(xi)
        y.append(yi)

melhor = {}

with open("output.dat") as f:
    f.readline()  # pula cabeçalho
    for linha in f:
        g, fit, erro, a, b = linha.split()
        g   = int(g)
        fit = float(fit)
        a   = float(a)
        b   = float(b)

        if g not in melhor or fit > melhor[g][2]:
            melhor[g] = (a, b, fit)

geracoes = sorted(melhor.keys())


g0 = geracoes[0]
g_final = geracoes[-1]

a0, b0, fit0 = melhor[g0]
af, bf, fitf = melhor[g_final]


a_real, b_real = np.polyfit(x, y, 1)

x_line = np.linspace(min(x), max(x), 1000)

y0     = a0     * x_line + b0
yf     = af     * x_line + bf
y_real = a_real * x_line + b_real


plt.figure(figsize=(10,6))

# pontos reais
plt.scatter(x, y, label="Pontos reais")

# inicial
plt.plot(
    x_line, y0,
    label=f"Inicial: y={a0:.5f}x + {b0:.5f} | fit={fit0:.5f}",
    linestyle='--'
)

# final
plt.plot(
    x_line, yf,
    label=f"Final: y={af:.5f}x + {bf:.5f} | fit={fitf:.5f}",
    linewidth=2
)

# reta real
plt.plot(
    x_line, y_real,
    label=f"Real: y={a_real:.5f}x + {b_real:.5f}",
    linestyle=':'
)

plt.xlabel("x")
plt.ylabel("y")
plt.title("Comparação: Inicial vs Final vs Reta Real")

plt.legend()
plt.grid()

# zoom automático mais sensível
plt.xlim(min(x), max(x))
plt.ylim(min(y)-2, max(y)+2)

plt.show()
