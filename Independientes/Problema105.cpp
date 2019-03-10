#include <stdio.h>

void imprimirDia(int dia) {
    if (dia == -1) {
        printf("EMPATE ");
    } else if (dia == 0) {
        printf("MARTES ");
    } else if (dia == 1) {
        printf("MIERCOLES ");
    } else if (dia == 2) {
        printf("JUEVES ");
    } else if (dia == 3) {
        printf("VIERNES ");
    } else if (dia == 4) {
        printf("SABADO ");
    } else {
        printf("DOMINGO ");
    }
}

int main() {
    float dias[6];
    float max, min, media;
    int diaMax, diaMin;
    int i;

    while (true) {
        scanf("%f", &dias[0]);
        if (dias[0] == -1) return 0;

        media = dias[0];
        for (i = 1; i < 6; i++) {
            scanf("%f", &dias[i]);
            media += dias[i];
        }
        media /= 6;

        diaMax = diaMin = 0;
        max = min = dias[0];
        for (i = 1; i < 6; i++) {
            if (dias[i] > max) {
                max = dias[i];
                diaMax = i;
            } else if (dias[i] == max) {
                diaMax = -1;
            }

            if (dias[i] < min) {
                min = dias[i];
                diaMin = i;
            } else if (dias[i] == min) {
                diaMin = -1;
            }
        }

        imprimirDia(diaMax);
        imprimirDia(diaMin);

        if (dias[5] > media) {
            printf("SI\n");
        } else {
            printf("NO\n");
        }
    }
}