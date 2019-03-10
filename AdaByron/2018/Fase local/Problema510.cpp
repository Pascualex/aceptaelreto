#include <stdio.h>
#include <algorithm>

int main() {
    int nZapatos;
    int zapatoAct;
    int posPositivos[1000];
    int positivos[1000], nPositivos, nPositivosAct;
    int negativos[1000], nNegativos, nNegativosAct;
    int i;

    while (true) {
        scanf("%d", &nZapatos);
        if (nZapatos == 0) return 0;

        nPositivos = 0;
        nNegativos = 0;
        for (i = 0; i < nZapatos; i++) {
            scanf("%d", &zapatoAct);
            
            if (zapatoAct > 0) {
                posPositivos[i] = 1;
                positivos[nPositivos] = zapatoAct;
                nPositivos++;
            } else {
                posPositivos[i] = 0;
                negativos[nNegativos] = zapatoAct;
                nNegativos++;
            }
        }

        std::sort(positivos, positivos+nPositivos);
        std::sort(negativos, negativos+nNegativos);

        nPositivosAct = 0;
        nNegativosAct = 0;
        for (i = 0; i < nZapatos-1; i++) {
            if (posPositivos[i] == 1) {
                printf("%d ", positivos[nPositivosAct]);
                nPositivosAct++;
            } else {
                printf("%d ", negativos[nNegativos-nNegativosAct-1]);
                nNegativosAct++;
            }
        }

        if (posPositivos[nZapatos-1] == 1) {
            printf("%d\n", positivos[nPositivosAct]);
        } else {
            printf("%d\n", negativos[nNegativos-nNegativosAct-1]);
        }
    }
}