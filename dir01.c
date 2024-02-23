/*
esegue un 'ls -l' tramite exec()
*/

#include<unistd.h>
#include "sysmacro.h"

int main(int argc, char * argv[])
{

    if (argc != 2){
        WRITE("Usage: dir file\n");
        return 0;
    }
    
    //versione con execl
    execl("/bin/ls", "/bin/ls", "-l", argv[1], NULL);
    WRITE("** Errore exec non eseguita **\n");
    return 0;

}
