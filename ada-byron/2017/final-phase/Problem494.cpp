#include <stdio.h>

int main() {
    int tamSerie;
    int serie[1000];
    int actualNum, ultimoNum;
    int posActual, backup;
    int i;

    while (true) {
        scanf("%d", &tamSerie);
        if (tamSerie == 0) return 0;

        posActual = 0;
        backup = 0;
        scanf("%d", &ultimoNum);
        for (i = 0; i < tamSerie-1; i++) {
            scanf("%d", &actualNum);
            serie[i] = actualNum-ultimoNum;
            ultimoNum = actualNum;
        }

        for (i = 0; i < tamSerie-1; i++) {
            if (i != 0 && serie[i] == serie[posActual]) {
                posActual++;                
            } else {
                posActual = 0;
                i = backup;
                backup++;
            }
        }

        printf("%d\n", ultimoNum+serie[posActual]);
    }
}