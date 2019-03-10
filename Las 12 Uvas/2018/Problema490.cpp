#include <stdio.h>

int main() {
    // CAMBIAR A 500.000
    long long calles[5000];
    long long asombroAct, asombroMax;
    int nCalles, nVisitas;
    int i;

    while (true) {
        scanf("%d %d", &nCalles, &nVisitas);
        if (feof(stdin)) return 0;

        for (i = 0; i < nCalles; i++) {
            scanf("%lld", &calles[i]);
        }

        asombroMax = 0;
        for (i = 0; i < nCalles-(nVisitas-1); i++) {
            asombroAct = calles[i+(nVisitas-1)]-calles[i];
            if (asombroAct > asombroMax) asombroMax = asombroAct;
            else if (-asombroAct > asombroMax) asombroMax = -asombroAct;
        }

        printf("%lld\n", asombroMax);
    }
}