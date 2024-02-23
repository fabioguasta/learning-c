#include <stdio.h>

int main() {
    int a = 10;
    int b = 3;
    int c;

    // Operatori aritmetici
    c = a + b; // Addizione
    printf("a + b = %d\n", c);

    c = a - b; // Sottrazione
    printf("a - b = %d\n", c);

    c = a * b; // Moltiplicazione
    printf("a * b = %d\n", c);

    c = b / a; // Divisione
    printf("b / a = %d\n", c);

    c = b % a; // Modulo
    printf("b %% a = %d\n", c);

    // Operatori di incremento e decremento
    c = a++; // Post-incremento
    printf("a++ = %d\n", c);

    c = a--; // Post-decremento
    printf("a-- = %d\n", c);    

    c = ++a; // Pre-incremento
    printf("++a = %d\n", c);

    c = --a; // Pre-decremento
    printf("--a = %d\n", c);

    // Operatori di confronto
    if (a == b) printf("a == b\n"); // Uguaglianza
    if (a != b) printf("a != b\n"); // Diverso
    if (a > b) printf("a > b\n");   // Maggiore
    if (a < b) printf("a < b\n");   // Minore
    if (a >= b) printf("a >= b\n"); // Maggiore o uguale
    if (a <= b) printf("a <= b\n"); // Minore o uguale

    // Operatori logici
    if (a && b) printf("a && b\n"); // AND
    if (a || b) printf("a || b\n"); // OR
    if (!a) printf("!a\n");        // NOT

    // Operatori bitwise
    c = a & b; // AND
    printf("a & b = %d\n", c);

    c = a | b; // OR
    printf("a | b = %d\n", c);

    c = a ^ b; // XOR
    printf("a ^ b = %d\n", c);

    c = ~a; // NOT
    printf("~a = %d\n", c);

    c = a << 2; // Shift a sinistra
    printf("a << 2 = %d\n", c);

    c = a >> 2; // Shift a destra
    printf("a >> 2 = %d\n", c);

    // Operatori di assegnazione
    c = a;
    printf("c = a: %d\n", c);

    c += a; // c = c + a
    printf("c += a: %d\n", c); 

    c -= a; // c = c - a
    printf("c -= a: %d\n", c);

    c *= a; // c = c * a
    printf("c *= a: %d\n", c);

    c /= a; // c = c / a
    printf("c /= a: %d\n", c);

    c %= a; // c = c % a
    printf("c %= a: %d\n", c);

    c &= a; // c = c & a
    printf("c &= a: %d\n", c);

    c |= a; // c = c | a
    printf("c |= a: %d\n", c);

    c ^= a; // c = c ^ a
    printf("c ^= a: %d\n", c);

    c <<= 2; // c = c << 2
    printf("c <<= 2: %d\n", c);

    c >>= 2; // c = c >> 2
    printf("c >>= 2: %d\n", c);

    return 0;
}