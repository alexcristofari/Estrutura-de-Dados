#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct no {
    int dado;
    struct no* prox;
} Lista;

void exibir(Lista* lista) {
    Lista* p;
    for (p = lista; p; p = p->prox) {
        cout << p->dado << "\t";
    }
    cout << endl;
}

int contar(Lista* lista) {
    Lista* p;
    int qtd = 0;
    for (p = lista; p; p = p->prox) {
        qtd++;
    }
    return qtd;
}

bool localizar(int valor, Lista* lista) {
    Lista* p;
    for (p = lista; p; p = p->prox) {
        if (valor == p->dado)
            return true;
    }
    return false;
}

Lista* inserir(int valor, Lista* lista) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->dado = valor;
    novo->prox = NULL;

    Lista *p, *pR;
    for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
        if (valor == p->dado) {
            free(novo);
            return lista;
        }
        if (valor < p->dado) {
            break;
        }
    }

    if (p == lista) {
        novo->prox = p;
        return novo;
    }

    if (!p) {
        pR->prox = novo;
        return lista;
    }

    pR->prox = novo;
    novo->prox = p;
    return lista;
}

#endif
