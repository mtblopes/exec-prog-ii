#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"

struct pacote 
{
    void *elementos;
    int nElem;
    int somaDeVerificacao;
    Type tipo;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem)
{
    tPacote *p = (tPacote *) malloc (sizeof (tPacote));
    p->nElem = numElem;
    p->tipo = type;

    if(p->tipo == CHAR)
    {
        p->elementos = malloc (sizeof(char)* p->nElem);
    }
    else
    {
        p->elementos = malloc (sizeof (int) * p->nElem);
    }

    return p;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac)
{
    free(pac->elementos);
    free(pac);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac)
{
    for(int i = 0; i < pac->nElem; i++)
    {
        if(pac->tipo == INT)
        {
            scanf("%d\n", &((int *)pac->elementos)[i]);
        }
        else
        {
            scanf("%c\n", &((char *)pac->elementos)[i]);
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac)
{
    CalculaSomaVerificacaoPacote(pac);
    printf("%d ", pac->somaDeVerificacao);

    for(int i = 0; i < pac->nElem; i++)
    {
        if(pac->tipo == INT)
            printf("%d ", ((int *)pac->elementos)[i]);

        else
            printf("%c ", ((char *)pac->elementos)[i]);
    }
    printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac)
{   
    pac->somaDeVerificacao = 0;

    for(int i = 0; i < pac->nElem; i++)
    {
        if(pac->tipo == CHAR)
            pac->somaDeVerificacao += ((char *)pac->elementos)[i];
    
        else
            pac->somaDeVerificacao += ((char *)pac->elementos)[i];
    }
}

