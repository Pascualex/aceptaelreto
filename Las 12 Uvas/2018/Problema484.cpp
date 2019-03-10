#include <stdio.h>

int main() {
    char numero[1100];
    int ini, i;
    bool flag, decimal;

    while (true) {
        scanf("%s", numero);
        if (feof(stdin)) return 0;

        flag = false;
        decimal = false;
        i = 0;
        while (numero[i] != '\0') {
            if (numero[i] == '.') {
                if (flag == false) {
                    ini = i-1;
                    flag = true;
                }
                decimal = true;
            } else {
                if (flag == false && numero[i] != '0') {
                    ini = i;
                    flag = true;
                }
            }
            i++;
        }           

        if (flag == false) {
            printf("0\n");
            continue;
        }

        if (decimal == true) {
            i--;
            while (true) {
                if (numero[i] == '.') {
                    numero[i] = '\0';
                    break;
                } else if (numero[i] != '0') {
                    numero[i+1] = '\0';
                    break;
                }
                i--;
            }
        }

        printf("%s\n", &numero[ini]);
    }
}