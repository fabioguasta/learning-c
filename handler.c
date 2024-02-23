/*
invio di segnale di allarme con gestione personalizzata della routine di gestione del segnale
[esempio uitilizzo sigaction]
*/

#include <unistd.h>
#include <signal.h>
#include "sysmacro.h"

int alarmFlag=0;
struct sigaction azione;
void gestore_segnale(int sig)
{
    alarmFlag=1;
    printf("Sono nel gestore segnale\n");
}

int main(int argc, char *argv[])
{
    
    
    azione.sa_handler=gestore_segnale;
    IFERROR(sigaction(SIGALRM,&azione, NULL), "eseguendo la sigaction.");  //installazione routine gestione segnale

    alarm(3); //allarme dopo 3 secondi

    printf("Ciclo infinito\n");
    while(!alarmFlag)
        pause();

    printf("Terminazione ciclo a causa del segnale di allarme\n");

    return 0;
}


