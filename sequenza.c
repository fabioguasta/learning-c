/*
esegue una sequenza di comandi mediante execvp
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "sysmacro.h"
#include "util.h"

int main(int argc, char *argv[])
{
    int pid, status, argn, i;
    char **newargv;

    if (argc<2){
        WRITE("Usage: sequenza cmd ..."); 
        return 0;
    }

    for(i=1; i<argc; i++)
    {
        IFERROR(pid=fork(), "generando il figlio");
        if(pid==0){ //condizione che indica che siamo nel figlio
            newargv=split_arg(argv[i], " ", &argn);
            execvp(newargv[0], newargv);
            printf("non ho potuto eseguire %s\n", argv[1]);
            exit(-1);
        }
        else{ //siamo nel padre
            wait(&status);
            WRITE("Comando terminato\n");
        }
    }
return 0;
}