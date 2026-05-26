#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int tamanho;
    scanf("%d\n", &tamanho);

    int *vetor = CriaVetor(tamanho);

    if(vetor == NULL)
    {
        printf("ERRO!");
        return 0;
    }

    LeVetor(vetor, tamanho);
    
    printf("%.2f", CalculaMedia(vetor, tamanho));
    
    LiberaVetor(vetor);

return 0;
}