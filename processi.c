#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM_CHILDREN 5

int main() {
    pid_t pid;
    int i;

    for (i = 0; i < NUM_CHILDREN; i++) {
        pid = fork();

        if (pid < 0) { // Se fork() restituisce un valore negativo, la creazione del processo figlio non è riuscita
            fprintf(stderr, "Fork Failed");
            return 1;
        }
        else if (pid == 0) { // fork() restituisce 0 nel processo figlio
            printf("Sono il processo figlio %d, PID = %d\n", i, getpid());
            exit(0); // Termina il processo figlio
        }
    }

    // Il processo genitore attende che tutti i processi figli terminino
    for (i = 0; i < NUM_CHILDREN; i++) {
        wait(NULL);
    }

    printf("Sono il processo genitore, PID = %d\n", getpid());

    return 0;
}