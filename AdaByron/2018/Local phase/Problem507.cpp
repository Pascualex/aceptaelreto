#include <stdio.h>
#include <algorithm>

int personas[200000];
int nLecturas, pesoMax;
int pesoActual;
int nPersonas;
int maxAct;
long long combinaciones, posMax;
int i;

int main() {   

    while (true) {
        scanf("%d %d", &nLecturas, &pesoMax);
        if (nLecturas == 0) return 0;

        nPersonas = 0;        
        for (i = 0; i < nLecturas; i++) {
            scanf("%d", &pesoActual);
            if (pesoActual <= pesoMax) {
                personas[nPersonas] = pesoActual;
                nPersonas++;
            }
        }

        std::sort(personas, &personas[nPersonas]);

        combinaciones = 0;
        for (i = 0; i < nPersonas-1; i++) {
            maxAct = pesoMax-personas[i];
            posMax = std::upper_bound(&personas[i+1], &personas[nPersonas], maxAct)-&personas[i+1];
            if (posMax == 0) {
                break;
            } else {
                combinaciones += posMax;
            }
        }

        printf("%lld\n", combinaciones);
    }
}