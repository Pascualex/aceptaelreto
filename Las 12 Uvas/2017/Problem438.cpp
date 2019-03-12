#include <stdio.h>

int main() {
    char mensaje[1002];
    int nExclamaciones, nLetras;
    int i;

    while (fgets(mensaje, 1002, stdin) != NULL) {
        nExclamaciones = 0;
        nLetras = 0;
        i = 0;
        while (mensaje[i] != '\n') {
            if (mensaje[i] == '!') nExclamaciones++;
            else if (mensaje[i] >= 65 && mensaje[i] <= 90 || mensaje[i] >= 97 && mensaje[i] <= 122) nLetras++;
            i++;
        }

        if (nExclamaciones > nLetras) {
            printf("ESGRITO\n");
        } else {
            printf("escrito\n");
        }
    }

    return 0;
}