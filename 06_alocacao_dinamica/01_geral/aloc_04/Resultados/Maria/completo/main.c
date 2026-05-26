#include <stdio.h>
#include "utils_char2.h"

int main () {

    int tamanho = TAM_PADRAO;

    char *str = CriaVetorTamPadrao();

    str = LeVetor(str, &tamanho);

    ImprimeString(str);
    LiberaVetor(str);

return 0;
}