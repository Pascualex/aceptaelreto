#include <stdio.h>

int main() {
    int horas, minutos, segundos;
    int nCasos;

    scanf("%d", &nCasos);
    for (int i = 0; i < nCasos; i++) {
        scanf("%d:%d:%d", &horas, &minutos, &segundos);
        if (segundos != 0) {
            segundos = 60-segundos;
            minutos = 59-minutos;
            horas = 23-horas;
        } else {
            if (minutos != 0) {
                minutos = 60-minutos;
                horas = 23-horas;
            } else {
                horas = 24-horas;
            }            
        }
        printf("%02d:%02d:%02d\n", horas, minutos, segundos);
    }

    return 0;
}