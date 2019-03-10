#include <stdio.h>

int main() {
    int uvas;
    int niveles;
    int uvasAct;

    while (true) {
        scanf("%d", &uvas);
        if (uvas == 0) break;

        niveles = 1;
        uvasAct = 1;
        while (uvas > uvasAct) {
            niveles++;
            uvasAct += niveles;
        }

        printf("%d\n", niveles);
    }
}