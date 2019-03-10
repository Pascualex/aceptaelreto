#include <stdio.h>

int main() {
    int nCasos;
    int nDias;
    int balanceDia, balanceActual, balanceMax;
    int inicioAct, inicioMax, finMax;
    int longitudAct, longitudMin;
    int i, j;

    scanf("%d", &nCasos);

    for (i = 0; i < nCasos; i++) {
        scanf("%d", &nDias);

        inicioAct = 0;
        balanceActual = 0;
        balanceMax = 0;
        longitudAct = 0;

        for (j = 0; j < nDias; j++) {
            scanf("%d", &balanceDia);
            balanceActual += balanceDia;
            longitudAct++;

            if (balanceActual > balanceMax || (balanceActual == balanceMax && longitudAct < longitudMin)) {
                balanceMax = balanceActual;
                inicioMax = inicioAct;
                finMax = j;
                longitudMin = longitudAct;
            }

            if (balanceActual <= 0) {
                balanceActual = 0;
                inicioAct = j+1;
                longitudAct = 0;
            }
        }

        printf("%d %d\n", inicioMax+1, finMax+1);
    }
}