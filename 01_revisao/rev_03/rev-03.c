#include <stdio.h>
#define MAX 1000

typedef struct{
    int n;
    int vet[MAX];
} tBiblioteca;

tBiblioteca zeraVetor(int n){
    tBiblioteca biblioteca;
    int i;

    biblioteca.n = n;

    for(i = 0; i < MAX; i++){
        biblioteca.vet[i] = 0;
    }
    return biblioteca; 
}

tBiblioteca qtdLivros(tBiblioteca biblioteca){
    int i;
    int livro;

    for(i = 0; i < biblioteca.n; i++){
        scanf("%d", &livro);
        biblioteca.vet[livro - 1]++;
    }
return biblioteca;
}

int nenhumLivro(tBiblioteca biblioteca){
    int i;
    int cont = 0;

    for(i = 0; i < MAX; i++){
        if(biblioteca.vet[i] < 2 && biblioteca.vet[i] > 0){
            cont++;
        }
    }

    if(cont == 0){
        return 1;
    }

return 0;
}   

void imprimeLivros(tBiblioteca biblioteca){
    int i;

    for(i = 0; i < MAX; i++){
        if(biblioteca.vet[i] < 2 && biblioteca.vet[i] > 0){
            printf("%d ", i+1);
        }else{
        }
    }
}

int main() {
    int n;
    tBiblioteca biblioteca;

    scanf("%d", &n);
    biblioteca = zeraVetor(n);
    biblioteca = qtdLivros(biblioteca);

    if(nenhumLivro(biblioteca)){
        printf("NENHUM");
    
    } else {
      imprimeLivros(biblioteca);
    }

return 0;
}
