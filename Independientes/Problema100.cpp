#include <stdio.h>

void BubbleSort(int dig[4]);

int main() {
    int nEntradas;

    scanf("%d", &nEntradas);

    for (int i = 0; i < nEntradas; i++) {
        int numero;
        int numeroInv;
        int dig[4];            

        scanf("%d", &numero);

        int contador = 0;
        while (numero != 6174 && numero != 0000) {
            contador++;

            dig[3] = numero/1000;
            dig[2] = numero/100%10;
            dig[1] = numero/10%10;
            dig[0] = numero%10;

            BubbleSort(dig);

            numero = dig[3]*1000+dig[2]*100+dig[1]*10+dig[0];
            numeroInv = dig[0]*1000+dig[1]*100+dig[2]*10+dig[3];

            if (numero > numeroInv) numero = numero-numeroInv;
            else numero = numeroInv-numero;
        }

        if (numero == 0000) printf("8\n");
        else printf("%d\n", contador);
    }
}

void BubbleSort(int dig[4]) {
    for (int i = 3; i >= 0; i--) {
        for (int j = 0; j < i; j++) {                
            if (dig[j] > dig[j+1]) {
                int aux = dig[j];
                dig[j] = dig[j+1];
                dig[j+1] = aux;
            }
        }
    }
}