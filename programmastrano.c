/*
Si realizzi un programma C che accetta come parametro un numero (intero) n e crea esattamente n processi.
Ognuno dei processi viene attivato ed esegue k+2 iterazioni dove k `e il numero progressivo di processo generato.
Ad ogni iterazione il processo stampa il proprio PID e il proprio numero di iterazione e attende un secondo con una sleep(1).
Ogni processo termina passando alla exit (o return) il proprio pid modulo 256.
Il processo padre attende la terminazione di tutti i figli e ne stampa il codice di uscita.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s number\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Number must be positive\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            return 1;
        } else if (pid == 0) {
            for (int j = 0; j < i + 2; j++) {
                printf("PID: %d, Iteration: %d\n", getpid(), j);
                sleep(1);
            }
            exit(getpid() % 256);
        }
    }

    for (int i = 0; i < n; i++) {
        int status;
        pid_t pid = wait(&status);
        if (pid < 0) {
            perror("wait");
            return 1;
        }
        printf("Child with PID %d exited with status %d\n", pid, WEXITSTATUS(status));
    }
   
    return 0;
}