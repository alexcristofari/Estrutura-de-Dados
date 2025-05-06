#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

#include "estrutura.h"

int main() {
    srand(time(NULL));

    Celula *lista = NULL;
    int quantidade = 20;   
    
    for (int i = 0; i < quantidade; i++) {
        lista = inserir(rand() % 100, lista);
    }

    auto inicio = chrono::high_resolution_clock::now();
    lista = ordenarBolha(lista);
    auto fim = chrono::high_resolution_clock::now();
    chrono::duration<double> duracao = fim - inicio;
    cout << "Tempo de execução do bolha: " << duracao.count() << " segundos" << std::endl;    
    
    cout << "Tamanho da lista: " << contar(lista) << "\n";
    
    exibir(lista);

    int numeroPesquisa;
    cout << "Digite um numero de pesquisa: ";
    cin >> numeroPesquisa;

    cout << numeroPesquisa << " aparece na estrutura? " << estaContido(numeroPesquisa, lista) << "\n";

    cout << numeroPesquisa << " aparece na estrutura " << apareceQuantasVezes(numeroPesquisa, lista) << " vezes\n";

    // lista = remover(numeroPesquisa, lista);
    lista = removerTodos(numeroPesquisa, lista);
    cout << "Lista apos a remocao....\n";
    exibir(lista);

    //remover todas as ocorrencias de um valor
    //calcular e retornar a média de uma lista
    //calcular e retornar a mediana de uma lista



    return 1;
}