/*
esegue un comando per n secondi
[utilizzo kill]
*/
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

#include "sysmacro.h"

struct sigaction azione;
void gestore_chld(int);

int main(int argc, char *argv[])
{
    int pid, secondi, resto=0;

    if(argc<3){
        WRITE("Usage: ./timeout secondi cmd arg ...\n");
        return 0;
    }

    secondi=atoi(argv[1]);

    IFERROR(pid=fork(),"generando il figlio");
    if(pid==0){     //siamo nel figlio
        IFERROR(execvp(argv[2], &argv[2]), "eseguendo il comando");
    }

    //siamo nel padre
    IFERROR(sigaction(SIGCHLD,NULL,&azione), "eseguendo sigaction");
    azione.sa_handler=gestore_chld;
    IFERROR(sigaction(SIGCHLD, &azione, NULL), "eseguendo sigaction");

    resto=sleep(secondi);   //la sleep viene interrotta dal segnale

    if(resto==0)
        IFERROR(kill(pid, SIGKILL),"inviando il segnale di kill");

    sleep(1);
    return 0;
}

void gestore_chld(int sig)
{
    int pid, stato;
    pid=wait(&stato);

    if(WIFEXITED(stato))    //terminazione mediante exit
        printf("processo %d terminato pre una exit(%d)\n", pid, WEXITSTATUS(stato));
    
    if(WIFSIGNALED(stato))
        printf("processo %d termianto per una kill (%d)\n", pid, WIFSIGNALED(stato));
    
    exit(0);
}