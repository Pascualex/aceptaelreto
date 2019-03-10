#include <stdio.h>

int main() {
    int nCasos;
    char t1, t2;
    int d1, d2;

    scanf("%d", &nCasos);
    for (int i = 0; i < nCasos; i++) {
        scanf(" %c=%d %c=%d", &t1, &d1, &t2, &d2);

        if (t1 == 'D') {
            if (t2 == 'T') {
                printf("V=%d\n", d1/d2);
            } else {
                printf("T=%d\n", d1/d2);
            }
        } else if (t1 == 'T') {
            if (t2 == 'D') {
                printf("V=%d\n", d2/d1);
            } else {
                printf("D=%d\n", d1*d2);
            }
        } else {
            if (t2 == 'D') {
                printf("T=%d\n", d2/d1);
            } else {
                printf("D=%d\n", d1*d2);
            }
        }
    }
}