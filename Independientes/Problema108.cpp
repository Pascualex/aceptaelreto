#include <stdio.h>

int main() {
    char categoria;
    float valor, beneficiosC[5], beneficiosT, max, min;
    int ventasT, ventasCom, maxC, minC, i;

    for (i = 0; i < 5; i++) beneficiosC[i] = 0;
    ventasT = 0;
    ventasCom = 0;

    while (true) {
        scanf(" %c %f", &categoria, &valor);
        if (feof(stdin)) return 0;

        if (categoria == 'N') {
            max = beneficiosC[0];
            maxC = 0;
            min = beneficiosC[0];
            minC = 0;
            for (i = 1; i < 5; i++) {
                if (beneficiosC[i] > max) {
                    max = beneficiosC[i];
                    maxC = i;
                } else if (beneficiosC[i] == max) maxC = -1;
                if (beneficiosC[i] < min) {
                    min = beneficiosC[i];
                    minC = i;
                } else if (beneficiosC[i] == min) minC = -1;                
            }

            if (maxC == -1) printf("EMPATE#");
            else if (maxC == 0) printf("DESAYUNOS#");
            else if (maxC == 1) printf("COMIDAS#");
            else if (maxC == 2) printf("MERIENDAS#");
            else if (maxC == 3) printf("CENAS#");
            else if (maxC == 4) printf("COPAS#");

            if (minC == -1) printf("EMPATE#");
            else if (minC == 0) printf("DESAYUNOS#");
            else if (minC == 1) printf("COMIDAS#");
            else if (minC == 2) printf("MERIENDAS#");
            else if (minC == 3) printf("CENAS#");
            else if (minC == 4) printf("COPAS#");
            
            beneficiosT = beneficiosC[0];
            for (i = 1; i < 5; i++) beneficiosT += beneficiosC[i];
            if (beneficiosC[1]/ventasCom > beneficiosT/ventasT) printf("SI\n");
            else printf("NO\n");

            for (i = 0; i < 5; i++) beneficiosC[i] = 0;
            ventasT = 0;
            ventasCom = 0;
        } else {
            if (categoria == 'D') i = 0;
            else if (categoria == 'A') { i = 1; ventasCom++; }
            else if (categoria == 'M') i = 2;
            else if (categoria == 'I') i = 3;
            else if (categoria == 'C') i = 4;            

            beneficiosC[i] += valor;
            ventasT++;
        }        
    }
}