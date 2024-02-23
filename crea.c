/*
CREAZIONE DI UN PROCESSO TRAMITE FORK
*/

#include <unistd.h>
#include "sysmacro.h" /* macro di utilita’ */
int main(int argc, char *argv[])
{
    int pid;
    IFERROR(pid = fork(), "generando il figlio");
    if (pid)
    {
        /* siamo nel padre */
        printf("Processo padre(pid=%d): ho generato figlio (pid=%d)\n",
               getpid(), pid);
        sleep(2); /* il processo si sospende per 2 secondi */
    }
    else
    {
        /* siamo nel figlio */
        printf("Processo figlio(pid=%d): sono generato dal processo (pid=%d)\n",
               getpid(), getppid());
    }
    /* padre e figlio */
    return (0);
}
