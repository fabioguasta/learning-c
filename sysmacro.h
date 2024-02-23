/* File: sysmacro.h
Specifica: macro per chiamate di sistema
*/
#include <stdio.h> /* serve per la perror */
#include <stdlib.h> /* serve per la exit */
#include <string.h> /* serve per strlen */
#include <errno.h> /* serve per errno */
#include <unistd.h> /* serve per la write */

//IFERROR implementa lo schema semplificato di gestione degli errori, se non vogliamo terminare il programma utilizzeremo la macro IFERROR3
// Definizione della macro IFERROR
#define IFERROR(s,m) if((s)==-1) {perror(m); exit(errno);}
// Definizione della macro IFERROR3
#define IFERROR3(s,m,c) if((s)==-1) {perror(m); c;}

//WRITE e WRITELN scrivono una stringa (ed un ritorno carrello nel caso di WRITELN) sullo standard output invocando la chiamata di sistema write
// Definizione della macro WRITE
#define WRITE(m) IFERROR(write(STDOUT,m,strlen(m)), m);
// Definizione della macro WRITELN
#define WRITELN(m) WRITE(m);WRITE("\n");

// Definizione delle costanti per i file descriptor standard
#define STDIN 0
#define STDOUT 1
#define STDERR 2
