#include <iostream>
#include <vector>
#include <algorithm> // Para std::find

int main() {
    int n;
    std::cout << "Digite o número de alunos na turma (<= 30): ";
    std::cin >> n;

    if (n > 30 || n <= 0) {
        std::cerr << "O número de alunos deve estar entre 1 e 30." << std::endl;
        return 1;
    }

    std::vector<std::string> nomes(n);
    std::vector<double> notasFinais(n);

    std::cout << "Digite os nomes e notas finais para cada aluno:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Aluno " << i + 1 << ": ";
        std::cin >> nomes[i] >> notasFinais[i];
    }

    // Função lambda para buscar um aluno pelo nome e mostrar a nota final
    auto buscar_aluno = [&](const std::string& nome) {
        auto it = std::find(nomes.begin(), nomes.end(), nome);
        if (it != nomes.end()) { // Aluno encontrado
            int index = std::distance(nomes.begin(), it);
            std::cout << "Nota final de " << nome << ": " << notasFinais[index] << std::endl;
        } else { // Aluno não encontrado
            std::cout << "Aluno '" << nome << "' não encontrado." << std::endl;
        }
    };

    // Loop de busca
    char escolha;
    do {
        std::string nomeBusca;
        std::cout << "Digite o nome do aluno que você deseja buscar: ";
        std::cin >> nomeBusca;
        buscar_aluno(nomeBusca);

        std::cout << "Deseja buscar outro aluno? (s/n): ";
        std::cin >> escolha;
    } while (escolha == 's' || escolha == 'S');

    return 0;
}