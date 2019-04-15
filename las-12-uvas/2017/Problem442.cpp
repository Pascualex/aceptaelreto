#include <stdio.h>

int main() {
    char nombreIni[100];
    char nombreFin[100];
    char formato[100];
    int posIni, posFin;

    while (true) {
        scanf("%s %s", nombreIni, formato);
        if (feof(stdin)) return 0;

        posIni = 1;
        posFin = 1;
        if (formato[0] == 'C') {
            if (nombreIni[0] >= 97) nombreFin[0] = nombreIni[0]-32;
            else nombreFin[0] = nombreIni[0];

            while (nombreIni[posIni] != '\0') {
                if (nombreIni[posIni] == '_' || nombreIni[posIni] == '-') {
                    posIni++;
                    nombreFin[posFin] = nombreIni[posIni]-32;
                } else {
                    nombreFin[posFin] = nombreIni[posIni];
                }                
                posIni++;
                posFin++;
            }
        } else if (formato[0] == 's') {
            if (nombreIni[0] <= 90) nombreFin[0] = nombreIni[0]+32;
            else nombreFin[0] = nombreIni[0];

            while (nombreIni[posIni] != '\0') {
                if (nombreIni[posIni] == '-') {
                    nombreFin[posFin] = '_';
                } else if (nombreIni[posIni] >= 65 && nombreIni[posIni] <= 90) {
                    nombreFin[posFin] = '_';
                    posFin++;
                    nombreFin[posFin] = nombreIni[posIni]+32;
                } else {
                    nombreFin[posFin] = nombreIni[posIni];
                }                
                posIni++;
                posFin++;
            }
        } else {
            if (nombreIni[0] <= 90) nombreFin[0] = nombreIni[0]+32;
            else nombreFin[0] = nombreIni[0];

            while (nombreIni[posIni] != '\0') {
                if (nombreIni[posIni] == '_') {
                    nombreFin[posFin] = '-';
                } else if (nombreIni[posIni] >= 65 && nombreIni[posIni] <= 90) {
                    nombreFin[posFin] = '-';
                    posFin++;
                    nombreFin[posFin] = nombreIni[posIni]+32;
                } else {
                    nombreFin[posFin] = nombreIni[posIni];
                }                
                posIni++;
                posFin++;
            }
        }
        nombreFin[posFin] = '\0';

        printf("%s\n", nombreFin);
    }
}