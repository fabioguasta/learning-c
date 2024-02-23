/* 
esegue un comando mediante execvp, e attende la terminazione
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "sysmacro.h"

int main(int argc, char *argv[])
{
    int pid, status;
    if (argc < 2)
    {
        WRITE("Usage: comando cmd arg ...\n");
        return (0);
    }
    IFERROR(pid = fork(), "generando il figlio");
    if (pid == 0)
    {
        /* siamo nel figlio */
        execvp(argv[1], &argv[1]);
        printf("Non ho potuto eseguire %s\n", argv[1]);
        exit(-1);
    }
    else
    {
        /* siamo nel padre */
        wait(&status);
        WRITE("Comando terminato.\n");
    }
    return (0);
}