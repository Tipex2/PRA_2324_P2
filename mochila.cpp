#include <iostream>
#include <vector>
#include <algorithm>

int mochila(int N, const std::vector<int>& p, const std::vector<int>& b, int M, std::vector<int>& x) {
    // Creamos una tabla de (N+1) x (M+1) para la programación dinámica
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(M + 1, 0));

    // Llenamos la tabla con las soluciones óptimas
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            if (p[i - 1] <= j) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - p[i - 1]] + b[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Recuperamos la solución (vector x) indicando qué objetos tomar
    x.assign(N, 0);
    int w = M;
    for (int i = N; i > 0; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            x[i - 1] = 1;  // Tomamos el objeto i-1
            w -= p[i - 1]; // Reducimos el peso
        }
    }

    // Retornamos el beneficio máximo
    return dp[N][M];
}

int main() {
    // Definir los pesos, beneficios y el peso máximo
    std::vector<int> p = {1, 3, 2, 4};
    std::vector<int> b = {10, 20, 15, 20};
    int M = 5;
    int N = p.size();

    std::vector<int> x;  // Para almacenar la solución (qué objetos tomar)

    // Llamar a la función mochila para obtener el máximo beneficio
    int beneficio_maximo = mochila(N, p, b, M, x);

    // Mostrar el resultado
    std::cout << "Beneficio máximo: " << beneficio_maximo << std::endl;
    std::cout << "Solución: ";
    for (int i = 0; i < N; ++i) {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
