/*  Maria Teresa Bolognini Lopes
    Data: 28/03/2026    */

#include <stdio.h>
#define MAX 1000

typedef struct{
    int linha;
    int coluna;
    int mat[MAX][MAX];
} tMatriz; 

typedef struct{
    int xi;
    int xj;
} tPosicao;

typedef struct{
    char pri, seg, ter, qua;
} tPrioridade;

tMatriz leMatriz(){
    int i, j;
    tMatriz mapa;
    
    scanf("%d %d", &mapa.linha, &mapa.coluna);

    for(i = 1; i <= mapa.linha; i++){
        for(j = 1; j <= mapa.coluna; j++){
            scanf("%d", &mapa.mat[i][j]);
        }
    }

    return mapa;
}

tPosicao lePosicao(){
    tPosicao posicao;

    scanf("%d %d", &posicao.xi, &posicao.xj);

return posicao;
}

tPrioridade lePrioridade(){
    tPrioridade prioridade;

    scanf(" %c%c%c%c", &prioridade.pri, &prioridade.seg, &prioridade.ter, &prioridade.qua);

return prioridade;
}

int ehLivre (tMatriz mapa, int i, int j){
    return mapa.mat[i][j] == 0;
}

int direcao(char c){
        switch (c)
        {
        case 'C':
            return -1;
        case 'B':
            return 1;
        case 'D':
            return 2;
        case 'E':
            return -2;
        default:
            break;
        }
return 0;
}

void caminho(tMatriz mapa, tPosicao inicio, tPosicao fim, tPrioridade p){
    int i, j;

    printf("(%d,%d) ", inicio.xi, inicio.xj);

    while (inicio.xi != fim.xi || inicio.xj != fim.xj){
        
        printf("(%d,%d)", inicio.xi, inicio.xj);
       
        if(primeira(p) == -1 && ehLivre(mapa, inicio.xi - 1, inicio.xj)){
            inicio.xi = inicio.xi - 1;
            printf("(%d,%d)", inicio.xi, inicio.xj);
        } else {
            if(primeira(p) == 1 && ehLivre(mapa, inicio.xi+1, inicio.xj)){
                inicio.xi = inicio.xi + 1;
                printf("(%d,%d)", inicio.xi, inicio.xj);
            } else {
                if(primeira(p) == 2 && ehLivre(mapa, inicio.xi, inicio.xj+1)){
                    inicio.xj = inicio.xj + 1;
                    printf("(%d,%d)", inicio.xi, inicio.xj);
                } else {
                    if(primeira(p) == -2 && ehLivre(mapa, inicio.xi, inicio.xj-1)){
                        inicio.xj = inicio.xj - 1;
                        printf("(%d,%d)", inicio.xi, inicio.xj);
                    }
                }
            }
        }
    }
}


int main (){
    int linha, coluna;
    tMatriz mat;
    tPosicao inicio, fim;
    tPrioridade priori;

    mat = leMatriz();
    inicio = lePosicao();
    fim = lePosicao();
    priori = lePrioridade();

    caminho(mat, inicio, fim, priori);

return 0;
}