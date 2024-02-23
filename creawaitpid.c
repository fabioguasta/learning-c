/*
creazione di un processo e riporto dello stato
(terminato o running)
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "sysmacro.h"
int main(int argc, char *argv[])
{
    int pid, pidw, status;
    IFERROR(pid = fork(), "generando il figlio");
    if (pid)
    {
        /* siamo nel padre */
        printf("Processo padre(pid=%d): ho generato figlio (pid=%d)\n",
               getpid(), pid);
        do
        {
            sleep(1);
            /* verifico lo stato del figlio */
            IFERROR(pidw = waitpid(pid, &status, WNOHANG), "waitpid");
            if (pidw > 0)
            {
                if (WIFEXITED(status))
                    printf("Processo %d terminato con exit(%d)\n",
                           pidw, WEXITSTATUS(status));
                else
                    printf("Processo %d terminato con segnale.\n",
                           pidw);
            }
            else
                printf("Processo %d in esecuzione.\n", pid);
        } while (pidw == 0);
    }
    else
    {
        /* siamo nel figlio */
        printf("Processo figlio(pid=%d): sono generato dal processo (pid=%d)\n",
               getpid(), getppid());
        sleep(5);
        printf("Processo figlio(pid=%d): ho terminato!\n", getpid());
    }
    return 0;
}