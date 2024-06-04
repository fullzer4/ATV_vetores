#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int n;
    std::cout << "Digite o número de turistas (<= 3000): ";
    std::cin >> n;

    if (n < 1 || n > 3000) {
        std::cerr << "O número de turistas deve estar entre 1 e 3000." << std::endl;
        return 1;
    }

    // Cada praia é identificada por um código de 1 a 42.
    std::vector<int> contadorTuristas(43, 0); // Contador de turistas para cada praia (índice 0 não usado)
    std::vector<double> rendaTotal(43, 0.0); // Soma das rendas para cada praia

    std::cout << "Digite o código da praia (1-42) e a renda mensal para cada turista:" << std::endl;
    for (int i = 0; i < n; ++i) {
        int codigoPraia;
        double renda;
        std::cin >> codigoPraia >> renda;
        if (codigoPraia < 1 || codigoPraia > 42) {
            std::cerr << "Código de praia inválido. Deve estar entre 1 e 42." << std::endl;
            return 1;
        }
        contadorTuristas[codigoPraia]++;
        rendaTotal[codigoPraia] += renda;
    }

    // Mostrando resultados
    std::cout << "Codigo da Praia Numero de turistas Renda media(R$)" << std::endl;
    for (int i = 1; i <= 42; ++i) {
        if (contadorTuristas[i] > 0) { // Apenas praias com turistas
            double rendaMedia = rendaTotal[i] / contadorTuristas[i];
            std::cout << std::setw(10) << i
                      << std::setw(20) << contadorTuristas[i]
                      << std::fixed << std::setprecision(2)
                      << std::setw(20) << rendaMedia << std::endl;
        }
    }

    return 0;
}