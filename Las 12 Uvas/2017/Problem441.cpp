#include <stdio.h>
#include <string.h>

int main() {
    char numero[1001];
    int tamNumero;
    int posAct;

    while (true) {
        scanf("%s", &numero);
        if (feof(stdin)) return 0;

        tamNumero = strlen(numero);

        posAct = 0;
        while (posAct < tamNumero) {
            if (numero[tamNumero-1-posAct] == '.') {
                posAct++;
            } else if (numero[tamNumero-1-posAct] == '9') {
                numero[tamNumero-1-posAct] = '0';
                posAct++;
            } else {
                numero[tamNumero-1-posAct]++;                
                printf("%s\n", numero);
                break;
            }
        }

        if (posAct == tamNumero) {
            if (tamNumero%4 == 3) {
                printf("1.%s\n", numero);
            } else {
                printf("1%s\n", numero);
            }
        }    
    }
}