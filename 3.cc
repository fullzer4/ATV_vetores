#include <iostream>
#include <vector>

int main() {
    int n;
    std::cout << "Digite o número de elementos nos vetores (<= 15): ";
    std::cin >> n;

    if (n > 15 || n <= 0) {
        std::cerr << "O número de elementos deve estar entre 1 e 15." << std::endl;
        return 1;
    }

    std::vector<double> V(n), W(n), sum(n), difference(n), product(n), quotient(n);

    std::cout << "Digite os elementos para o vetor V:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> V[i];
    }

    std::cout << "Digite os elementos para o vetor W:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> W[i];
    }

    // Funções lambda para operações com vetores
    auto calculate_sum = [&]() {
        for (int i = 0; i < n; ++i) sum[i] = V[i] + W[i];
    };

    auto calculate_difference = [&]() {
        for (int i = 0; i < n; ++i) difference[i] = V[i] - W[i];
    };

    auto calculate_product = [&]() {
        for (int i = 0; i < n; ++i) product[i] = V[i] * W[i];
    };

    auto calculate_quotient = [&]() {
        for (int i = 0; i < n; ++i) quotient[i] = W[i] != 0 ? V[i] / W[i] : 0; // Evita divisão por zero
    };

    auto calculate_dot_product = [&]() -> double {
        double dotProduct = 0.0;
        for (int i = 0; i < n; ++i) {
            dotProduct += V[i] * W[i];
        }
        return dotProduct;
    };

    // Executa operações com vetores
    calculate_sum();
    calculate_difference();
    calculate_product();
    calculate_quotient();
    double dotProduct = calculate_dot_product();

    // Exibe os resultados
    auto display_vector = [](const std::vector<double>& vec, const std::string& name) {
        std::cout << name << ":" << std::endl;
        for (double num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    };

    display_vector(sum, "Soma de V e W");
    display_vector(difference, "Diferença de V e W");
    display_vector(product, "Produto de V e W");
    display_vector(quotient, "Quociente de V e W");

    std::cout << "Produto escalar de V e W: " << dotProduct << std::endl;
    std::cout << (dotProduct == 0 ? "Os vetores V e W são ortogonais." : "Os vetores V e W não são ortogonais.") << std::endl;

    return 0;
}