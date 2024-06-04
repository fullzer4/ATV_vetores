#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cout << "Digite o número de elementos no vetor (<= 15): ";
    std::cin >> n;

    if (n > 15 || n <= 0) {
        std::cerr << "O número de elementos deve estar entre 1 e 15." << std::endl;
        return 1;
    }

    std::vector<int> numeros(n);

    std::cout << "Digite os elementos para o vetor:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> numeros[i];
    }

    // Ordenando o vetor em ordem crescente
    std::sort(numeros.begin(), numeros.end());

    // Exibindo o vetor ordenado
    std::cout << "Vetor ordenado:" << std::endl;
    for (int num : numeros) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}