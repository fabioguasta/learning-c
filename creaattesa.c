#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "sysmacro.h"
int main(int argc, char *argv[])
{
    int pid, pidw, status;
    IFERROR(pid = fork(), "generando il figlio");
    if (pid)
    { /* siamo nel padre */
        printf("Processo padre(pid=%d): ho generato figlio (pid=%d)\n",
               getpid(), pid);
        pidw = wait(&status); /* attendo la terminazione del figlio */
        if (WIFEXITED(status))
            printf("Processo padre(pid=%d): processo %d terminato con exit(%d)\n",
                   getpid(), pidw, WEXITSTATUS(status));
        else
            printf("Processo padre(pid=%d): processo %d terminato con segnale\n",
                   getpid(), pidw);
    }
    else
    {
        /* siamo nel figlio */
        printf("Processo figlio(pid=%d): sono generato dal processo (pid=%d)\n",
               getpid(), getppid());
        sleep(1);
    }
    /* padre e figlio */
    return (0);
}