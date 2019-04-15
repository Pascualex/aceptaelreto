#include <stdio.h>

int main() {
    int nGastos;
    int gastoAct, gastoTotal;
    int i;

    while (true) {
        scanf("%d", &nGastos);
        if (nGastos == 0) return 0;

        gastoTotal = 0;
        for (i = 0; i < nGastos; i++) {
            scanf("%d", &gastoAct);
            gastoTotal += gastoAct;
        }

        printf("%d\n", gastoTotal);
    }
}