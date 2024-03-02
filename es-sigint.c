/*
Esempio utilizzo SIGINT
*/

#include<sys/types.h>
#include<signal.h>
#include<unistd.h>

#include "sysmacro.h"

struct sigaction azione; //per memorizzare il nuovo handler
void gestore_sigint(int);

int main(int argc, char * argv[])
{
    int pid;

    //installazione gestore CTRL+C
    IFERROR(sigaction(SIGINT, NULL, &azione), "Errore eseguendo sigaction");
    azione.sa_handler=gestore_sigint;
    IFERROR(sigaction(SIGINT, &azione, NULL), "Errore eseguendo sigaction");

    IFERROR(pid=fork(), "errore eseguendo la fork");

    if(pid==0){
        //figlio
        printf("Figlio PID %d PGRP %d aspetta\n", getpid(), getpgrp());
        
    }
    else{
        //padre
        printf("Padre PID %d PGRP %d aspetta\n", getpid(), getpgrp());
    }

    return 0;
}

void gestore_sigint(int sig)
{
    printf("processo %d ha ricevuto un SIGINT\n", getpid());
    exit(1);
}
