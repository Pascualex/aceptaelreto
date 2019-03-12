#include <stdio.h>
#include <algorithm>

int main() {
    long long a, b, numero;
    long long mcm;

    while (true) {
        scanf("%lld %lld %lld", &a, &b, &numero);
        if (a == 0) return 0;

        mcm = (a*b)/std::__gcd(a, b);

        printf("%lld\n", numero/mcm);
    }
}