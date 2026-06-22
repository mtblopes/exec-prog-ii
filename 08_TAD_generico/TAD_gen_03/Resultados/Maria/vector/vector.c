#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct Vector
{
    data_type *elementos;
    int capacidade;
    int tam;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct()
{
    Vector *v = (Vector *) malloc (sizeof(Vector));

    v->capacidade = 4;
    v->tam = 0;

    v->elementos = (data_type *) malloc(sizeof(data_type) * v->capacidade);

    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, data_type val)
{
    if(v->tam == v->capacidade)
    {
        v->capacidade *= 2;
        v->elementos = (data_type *) realloc(v->elementos, sizeof(data_type) * v->capacidade);
    }

    v->elementos[v->tam] = val;
    v->tam++;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return data_type Elemento do vetor
*/
data_type VectorGet(Vector *v, int i)
{
    return (v->elementos[i]);
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v)
{
    return v->tam;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(data_type))
{
    for(int i = 0; i < v->tam; i++)
    {
        destroy(v->elementos[i]);
    }
    free(v->elementos);
    free(v);
}