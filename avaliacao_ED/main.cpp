#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "lista.h"
#include "util.h"

int main() {
    Lista* lista1 = NULL;
    Lista* lista2 = NULL;
    Lista* listaComuns = NULL;
    Lista* listaUnida = NULL;

    lista1 = popularLista(lista1, 25);
    lista2 = popularLista(lista2, 30);

    system("cls");

    cout << "Lista 1:" << endl;
    exibir(lista1);

    cout << "Lista 2:" << endl;
    exibir(lista2);

    system("pause");

    // 1) Faça um método que receba as duas listas e exiba os números que estão presentes em ambas.
    listaComuns = localizarComuns(lista1, lista2);
    cout << "Numeros comuns nas listas:" << endl;
    exibir(listaComuns);

    system("pause");

    // 2) Faça um método que exclua todos os números pares da lista1 ou listaA
    lista1 = excluirPares(lista1);
    cout << "Lista 1 sem numeros pares:" << endl;
    exibir(lista1);

    system("pause");

    // 3) Faça um método que una a lista1 ou listaA na lista2 ou listaB. Ou seja, todos os elementos da primeira lista devem vir primeiro dos elementos da segunda lista
    listaUnida = uniaoListas(lista1, lista2);
    cout << "Uniao da Lista 1 com Lista 2:" << endl;
    exibir(listaUnida);

    system("pause");

    // 4) Faça um método que receba o resultado da união da lista1 com a lista2 e aplique um método de ordenação
    listaUnida = ordenarLista(listaUnida);
    cout << "Lista unida ordenada:" << endl;
    exibir(listaUnida);

    system("pause");

    // 5) Faça um método que delete todos os elementos da lista criada da união entre lista1 e lista2.
    listaUnida = deletarLista(listaUnida);
    cout << "Lista unida deletada:" << endl;
    exibir(listaUnida);

    cout << "acabou!" << endl;

    return 1;
}
