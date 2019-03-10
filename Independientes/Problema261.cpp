#include <stdio.h>

int main() {

    int repeticiones, suma, cara, resto, i;

    scanf("%d", &repeticiones);

    for (i = 0; i < repeticiones; i++) {
        scanf("%d", &suma);
        scanf("%d", &cara);

        if (suma == 1000) {
            printf("GANA\n");
            continue;
        }

        resto = suma%9;

        switch (resto) {
            case 0:
                printf("PIERDE\n");
                break;
            case 1:
                if (cara == 3 || cara == 4) {
                    printf("PIERDE\n");
                } else {
                    printf("GANA\n");
                }
                break;
            case 2:
                printf("GANA\n");
                break;
            case 3:
                printf("GANA\n");
                break;
            case 4:
                if (cara == 2 || cara == 5) {
                    printf("PIERDE\n");
                } else {
                    printf("GANA\n");
                }
                break;
            case 5:
                if (cara == 3 || cara == 4) {
                    printf("PIERDE\n");
                } else {
                    printf("GANA\n");
                }
                break;
            case 6:
                if (cara == 3 || cara == 4) {
                    printf("PIERDE\n");
                } else {
                    printf("GANA\n");
                }
                break;
            case 7:
                printf("GANA\n");
                break;
            case 8:
                if (suma != 998) {
                    printf("GANA\n");
                } else {
                    if (cara == 1 || cara == 6) {
                        printf("PIERDE\n");
                    } else {
                        printf("GANA\n");
                    }
                }
                break;
        }
    }
}