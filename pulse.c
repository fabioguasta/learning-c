/*
ESEMPIO DI SOSPENSIONE E RIATTIVAZIONE DI PROCESSI
*/
#include <sys/types.h>
#include <signal.h>

#include <unistd.h>
#include "sysmacro.h"
int main(int argc, char *argv[])
{
    int pid1, pid2;
    IFERROR(pid1 = fork(), "generando il figlio 1");
    if (pid1 == 0)
    {
        while (1)
        {
            printf("Figlio 1 (%d) e’ vivo\n", getpid());
            sleep(1);
        }
    }
    IFERROR(pid2 = fork(), "generando il figlio 2");
    if (pid2 == 0)
    {
        while (1)
        {
            printf("Figlio 2 (%d) e’ vivo\n", getpid());
            sleep(1);
        }
    }
    sleep(3);
    kill(pid1, SIGSTOP);
    system("ps f | grep pulse | grep -v sh");
    sleep(3);
    kill(pid1, SIGCONT);
    sleep(3);
    kill(pid1, SIGINT);
    kill(pid2, SIGINT);
    return (0);
}
