/*
esempio utilizzo alarm
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sysmacro.h"

int main()
{
    alarm(3); //predispone l'invio di un segnare di allarme dopo 3 secondi

    printf("Ciclo infinito\n");
    while(1);
    printf("Mai eseguita");
    return 0;
}