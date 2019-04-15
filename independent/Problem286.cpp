#include <stdio.h>
#include <algorithm>

#define TAM 50001

int fechaADia(int dia, int mes, int ano);

int main() {
    int nViajes, nConsultas;
    int dia, mes, ano;
    int llegadas[TAM], salidas[TAM];
    int diaConsulta;
    int nLlegadasPrev, nSalidasPrev;
    int i;

    while (true) {
        scanf("%d", &nViajes);
        if (nViajes == 0) break;

        llegadas[0] = fechaADia(12, 6, 1968);
        for (int i = 0; i < nViajes; i++) {
            scanf("%d/%d/%d", &dia, &mes, &ano);
            salidas[i] = fechaADia(dia, mes, ano);
            scanf("%d/%d/%d", &dia, &mes, &ano);
            llegadas[i+1] = fechaADia(dia, mes, ano);
        }
        salidas[nViajes] = fechaADia(31, 12, 9999);

        std::sort(llegadas, llegadas+nViajes+1);
        std::sort(salidas, salidas+nViajes+1);

        scanf("%d", &nConsultas);
        for (int i = 0; i < nConsultas; i++) {
            scanf("%d/%d/%d", &dia, &mes, &ano);
            diaConsulta = fechaADia(dia, mes, ano);

            nLlegadasPrev = std::upper_bound(llegadas, llegadas+nViajes+1, diaConsulta)-llegadas;
            nSalidasPrev = std::lower_bound(salidas, salidas+nViajes+1, diaConsulta)-salidas;

            printf("%d\n", nLlegadasPrev-nSalidasPrev);
        }
        printf("----\n");
    }

    return 0;
}

int fechaADia(int dia, int mes, int ano) {
    int totalDias = ano*365;

    if (mes == 2) totalDias += 31;
    else if (mes == 3) totalDias += 59;
    else if (mes == 4) totalDias += 90;
    else if (mes == 5) totalDias += 120;
    else if (mes == 6) totalDias += 151;
    else if (mes == 7) totalDias += 181;
    else if (mes == 8) totalDias += 212;
    else if (mes == 9) totalDias += 243;
    else if (mes == 10) totalDias += 273;
    else if (mes == 11) totalDias += 304;
    else if (mes == 12) totalDias += 334;

    return totalDias+dia;
}