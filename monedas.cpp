#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

const int INF = std::numeric_limits<int>::max();

int cambio(const std::vector<int>& v, int N, int M, std::vector<int>& solution) {
   
    std::vector<std::vector<int>> dp(N, std::vector<int>(M + 1, INF));

    
    for (int i = 0; i < N; i++) {
        dp[i][0] = 0;
    }

   
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            if (i > 0) {
                dp[i][j] = dp[i - 1][j]; 
            }
            if (j >= v[i] && dp[i][j - v[i]] != INF) {
                dp[i][j] = std::min(dp[i][j], dp[i][j - v[i]] + 1);
            }
        }
    }

    if (dp[N - 1][M] == INF) {
        return -1;
    }

    solution.assign(N, 0);
    int i = N - 1, j = M;
    while (j > 0 && i >= 0) {
        if (i > 0 && dp[i][j] == dp[i - 1][j]) {
            i--; 
        } else {
            solution[i]++;
            j -= v[i];
        }
    }

    return dp[N - 1][M];
}

int main() {
    // Ejemplo de uso
    std::vector<int> monedas = {1, 4, 6};
    int cantidad = 8;
    std::vector<int> solucion;

    int minimoMonedas = cambio(monedas, monedas.size(), cantidad, solucion);

    if (minimoMonedas == -1) {
        std::cout << "No es posible dar el cambio para " << cantidad << std::endl;
    } else {
        std::cout << "El número mínimo de monedas es: " << minimoMonedas << std::endl;
        std::cout << "Solución: ";
        for (size_t i = 0; i < solucion.size(); i++) {
            std::cout << solucion[i] << " monedas de valor " << monedas[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
