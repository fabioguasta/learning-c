#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Verifica se un percorso è una directory
int isdirectory(const char *path) {
    DIR* dir = opendir(path);
    if (dir) {
        closedir(dir);
        return 1;
    } else {
        return 0;
    }
}

// Concatena due stringhe
char * concatena(const char *s1, const char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 per il carattere null
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

// Concatena tre stringhe
char * concatena3(const char *s1, const char *s2, const char *s3) {
    char *result = malloc(strlen(s1) + strlen(s2) + strlen(s3) + 1); // +1 per il carattere null
    strcpy(result, s1);
    strcat(result, s2);
    strcat(result, s3);
    return result;
}

// Divide una stringa in base a un delimitatore
char ** split_arg(char *str, char* delim, int *count) {
    char **res = NULL;
    char *p = strtok(str, delim);
    int n_spaces = 0;

    while (p) {
        res = realloc(res, sizeof(char*) * ++n_spaces);
        res[n_spaces-1] = p;
        p = strtok(NULL, delim);
    }

    *count = n_spaces;
    return res;
}

// Libera la memoria allocata per un array di stringhe
void free_args(char **args) {
    free(args);
}