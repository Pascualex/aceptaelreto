#include <stdio.h>
#include <string.h>

int main() {
    char numero[1001];
    int tamNumero;
    int digitos[10];
    int i;

    while (true) {
        scanf("%s", numero);
        if (feof(stdin)) return 0;
        tamNumero = strlen(numero);

        if (tamNumero%10 != 0) {
            printf("no subnormal\n");
            continue;
        }

        for (i = 0; i < 10; i++) digitos[i] = 0;

        for (i = 0; i < tamNumero; i++) {
            digitos[numero[i]-48]++;
            if (digitos[numero[i]-48] > tamNumero/10) break;
        }

        if (i != tamNumero) {
            printf("no subnormal\n");
            continue;
        }

        for (i = 0; i < 10; i++) {
            if (digitos[i] != tamNumero/10) break;
        }

        if (i == 10) printf("subnormal\n");
        else printf("no subnormal\n");
    }
}