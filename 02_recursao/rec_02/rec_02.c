#include <stdio.h>
#include <string.h>
#define MAX 100

int somaElementosPares (int *vet, int numElementos){
    if(numElementos == 0){
        return 0;
    }
    
    int atual = vet[numElementos - 1];

    if(atual % 2 == 0){
        return atual + somaElementosPares(vet, numElementos - 1);
    } else {
        return somaElementosPares(vet, numElementos - 1);
    } 
}

int main(){
    int n, i, j, k;
    int vet[MAX];
    int soma;

    scanf("%d\n", &n);

    for(k = 0; k < n; k++){
        scanf("%d\n", &i);
            for (j = 0; j < i; j++){
              scanf("%d", &vet[j]);
            }
            soma = somaElementosPares(vet, i);
            printf("%d\n", soma);
        }


return 0;
}