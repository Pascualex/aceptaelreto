#include <stdio.h>

#define TAM 20001

// U = UNKNONW, Y = YES, N = NO
char valores[TAM];

bool comprobarValor(int valorAct) {
    if (valores[valorAct] == 'Y') {
        return true;
    } else if (valores[valorAct] == 'N') {
        return false;
    } else {
        if (valorAct-5 >= 1) {
            if (valorAct%3 == 0) {
                if (comprobarValor(valorAct-5) || comprobarValor(valorAct/3)) {
                    valores[valorAct] = 'Y';
                    return true;
                } else {
                    valores[valorAct] = 'N';
                    return false;
                }
            } else {
                if (comprobarValor(valorAct-5)) {
                    valores[valorAct] = 'Y';
                    return true;
                } else {
                    valores[valorAct] = 'N';
                    return false;
                }
            }
        } else {
            if (valorAct%3 == 0) {
                if (comprobarValor(valorAct/3)) {
                    valores[valorAct] = 'Y';
                    return true;
                } else {
                    valores[valorAct] = 'N';
                    return false;
                }
            } else {
                valores[valorAct] = 'N';
                return false;
            }
        }
    }
}

int main() {
    int valorAct;
    int i;

    valores[1] = 'Y';
    for (i = 2; i < TAM; i++) valores[i] = 'U';
    
    while (true) {
        scanf("%d", &valorAct);
        if (valorAct == 0) return 0;

        if (comprobarValor(valorAct) == true) {
            printf("SI\n");
        } else {
            printf("NO\n");
        }
    }
}