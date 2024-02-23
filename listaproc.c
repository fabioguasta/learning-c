/*
Si scriva un programma C, che implementi il comando listaproc, il quale invocato con listaproc numero genera un processo, stampa 1 e termina.
Il processo generato deve generare un altro processo, stampare 2 e terminare. Il processo generato deve generare un altro processo,
stampare 3 e terminare. E cosi via, fino a quando si giunge al processo che deve stampare numero, il quale non genera alcun processo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void create_process(int n, int max) {
    printf("%d\n", n);
    if (n < max) {
        if (fork() == 0) {
            create_process(n + 1, max);
            exit(0);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s number\n", argv[0]);
        return 1;
    }

    int max = atoi(argv[1]);
    if (max <= 0) {
        fprintf(stderr, "Number must be positive\n");
        return 1;
    }

    create_process(1, max);

    return 0;
}