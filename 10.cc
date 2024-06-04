#include <iostream>
#include <vector>
#include <cmath>

bool eh_primo(int numero) {
    if (numero <= 1) return false;
    if (numero <= 3) return true; 

    // Verifica se o número é divisível por algum número entre 2 e sua raiz quadrada
    for (int i = 2; i <= std::sqrt(numero); ++i) {
        if (numero % i == 0) return false;
    }
    return true; // Se não foi divisível por nenhum número, é primo
}

int main() {
    int n;
    std::cout << "Digite o número de elementos no vetor X (1 a 100): ";
    std::cin >> n;

    if (n < 1 || n > 100) {
        std::cerr << "O número de elementos no vetor deve estar entre 1 e 100." << std::endl;
        return 1;
    }

    std::vector<int> X(n);

    std::cout << "Insira os elementos do vetor X:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> X[i];
    }

    std::vector<int> Y; // Vetor para armazenar os números primos

    // Construindo o vetor Y com os números primos de X
    for (int num : X) {
        if (eh_primo(num)) {
            Y.push_back(num);
        }
    }

    // Exibindo o vetor Y
    std::cout << "Números primos no vetor Y:" << std::endl;
    for (int primo : Y) {
        std::cout << primo << " ";
    }
    std::cout << std::endl;

    return 0;
}