#include <stdio.h>

int main() {
    int nMuestras, umbral;
    int act, actC, max, umbralAct;
    int aux, i;

    while (true) {
        scanf("%d %d", &nMuestras, &umbral);
        if (nMuestras == 0 && umbral == 0) break;

        act = 0;
        actC = 0;
        umbralAct = 100001;
        max = 0;
        for (i = 0; i < nMuestras; i++) {
            scanf("%d", &aux);
            act++;
            if (aux == 1) {
                umbralAct = 0;    
                actC = act;
                if (actC > max) max = actC;
            } else {
                umbralAct++;
                if (umbralAct > umbral) act = 0;
            }
        }
        if (actC > max) max = actC;

        printf("%d\n", max);
    }

    return 0;
}