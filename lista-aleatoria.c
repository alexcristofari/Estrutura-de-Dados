#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int remover_pares(int arr[], int *size) {
    int j = 0;
    for (int i = 0; i < *size; i++) {
        if (arr[i] % 2 != 0) {
            arr[j++] = arr[i];
        }
    }
    *size = j;
    return *size;
}

int main() {
    int lista[SIZE];
    int tamanho = SIZE;

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        lista[i] = rand() % 100;
    }

    printf("Lista original:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    printf("Tamanho original da lista: %d\n", SIZE);

    int novo_tamanho = remover_pares(lista, &tamanho);

    printf("Lista após remover pares:\n");
    for (int i = 0; i < novo_tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    printf("Tamanho da lista após remover pares: %d\n", novo_tamanho);

    return 0;
}
