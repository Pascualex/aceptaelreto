#include <stdio.h>
#include <stdlib.h>

int main() {
    bool visitados[10000];
    int *rondaAct, *rondaSig, *auxP;
    int tamRondaAct, tamRondaSig;
    int inicial, objetivo;
    int costeActual;
    int aux, i;

    rondaAct = (int *) malloc(sizeof(int)*10000);
    rondaSig = (int *) malloc(sizeof(int)*10000);

    while (true) {
        scanf("%d %d", &inicial, &objetivo);
        if (feof(stdin)) return 0;

        if (inicial == objetivo) {
            printf("0\n");
            continue;
        }

        for (i = 0; i < 10000; i++) {
            visitados[i] = false;
        }

        visitados[inicial] = true;
        rondaSig[0] = inicial;
        tamRondaSig = 1;
        costeActual = 1;
        while (true) {
            auxP = rondaAct;
            rondaAct = rondaSig;
            rondaSig = auxP;

            tamRondaAct = tamRondaSig;
            tamRondaSig = 0;

            for (i = 0; i < tamRondaAct; i++) {
                aux = (rondaAct[i]+1)%10000;
                if (visitados[aux] == false) {
                    if (aux == objetivo) break;
                    visitados[aux] = true;
                    rondaSig[tamRondaSig] = aux;
                    tamRondaSig++;                    
                }

                aux = (rondaAct[i]*2)%10000;
                if (visitados[aux] == false) {
                    if (aux == objetivo) break;
                    visitados[aux] = true;
                    rondaSig[tamRondaSig] = aux;
                    tamRondaSig++;                    
                }

                aux = (rondaAct[i]/3)%10000;
                if (visitados[aux] == false) {
                    if (aux == objetivo) break;
                    visitados[aux] = true;
                    rondaSig[tamRondaSig] = aux;
                    tamRondaSig++;                    
                }
            }

            if (i != tamRondaAct) break;

            costeActual++;
        }

        printf("%d\n", costeActual);
    }
}