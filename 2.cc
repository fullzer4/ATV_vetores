#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Digite o número de valores (<= 10): ";
    std::cin >> n;

    if (n > 10 || n <= 0) {
        std::cerr << "O número de valores deve estar entre 1 e 10." << std::endl;
        return 1;
    }

    std::vector<double> V(n);
    std::vector<double> smoothedV(n);

    std::cout << "Digite os valores:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> V[i];
        smoothedV[i] = V[i];
    }

    for (int i = 1; i < n - 1; ++i) {
        smoothedV[i] = (V[i - 1] + V[i] + V[i + 1]) / 3.0;
    }

    std::cout << "Valores originais:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << V[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Valores suavizados:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << smoothedV[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}