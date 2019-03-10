#include <stdio.h>
#include <string.h>

int main() {
    char mensaje[1000000];
    int offset, tam, nVocales;

    while (true) {
        fgets(mensaje, 1024, stdin);

        offset = 'p'-mensaje[0];

        tam = strlen(mensaje);
        nVocales = 0;            
        for (int i = 0; i < tam; i++) {
            if (mensaje[i] >= 97 && mensaje[i] <= 122) {
                mensaje[i] = 97+(mensaje[i]-71+offset)%26;
                if (mensaje[i] == 97 || mensaje[i] == 101 || mensaje[i] == 105 || mensaje[i] == 111 || mensaje[i] == 117) {
                    nVocales++;
                }
            } else if (mensaje[i] >= 65 && mensaje[i] <= 90) {
                mensaje[i] = 65+(mensaje[i]-39+offset)%26;
                if (mensaje[i] == 65 || mensaje[i] == 69 || mensaje[i] == 73 || mensaje[i] == 79 || mensaje[i] == 85) {
                    nVocales++;
                }
            }
        }

        if (mensaje[1] == 'F' && mensaje[2] == 'I' && mensaje[3] == 'N' && (mensaje[4] == '\0' || mensaje[4] == '\n')) {
            break;
        } else {
            printf("%d\n", nVocales);
        }
    }    
}