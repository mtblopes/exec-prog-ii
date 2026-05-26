#include <stdio.h>
#include <stdlib.h>
#include "utils_char.h"

int main ()
{
    int tamanho;
    scanf("%d\n", &tamanho);

    char *vetor = CriaVetor(tamanho);

    if(vetor == NULL)
    {
        return 0;
    }

    ImprimeString(vetor, tamanho);

    LeVetor(vetor, tamanho);
    ImprimeString(vetor, tamanho);

    LiberaVetor(vetor);

return 0; 
}