#include <stdio.h>
#include <algorithm>

int main() {
    int nComensales;
    long long numerador, denominador;
    long long numeradorAct, denominadorAct;
    long long gcd;
    int i;

    while (true) {
        scanf("%d", &nComensales);
        if (nComensales == 0) return 0;

        scanf("%lld/%lld", &numerador, &denominador);
        for (i = 1; i < nComensales; i++) {
            scanf("%lld/%lld", &numeradorAct, &denominadorAct);
            if (denominador%denominadorAct != 0) {
                gcd = std::__gcd(denominador, denominadorAct);
                denominador *= denominadorAct/gcd;
                numerador *= denominadorAct/gcd;
            }
            numerador += numeradorAct*denominador/denominadorAct;
        }

        printf("%lld\n", denominador-numerador);
    }
}