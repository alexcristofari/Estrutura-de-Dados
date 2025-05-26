#include <ctime>
#include <cstdlib>
#include "lista.h"

using namespace std;

Lista* popularLista(Lista* lista, int n) {
    srand(time(NULL));
    int i = 0;
    while (i < n) {
        lista = inserir((rand() % 100) + 1, lista);
        i++;
    }
    return lista;
}

Lista* localizarComuns(Lista* listaA, Lista* listaB) {
    Lista* listaResultado = NULL;
    Lista* p1, * p2;

    for (p1 = listaA; p1; p1 = p1->prox) {
        for (p2 = listaB; p2; p2 = p2->prox) {
            if (p1->dado == p2->dado) {
                listaResultado = inserir(p1->dado, listaResultado);
            }
        }
    }
    return listaResultado;
}

Lista* excluirPares(Lista* lista) {
    Lista* p = lista;
    Lista* anterior = NULL;

    while (p != NULL) {
        if (p->dado % 2 == 0) {
            if (p == lista) {
                lista = p->prox;
                free(p);
                p = lista;
            }
            else {
                anterior->prox = p->prox;
                free(p);
                p = anterior->prox;
            }
        }
        else {
            anterior = p;
            p = p->prox;
        }
    }

    return lista;
}

Lista* uniaoListas(Lista* listaA, Lista* listaB) {
    Lista* listaResultado = NULL;
    Lista* p;

    for (p = listaA; p; p = p->prox) {
        listaResultado = inserir(p->dado, listaResultado);
    }

    for (p = listaB; p; p = p->prox) {
        listaResultado = inserir(p->dado, listaResultado);
    }

    return listaResultado;
}

Lista* ordenarLista(Lista* lista) {
    if (!lista || !lista->prox) {
        return lista;
    }

    Lista* listaOrdenada = NULL;
    Lista* p;

    for (p = lista; p; p = p->prox) {
        listaOrdenada = inserir(p->dado, listaOrdenada);
    }

    return listaOrdenada;
}

Lista* deletarLista(Lista* lista) {
    Lista* p;
    while (lista != NULL) {
        p = lista;
        lista = lista->prox;
        free(p);
    }
    return NULL;
}
