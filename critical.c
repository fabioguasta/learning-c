/*
ESEMPIO PROTEZIONE DI CODICE CRITICO
*/
#include <signal.h>
#include "sysmacro.h"

int main(int argc, char *argv[])
{
    struct sigaction oldHandler; /* per memorizzare il vecchio handler */
    struct sigaction newHandler; /* per memorizzare il nuovo handler */
    printf("Posso essere interrotto\n");
    sleep(3);

    newHandler.sa_handler = SIG_IGN;

    IFERROR(sigaction(SIGINT, &newHandler, &oldHandler), "eseguendo la sigaction");
    /* ignora Control-C */
    printf("Ora non posso essere interrotto\n");

    sleep(3);

    IFERROR(sigaction(SIGINT, &oldHandler, NULL), "eseguendo la sigaction");
    /* ripristina vecchio handler */
    printf("Posso essere interrotto di nuovo!\n");

    sleep(3);
    
    printf("Ciao!!!\n");
    return (0);
}
