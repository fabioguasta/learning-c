/*
Esempio cambio di identificatore di gruppo
*/

#include<sys/types.h>
#include<signal.h>
#include<unistd.h>

#include "sysmacro.h"

struct sigaction azione; //per memorizzare il nuovo handler
void gestore_sigint(int);

int main(int argc, char * argv[])
{
    int pid, i;

    //installazione gestore CTRL+C
    IFERROR(sigaction(SIGINT, NULL, &azione), "Errore eseguendo sigaction");
    azione.sa_handler=gestore_sigint;
    IFERROR(sigaction(SIGINT, &azione, NULL), "Errore eseguendo sigaction");

    IFERROR(pid=fork(), "errore eseguendo la fork");

    if(pid==0){//figlio
        
        IFERROR(setpgid(0, getpid()),"eseguendo la setpgid") 
        /*
        Quando si passa 0 come primo argomento e getpid() come secondo argomento, 
        si sta essenzialmente impostando il gruppo del processo corrente con il PID del processo stesso.
        Questo significa che il processo corrente diventerà il capogruppo del proprio gruppo.
        */
    }
    printf("Processo PID %d PGRP %d in attesa\n", getpid(), getpgrp());

    for(i=1; i<=3; i++){
        printf("processo %d vivo\n", getpid());
        sleep(1);
    }

    return 0;
}

void gestore_sigint(int sig)
{
    printf("processo %d ha ricevuto un SIGINT\n", getpid());
    exit(1);
}
