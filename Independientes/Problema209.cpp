#include <stdio.h>
#include <string.h>

#define TAM 1000000

int busqueda_binaria(int telefonos[TAM], int nTelefonos, int pos);

int main() {
    char tunel[TAM];
    int tamTunel;
    int telefonos[TAM];
    int nTelefonos;
    int nConsultas, pos, pPos, inf, sup;
    int i;

    while (true) {
        scanf("%s", tunel);
        if (feof(stdin)) return 0;

        tamTunel = strlen(tunel);

        telefonos[0] = 0;
        nTelefonos = 1;
        for (i = 0; i < tamTunel; i++) {
            if (tunel[i] == 'T') {
                telefonos[nTelefonos] = i+1;
                nTelefonos++;
            }
        }
        telefonos[nTelefonos] = tamTunel+1;
        nTelefonos++;

        scanf("%d", &nConsultas);
        for (i = 0; i < nConsultas; i++) {
            scanf("%d", &pos);
            pPos = busqueda_binaria(telefonos, nTelefonos, pos);
            sup = telefonos[pPos];
            if (sup == pos) {
                printf("AQUI\n");
                continue;
            }

            inf = telefonos[pPos-1];
            
            inf = pos-inf;
            sup = sup-pos;

            if (inf < sup) printf("PENINSULA\n");
            else if (sup < inf) printf("ISLAS\n");
            else {
                if (pos <= (tamTunel+1)/2) {
                    printf("PENINSULA\n");
                } else {
                    printf("ISLAS\n");
                }
            }
        }
    }

    return 0;
}

int busqueda_binaria(int telefonos[TAM], int nTelefonos, int pos) {
    int min = 0;
    int max = nTelefonos-1;
    int act;

    while (min < max) {
        act = min+(max-min)/2;
        if (telefonos[act] > pos) max = act-1;
        else if (telefonos[act] < pos) min = act+1;
        else return act;
    }

    act = min+(max-min)/2;
    if (telefonos[act] >= pos) return min;
    else return min+1;
}