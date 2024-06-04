#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cout << "Entre o numero de estudantes (<= 20): ";
    std::cin >> n;

    if (n > 20 || n <= 0) {
        std::cerr << "O numero de estudantes tem que ser entre 1 e 20." << std::endl;
        return 1;
    }

    std::vector<std::string> names(n);
    std::vector<double> grades(n);
    double total = 0.0;

    for (int i = 0; i < n; ++i) {
        std::cout << "Insira o nome do estudante " << i + 1 << ": ";
        std::cin >> names[i];
        std::cout << "Insira a nota " << names[i] << ": ";
        std::cin >> grades[i];
        total += grades[i];
    }

    double average = total / n;
    std::cout << "Media da sala: " << average << std::endl;

    std::cout << "Estudantes comnota acima da media da sala:" << std::endl;
    for (int i = 0; i < n; ++i) {
        if (grades[i] >= average) {
            std::cout << names[i] << " com nota " << grades[i] << std::endl;
        }
    }

    int below_average_count = 0;
    for (int i = 0; i < n; ++i) {
        if (grades[i] < average) {
            below_average_count++;
        }
    }

    std::cout << "Estudantes com nota abaixo da media da sala: " << below_average_count << std::endl;

    return 0;
}
