#include <stdio.h>
#include <math.h>

int main() {
    int paginaIni, paginaFin;
    int digitosIni, digitosFin;
    int paginasDigitos[7];
    int totalDigitos, maximoDigitos, actualDigitos;
    int paginaCambio;
    int i;

    while (true) {
        scanf("%d %d", &paginaIni, &paginaFin);
        if (paginaIni == 0) return 0;
 
        digitosIni = floor(log10(paginaIni))+1;
        digitosFin = floor(log10(paginaFin))+1;

        if (digitosIni == digitosFin) {
            paginasDigitos[digitosIni-1] = paginaFin-paginaIni+1;
        } else {
            paginasDigitos[digitosIni-1] = pow(10, digitosIni)-paginaIni;
            paginasDigitos[digitosFin-1] = paginaFin-pow(10, digitosFin-1)+1;
        }

        for (i = digitosIni+1; i < digitosFin; i++) {
            paginasDigitos[i-1] = pow(10, i-1)*9;
        }

        totalDigitos = 0;
        for (i = digitosIni; i <= digitosFin; i++) {
            totalDigitos += i*paginasDigitos[i-1];
        }

        maximoDigitos = totalDigitos/2;
        actualDigitos = 0;
        paginaCambio = paginaIni-1;
        for (i = digitosIni; i <= digitosFin; i++) {
            if (actualDigitos+i*paginasDigitos[i-1] > maximoDigitos) {
                paginaCambio += (maximoDigitos-actualDigitos)/i;
                break;
            } else {
                actualDigitos += i*paginasDigitos[i-1];
                paginaCambio += paginasDigitos[i-1];
            }
        }

        printf("%d\n", paginaCambio);
    }
}