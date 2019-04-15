#include <stdio.h>
#include <string.h>

char palabra[1001];
int maximos[1000][1000];

int encontrarMayorPalindromo(int primero, int segundo) {
    int maxD, maxI;

    if (primero == segundo) return 1;
    if (primero > segundo) return 0;

    if (maximos[primero][segundo] == -1) {
        if (palabra[primero] == palabra[segundo]) {
            maximos[primero][segundo] = 2+encontrarMayorPalindromo(primero+1, segundo-1);
        } else {
            maxD = encontrarMayorPalindromo(primero+1, segundo);
            maxI = encontrarMayorPalindromo(primero, segundo-1);

            if (maxD >= maxI) {
                maximos[primero][segundo] = maxD;
            } else {
                maximos[primero][segundo] = maxI;
            }
        }
    }

    return maximos[primero][segundo];
}

void imprimirMayorPalindromo(int primero, int segundo) {
    if (primero == segundo) printf("%c", palabra[primero]);
    if (primero >= segundo) return;

    if (palabra[primero] == palabra[segundo]) {
        printf("%c", palabra[primero]);
        imprimirMayorPalindromo(primero+1, segundo-1);
        printf("%c", palabra[segundo]);
    } else {
        if (maximos[primero+1][segundo] >= maximos[primero][segundo-1]) {
            imprimirMayorPalindromo(primero+1, segundo);
        } else {
            imprimirMayorPalindromo(primero, segundo-1);
        }
    }
}

int main() {
    int tam;
    int i, j;

    while (true) {
        scanf("%s", palabra);
        if (feof(stdin)) return 0;

        tam = strlen(palabra);

        for (i = 0; i < tam-1; i++) {
            for (j = i+1; j < tam; j++) {
                maximos[i][j] = -1;
            }
        }

        encontrarMayorPalindromo(0, tam-1);

        imprimirMayorPalindromo(0, tam-1);
        printf("\n");
    }
}