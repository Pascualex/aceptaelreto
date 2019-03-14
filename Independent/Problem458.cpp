#include <stdio.h>

int main() {
    int nNumeros;
    long long maxPos1, maxPos2;
    long long maxNeg1, maxNeg2;
    long long actual;
    long long resPos, resNeg;
    int i;

    while (true) {
        scanf("%d", &nNumeros);
        if (nNumeros == 0) return 0;

        maxPos1 = maxPos2 = 0;
        maxNeg1 = maxNeg2 = 0;

        if (nNumeros == 2) {
            scanf("%lld", &actual);
            resPos = actual;
            scanf("%lld", &actual);
            resPos *= actual;
            printf("%lld\n", resPos);
            continue;
        }

        for (i = 0; i < nNumeros; i++) {
            scanf("%lld", &actual);

            if (actual >= 0) {
                if (actual > maxPos1) {
                    maxPos2 = maxPos1;
                    maxPos1 = actual;
                } else if (actual > maxPos2) {
                    maxPos2 = actual;
                }
            } else {
                if (actual < maxNeg1) {
                    maxNeg2 = maxNeg1;
                    maxNeg1 = actual;
                } else if (actual < maxNeg2) {
                    maxNeg2 = actual;
                }
            }
        }

        resPos = maxPos1*maxPos2;
        resNeg = maxNeg1*maxNeg2;

        if (resPos >= resNeg) {
            printf("%lld\n", resPos);
        } else {
            printf("%lld\n", resNeg);
        }
    }
}