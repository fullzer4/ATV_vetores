#include <iostream>
#include <vector>
#include <limits>

int main() {
    int n;
    std::cout << "Digite o número de elementos no vetor V (<= 15): ";
    std::cin >> n;

    if (n > 15 || n <= 0) {
        std::cerr << "O número de elementos deve estar entre 1 e 15." << std::endl;
        return 1;
    }

    std::vector<int> V(n);

    std::cout << "Digite os elementos para o vetor V:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> V[i];
    }

    // Lambda para encontrar mínimo e máximo
    auto encontrar_min_max = [&]() {
        int min = std::numeric_limits<int>::max();
        int max = std::numeric_limits<int>::min();
        for (int elem : V) {
            if (elem < min) min = elem;
            if (elem > max) max = elem;
        }
        return std::make_pair(min, max);
    };

    // Executa a função encontrar_min_max
    auto [elemento_minimo, elemento_maximo] = encontrar_min_max();

    // Exibe os resultados
    std::cout << "Elemento mínimo em V: " << elemento_minimo << std::endl;
    std::cout << "Elemento máximo em V: " << elemento_maximo << std::endl;

    return 0;
}