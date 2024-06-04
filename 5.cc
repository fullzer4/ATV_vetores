#include <iostream>
#include <vector>
#include <limits>

int main() {
    int n;
    std::cout << "Digite o número de atletas (<= 100): ";
    std::cin >> n;

    if (n > 100 || n <= 0) {
        std::cerr << "O número de atletas deve estar entre 1 e 100." << std::endl;
        return 1;
    }

    std::vector<int> numeros_inscricao(n);
    std::vector<int> alturas(n);

    std::cout << "Digite o número de inscrição e altura para cada atleta:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> numeros_inscricao[i] >> alturas[i];
    }

    // Lambda para encontrar o atleta mais alto e mais baixo
    auto encontrar_extremos = [&]() {
        int altura_minima = std::numeric_limits<int>::max();
        int altura_maxima = std::numeric_limits<int>::min();
        int numero_inscricao_min, numero_inscricao_max;

        for (int i = 0; i < n; ++i) {
            if (alturas[i] < altura_minima) {
                altura_minima = alturas[i];
                numero_inscricao_min = numeros_inscricao[i];
            }
            if (alturas[i] > altura_maxima) {
                altura_maxima = alturas[i];
                numero_inscricao_max = numeros_inscricao[i];
            }
        }
        return std::make_tuple(numero_inscricao_min, altura_minima, numero_inscricao_max, altura_maxima);
    };

    // Lambda para calcular a altura média
    auto calcular_altura_media = [&]() -> double {
        double soma = 0.0;
        for (int altura : alturas) {
            soma += altura;
        }
        return soma / n;
    };

    // Executar funções
    auto [num_inscricao_min, altura_min, num_inscricao_max, altura_max] = encontrar_extremos();
    double altura_media = calcular_altura_media();

    // Exibir resultados
    std::cout << "Número de inscrição do atleta mais alto: " << num_inscricao_max << " com altura: " << altura_max << " cm" << std::endl;
    std::cout << "Número de inscrição do atleta mais baixo: " << num_inscricao_min << " com altura: " << altura_min << " cm" << std::endl;
    std::cout << "Altura média do grupo: " << altura_media << " cm" << std::endl;

    return 0;
}