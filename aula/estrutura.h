typedef struct no {
    int dado;
    struct no *prox;
} Celula;

Celula *inserir(int valor, Celula *lista){
    //alocar memoria
    Celula *novo = NULL;
    novo = (Celula *)malloc(sizeof(Celula));

    //depositar os parametros
    novo->dado = valor;
    novo->prox = NULL;

    //testar se eh a primeira vez
    if (!lista) {
        return novo;
    }

    //percorrer a lista com controle de duplicados ou não
    Celula *p;
    for (p = lista; p->prox; p = p->prox);

    //encadear
    p->prox = novo;

    //retornar o inicio da lista
    return lista;
}

Celula *ordenarBolha(Celula *lista){
    Celula *p; //para percorrer a estrutura
    int tmp; //para realizar as trocas
    bool houveTroca;

    do {
        houveTroca = false;
        for (p = lista; p->prox; p = p->prox) {
            if (p->dado > p->prox->dado) {
                //trocar
                houveTroca = true;
                tmp = p->dado;
                p->dado = p->prox->dado;
                p->prox->dado = tmp;
            }
        }
    } while (houveTroca);
    
    return lista;
}

int contar(Celula *lista) {
    int quantidade = 0;
    for (Celula *p = lista; p; p = p->prox) {
        quantidade++;
    }
    return quantidade;
}

void exibir(Celula *lista) {  
    for (Celula *p = lista; p; p = p->prox) {
        cout << p->dado << "\n";
    }
}

bool estaContido(int valor, Celula *lista) {
    for (Celula *p = lista; p; p = p->prox) {
        if (valor == p->dado) {
            return true;
        }
    }
    return false;
}

int apareceQuantasVezes(int valor, Celula *lista) {
    int quantidade = 0;
    for (Celula *p = lista; p; p = p->prox) {
        if (valor == p->dado) {
            quantidade++;
        }
    }
    return quantidade;
}

Celula *remover(int valor, Celula *lista) {
    Celula *p, *pR;
    for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
        if (valor == p->dado) {
            //encontrei o valor
            //se for o primeiro
            if (p == lista) {
                lista = lista->prox;
                free(p);
                return lista;
            } 
            //se for o ultimo
            if (!p->prox) {
                pR->prox = NULL;
                free(p);
                return lista;
            }
            //se for alguem do meio
            pR->prox = p->prox;
            free(p);
            return lista;
        }
    }
    return lista;
}

Celula *removerTodos(int valor, Celula *lista) {

    for (int i = 0; i <= apareceQuantasVezes(valor, lista); i++) {
        lista = remover(valor, lista);
    }
    return lista;
}