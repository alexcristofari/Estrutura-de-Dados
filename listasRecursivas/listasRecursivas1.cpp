#include <iostream>
#include <ctime>
using namespace std;
 
#include "listas.h"
 
int main() {
    Celula *lista = NULL;
    int quantidade = 100;
    srand(time(NULL));
   
    while (quantidade > 0) {
        lista = inserirR(rand() % 1000, lista);
        quantidade--;
    }
    exibirR(lista);
 
    return 1;
}