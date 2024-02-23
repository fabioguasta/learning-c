#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Hello, ";
    char str2[50] = "World!";
    char str3[50];

    // strlen: get the length of a string
    printf("Length of string str1: %lu\n", strlen(str1));

    // strcat: concatenate two strings
    strcat(str1, str2);
    printf("str1 after concatenation: %s\n", str1);

    // strcpy: copy a string
    strcpy(str3, str1);
    printf("str3 after copying str1: %s\n", str3);

    // strcmp: compare two strings
    int cmp = strcmp(str1, str3);
    if(cmp == 0) {
        printf("str1 and str3 are equal\n");
    } else {
        printf("str1 and str3 are not equal\n");
    }

    // strchr: find first occurrence of a character in a string
    char *ch = strchr(str1, 'W');
    if(ch != NULL) {
        printf("First occurrence of 'W' in str1: %s\n", ch);
    }

    // strstr: find a substring in a string
    char *substr = strstr(str1, "World");
    if(substr != NULL) {
        printf("Substring 'World' found in str1: %s\n", substr);
    }

    return 0;
}