#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int valore;
    struct elemento *next;
} nodo;

//funzione che crea un nuovo nodo e lo inserisce in coda alla lista
void inserisciInCoda(int valore, nodo** testa) {
    // Create a new node
    nodo* nuovo = (nodo*)malloc(sizeof(nodo));
    if (nuovo == NULL) {
        return; // return if memory allocation failed
    }
    nuovo->valore = valore;
    nuovo->next = NULL;

    // If the list is empty, set the new node as the head
    if (*testa == NULL) {
        *testa = nuovo;
        return;
    }

    // Otherwise, traverse the list to find the last node
    nodo* corrente = *testa;
    while (corrente->next != NULL) {
        corrente = corrente->next;
    }

    // Set the next field of the last node to the new node
    corrente->next = nuovo;
}

void stampalista(nodo* testa){
    while(testa != NULL){
        printf("%d ", testa->valore);
        testa = testa->next;
    }
}

int main(){
    nodo *testa=NULL;

    for(int i=0; i<10; i++){
        inserisciInCoda(i, &testa);
    }

    stampalista(testa);
}