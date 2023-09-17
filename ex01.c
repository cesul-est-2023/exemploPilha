#include <stdio.h>
#include <stdlib.h>

typedef struct Prova {
    char* aluno;
    int ra;
    float nota;
} Prova;

typedef struct Item {
    Prova valor;
    struct Item* proximo;
} Item;

typedef struct Pilha {
    Item *topo;
    int tamanho;
} Pilha;

Pilha pilha = {NULL,  0};

Item* criarItem(Prova valor) {
    Item* novoItem = malloc(sizeof(Item));
    novoItem->valor = valor;
    novoItem->proximo = NULL;

    return novoItem;
}

void empilhar(Prova valor) {
    Item* novoItem = criarItem(valor);

    if (pilha.topo == NULL) {
        pilha.topo = novoItem;
    } else {
        novoItem->proximo = pilha.topo;
        pilha.topo = novoItem;
    }

    pilha.tamanho ++;
}

void exibirPilha() {
    Item* item = pilha.topo;
    while (item != NULL) {
        Prova prova = item->valor;
        printf("Aluno: %s \n", prova.aluno);
        printf("RA: %d \n", prova.ra);
        printf("Nota: %.1f \n", prova.nota);
        printf("------\n");

        item = item->proximo;
    }
}

void desempilhar() {
    Item* itemRemover = pilha.topo;
    pilha.topo = itemRemover->proximo;
    pilha.tamanho --;

    printf("Desempilhado -> %s \n", itemRemover->valor.aluno);
    printf("------\n");

    free(itemRemover);
}

int main() {
    Prova p1 = { "Joao", 1001, 9.0f};
    Prova p2 = { "Pedro", 1002,8.5f};
    Prova p3 = { "Maria", 1003, 6.7f};
    Prova p4 = { "Paulo", 1004, 9.2f};
    Prova p5 = { "Lucia", 1005, 9.6f};

    empilhar(p1);
    empilhar(p2);
    empilhar(p3);
    empilhar(p4);
    empilhar(p5);

    exibirPilha();

    desempilhar();
    exibirPilha();

    desempilhar();
    exibirPilha();

    return 0;
}
