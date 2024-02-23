/* include per chiamate sui processi */
#include <unistd.h>
/* include per chiamate sui file */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "sysmacro.h" /* macro di utilita’ */
int main(int argc, char *argv[])
{
    int fd;
    int pid, n;
    char buf[1000];
    IFERROR(fd = open("crea_io.c", O_RDONLY), "aprendo il file");
    IFERROR(pid = fork(), "generando il figlio");
    if (pid)
    {
        /* siamo nel padre */
        sleep(2); /* il processo si sospende per 2 secondi */
        IFERROR(n = read(fd, buf, 100), "leggendo");
        IFERROR(write(1, buf, n), "scrivendo");
    }
    else
    {
        /* siamo nel figlio */
        IFERROR(n = read(fd, buf, 100), "leggendo");
        IFERROR(write(1, buf, n), "scrivendo");
    }
    /* padre e figlio */
    printf("\n");
    return (0);
}

