#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int remover_pares(std::vector<int>& v) {
    int j = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] % 2 != 0) {
            v[j++] = v[i];
        }
    }
    v.resize(j);
    return v.size();
}

int main() {
    std::vector<int> lista(10);
    srand(time(0));

    for (int i = 0; i < 10; i++) {
        lista[i] = rand() % 100;
    }

    std::cout << "Lista original:\n";
    for (int i = 0; i < 10; i++) {
        std::cout << lista[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Tamanho original da lista: " << lista.size() << "\n";

    int novo_tamanho = remover_pares(lista);

    std::cout << "Lista após remover pares:\n";
    for (int i = 0; i < novo_tamanho; i++) {
        std::cout << lista[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Tamanho da lista após remover pares: " << novo_tamanho << "\n";

    return 0;
}
