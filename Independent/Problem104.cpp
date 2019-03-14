#include <stdio.h>

int balanceado(int pi, int di, int pd, int dd) {
    int piAux, diAux, pdAux, ddAux;

    if (pi == 0) {
        scanf("%d %d %d %d", &piAux, &diAux, &pdAux, &ddAux);
        pi = balanceado(piAux, diAux, pdAux, ddAux);
    }

    if (pd == 0) {
        scanf("%d %d %d %d", &piAux, &diAux, &pdAux, &ddAux);
        pd = balanceado(piAux, diAux, pdAux, ddAux);
    }

    if (pi == -1 || pd == -1) return -1;

    if (pi*di == pd*dd) return pi+pd;
    else return -1;
}

int main() {
    int pi, di, pd, dd;

    while (true) {
        scanf("%d %d %d %d", &pi, &di, &pd, &dd);
        if (pi == 0 && di == 0 && pd == 0 && dd == 0) return 0;

        if (balanceado(pi, di, pd, dd) != -1) {
            printf("SI\n");
        } else {
            printf("NO\n");
        }
    }
}