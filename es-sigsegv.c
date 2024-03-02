/*
esempio di installazione gestore SIGSEGV

Il segnale SIGSEGV viene inviato dal kernel al processo che ha tentato di accedere al di fuori dei segmenti di memoria assegnati.
*/

#include<signal.h>

#include "sysmacro.h"

void gestore_sigsegv(int);
struct sigaction azione;

int main(int argc, char* argv[])
{
    char stringa[10];

    IFERROR(sigaction(SIGINT, NULL, &azione), "Errore eseguendo sigaction");
    azione.sa_handler=gestore_sigsegv;
    IFERROR(sigaction(SIGINT, &azione, NULL), "Errore eseguendo sigaction");

    stringa[100000]=1; //scrivo in area non assegnata 

    return 0;
}

void gestore_sigsegv(int sig)
{
    printf("ricevuto segnale numero %d. Hai tentato di accedere a memoria non assegnata.\n", sig);
    exit(-1);
}