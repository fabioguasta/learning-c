#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int valore;
    struct elemento *next;
} nodo;


//funzione che crea un nuovo nodo e lo inserisce in testa alla lista
nodo* inserimentoInTesta(int valore, nodo** testa){ 
    nodo* nuovo = (nodo*)malloc(sizeof(nodo));
    if (nuovo == NULL) {
        return NULL; // return NULL if memory allocation failed
    }
    nuovo->valore = valore;
    nuovo->next = *testa;
    return nuovo;
} 

nodo* cercaElemento(int valore, nodo* testa) {
    nodo* corrente = testa;
    while(corrente != NULL) {
        if(corrente->valore == valore) {
            return corrente; // restituisce il nodo se il valore è trovato
        }
        corrente = corrente->next;
    }
    return NULL; // restituisce NULL se il valore non è trovato
}

void stampalista(nodo* testa){
    nodo* corrente = testa;
    while(corrente != NULL){
        printf("%d ", corrente->valore);
        corrente = corrente->next;
    }
}

//stampa la lista in ordine inverso attraverso ricorsione
void stampaReverse(nodo* testa){
    if(testa == NULL){
        return;
    }
    stampaReverse(testa->next);
    printf("%d ", testa->valore);
}

int main(){
    nodo *testa=NULL;
    nodo *nuovoElemento=NULL;

    for(int i=0; i<10; i++){
        nuovoElemento = inserimentoInTesta(i, &testa);
        testa = nuovoElemento;
    }

    stampalista(testa);
    printf("\n");
    stampaReverse(testa);
    printf("\n");
    return 0;
}