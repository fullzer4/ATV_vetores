#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Digite o número de elementos (1 a 10): ";
    std::cin >> n;

    if (n < 1 || n > 10) {
        std::cerr << "O número de elementos deve estar entre 1 e 10." << std::endl;
        return 1;
    }

    std::vector<int> X(n);

    std::cout << "Digite os elementos do vetor X:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> X[i];
    }

    // Lambda para inverter o vetor sem usar um vetor auxiliar
    auto inverter_vetor = [&]() {
        for (int i = 0; i < n / 2; ++i) {
            std::swap(X[i], X[n - i - 1]);
        }
    };

    // Executar a operação de inversão
    inverter_vetor();

    // Exibir os elementos após a inversão
    std::cout << "Elementos do vetor X após a inversão:" << std::endl;
    for (int elemento : X) {
        std::cout << elemento << " ";
    }
    std::cout << std::endl;

    return 0;
}
