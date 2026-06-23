#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

typedef void *DataType; // void pointer
struct Vector
{
    DataType *elementos;
    int capacidade;
    int tamanho;
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
    v->tamanho = 0;

    v->elementos = (DataType *) malloc (sizeof(DataType)* v->capacidade);

    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val)
{
    if(v->capacidade == v->tamanho)
    {
        v->capacidade *= 2;
        v->elementos = (DataType *) realloc (v->elementos, sizeof(DataType)* v->capacidade);
    }

    v->elementos[v->tamanho] = val;
    v->tamanho++;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i)
{
    return v->elementos[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v)
{
    return v->tamanho;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType))
{
    for(int i = 0; i < v->tamanho; i++)
    {
        destroy(v->elementos[i]);
    }
    free(v->elementos);
    free(v);
}