/*  Maria Teresa Bolognini Lopes
    Data: 28/03/2026    */

#include <stdio.h>
#define MAX 100

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
    if(i < 1 || i > mapa.linha || j < 1 || j > mapa.coluna){
        return 0;
    }
    return mapa.mat[i][j] == 0;
}

tPosicao proximaPosicao (tPosicao atual, char dir)
{
    tPosicao proxima = atual;
        if (dir == 'C'){
            proxima.xi--;
        } else {
            if(dir == 'B'){
                proxima.xi++;
            } else {
                if(dir == 'D'){
                    proxima.xj++;
                } else {
                    if (dir == 'E'){
                        proxima.xj--;
                    }
                }
            }
        }
    return proxima;
}

void caminho(tMatriz mapa, tPosicao inicio, tPosicao fim, tPrioridade p){
    int andou;
    tPosicao prox;

    printf("(%d,%d) ", inicio.xi, inicio.xj);
    mapa.mat[inicio.xi][inicio.xj] = 1;

    while (inicio.xi != fim.xi || inicio.xj != fim.xj)
    {
        andou = 0;
        prox = proximaPosicao(inicio, p.pri);
        if(ehLivre(mapa, prox.xi, prox.xj)){
            inicio = prox;
            andou = 1;
        } else {
            prox = proximaPosicao(inicio, p.seg);
            if(ehLivre(mapa, prox.xi, prox.xj)){
                inicio = prox;
                andou = 1;
            } else {
                prox = proximaPosicao(inicio, p.ter);
                if(ehLivre(mapa,prox.xi, prox.xj)){
                    inicio = prox;
                    andou = 1; 
                } else {
                    prox = proximaPosicao(inicio, p.qua);
                    if(ehLivre(mapa, prox.xi, prox.xj)){
                        inicio = prox;
                        andou = 1;
                    }
                }
            }
        }
        
        if(!andou){
            break;
        }
        mapa.mat[inicio.xi][inicio.xj] = 1;
        printf("(%d,%d) ", inicio.xi, inicio.xj);   
    }
}


int main (){
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