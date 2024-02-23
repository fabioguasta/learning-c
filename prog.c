#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *path = getenv("PATH");
    if(path == NULL) {
        printf("PATH variable is not set.\n");
        return 1;
    }

    char *token = strtok(path, ":");
    while(token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ":");
    }

    return 0;
}