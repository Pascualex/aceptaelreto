#include <stdio.h>

int main() {
    int uvasT, uvasM, uvasG;
    int uvasF;
    int nCasos;
    int i;

    scanf("%d", &nCasos);
    for (i = 0; i < nCasos; i++) {
        scanf("%d %d %d", &uvasT, &uvasM, &uvasG);

        uvasF = uvasT/uvasG*uvasM;
        if (uvasT%uvasG > uvasM) {
            uvasF += uvasM;
        } else {
            uvasF += uvasT%uvasG;
        }

        printf("%d\n", uvasF);
    }
}