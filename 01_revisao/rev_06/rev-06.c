#include <stdio.h>
#define MAX 256

typedef struct{
    int vet[MAX];
    int limite;
} tLista; 

tLista zeraVetor(){
    tLista zerada;
    int i;
    for(i = 0; i < MAX; i++){
        zerada.vet[i] = 0;
    }
    return zerada;
}

tLista le_lista(){

    tLista lista = zeraVetor();
    char rotulo;

    scanf("%d\n", &lista.limite);

    while(scanf("%c", &rotulo) != EOF){
        lista.vet[rotulo]++;
    }
    return lista;
}



void imprimeRotulos(tLista lista){
    int i;
    int encontrou = 0;
    for(i = 0; i < MAX; i++){
        if(lista.vet[i] > lista.limite){
            printf("%c: %d\n", i, lista.vet[i]);
            encontrou = 1;
        }
    }

    if(!encontrou){
        printf("NENHUM");
    }
}

int main ()
{
    tLista lista;

    lista = le_lista();

    imprimeRotulos(lista);
return 0;
}