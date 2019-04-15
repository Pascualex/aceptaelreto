#include <stdio.h>

int main() {
    int a, b;
    int i, num;

    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        scanf("%d / %d", &a, &b);
        if (a >= b) printf("BIEN\n");
        else printf("MAL\n");
    }    
}