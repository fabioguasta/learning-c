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
    }
    else
    {
        /* siamo nel figlio */
        sleep(2); /* aspettiamo un po’ ...
        il padre dovrebbe nel frattempo terminare */
        printf("Processo figlio(pid=%d): adottato dal processo (pid=%d)\n",
               getpid(), getppid()); /* a questo punto il figlio e’
                stato adottato da init */
    }
    /* padre e figlio */
    return (0);
}
