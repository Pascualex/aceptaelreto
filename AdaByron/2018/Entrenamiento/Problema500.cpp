#include <stdio.h>

int main() {
    int capicuasVotos[9000];
    int N, Q;
    int M;
    int i, inverso;

    for (i = 0; i < 9000; i++) {
        capicuasVotos[i] = 0;
    }

    for (i = 0; i <= 9999; i++) {        
        inverso = i%10*1000+(i/10)%10*100+(i/100)%10*10+i/1000;

        if (i+inverso >= 1000 && i+inverso <= 9999) capicuasVotos[i+inverso-1000]++;
    }

    while (true) {
        scanf("%d %d", &N, &Q);
        if (N == 0) return 0;

        M = 0;
        for (i = Q; i <= N; i++) M += capicuasVotos[i-1000];

        printf("%d %d %d\n", N, Q, M);
    }
}