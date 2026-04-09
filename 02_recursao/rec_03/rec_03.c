#include <stdio.h>
#define MAX 100

int contaOcorrencias(int *vet, int numElementos, int numeroProcurado){
    if(numElementos == 0){
        return 0;
    }

    int atual = vet[numElementos - 1];

    if(atual == numeroProcurado){
        return 1+contaOcorrencias(vet, numElementos - 1, numeroProcurado);
    } else {
        return 0+contaOcorrencias(vet, numElementos - 1, numeroProcurado);
    }
}

int main(){
    int n, x, i, j, k;
    int vet[MAX];
    int ocorrencias;

    scanf("%d\n", &n);

    for(j = 0; j < n; j++){
        scanf("%d %d\n", &x, &i);
            for(k = 0; k < i; k++){
                scanf("%d", &vet[k]);
            }
        ocorrencias = contaOcorrencias(vet, i, x);
        printf("%d\n", ocorrencias);
    }
return 0;
}