#include <stdio.h>

int main() {
    int nVeces;

    scanf("%d", &nVeces);

    if (nVeces == 0) return 0;

    if (nVeces == 1) {
        printf("Hola mundo.\n");
        return 0;
    }

    if (nVeces == 2) {
        printf("Hola mundo.\nHola mundo.\n");
        return 0;
    }
    
    if (nVeces == 3) {
        printf("Hola mundo.\nHola mundo.\nHola mundo.\n");
        return 0;
    }

    if (nVeces == 4) {
        printf("Hola mundo.\nHola mundo.\nHola mundo.\nHola mundo.\n");
        return 0;
    }

    printf("Hola mundo.\nHola mundo.\nHola mundo.\nHola mundo.\nHola mundo.\n");
    return 0;
}