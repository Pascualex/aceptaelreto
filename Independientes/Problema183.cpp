#include <stdio.h>

void crecer(int nFases, char anilloAct) {
    if (nFases == 1) {
        if (anilloAct == 'A') {
            printf("AN");
        } else {
            printf("NA");
        }
    } else {
        if (anilloAct == 'A') {
            crecer(nFases-1, 'A');
            crecer(nFases-1, 'N');
        } else {
            crecer(nFases-1, 'N');
            crecer(nFases-1, 'A');
        }
    }
}

int main() {
    int nFases;
    char orugaIni[10000];
    int tamOrugaFin;
    int i;

    while (true) {
        scanf("%d %s", &nFases, orugaIni);
        if (orugaIni[0] == 'C') return 0;

        if (nFases == 0) {
            printf("%s\n", orugaIni);
            continue;
        }

        i = 0;
        tamOrugaFin = 0;
        while (orugaIni[i] != 'C') {
            crecer(nFases, orugaIni[i]);
            i++;
        }

        printf("C\n");
    }
}