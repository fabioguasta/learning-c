/*
esegue un comando in background
*/
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#include "sysmacro.h"

int main(int argc, char *argv[])
{
    int pid, status;
    if(argc<2){
        WRITE("Usage: comando cmd arg... \n");
        return 0;
    }

    IFERROR(pid=fork(), "generando il figlio");
    if(pid==0){
        //siamo nel figlio
        
        IFERROR(pid=fork(), "generando il nipote");
        if(pid==0){
            //siamo nel nipote
            execvp(argv[1], &argv[1]);
            printf("non ho potuto eseguire il comando");
            exit(-1);
        }
        else{
            //attendiamo la terminazione del nipote
            wait(&status);
            WRITE("Comando terminato\n");
        }
    //il padre termina subito
    return 0;
    }
}