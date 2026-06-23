#include "agencia.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura para representar uma agência bancária.
 */
struct Agencia
{
    int numero;
    char *nome;
    Vector *contas;
};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia()
{
    tAgencia *agencia = (tAgencia *)malloc(sizeof(tAgencia));
    agencia->nome = (char *) malloc (sizeof(char) * 100);
    agencia->numero = 0;
    agencia->contas = VectorConstruct();

    return agencia;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia)
{
    tAgencia *a = (tAgencia *)agencia;
    free(a->nome);
    VectorDestroy(a->contas, DestroiConta);
    free(a);
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia)
{
    scanf("%d;%[^\n]\n", &agencia->numero, agencia->nome);
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta)
{
    VectorPushBack(agencia->contas, conta);
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2)
{
    return numAgencia == agencia2->numero;
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia (tAgencia *agencia)
{
    float saldoMedio = 0.00;
    float qtdContas = VectorSize(agencia->contas);

    if(qtdContas == 0)
        return 0.00;

    for(int i = 0; i < qtdContas; i++)
    {
       tConta *conta = VectorGet(agencia->contas, i);
       saldoMedio += GetSaldoConta(conta);
    }

    return (float)saldoMedio/qtdContas;
}

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia)
{
    printf("\tNome: %s\n", agencia->nome);
    printf("\tNumero: %d\n", agencia->numero);
    
    printf("\tNumero de contas cadastradas: %d\n", VectorSize(agencia->contas));
    printf("\tSaldo médio: R$%.2f\n", GetSaldoMedioAgencia(agencia));
}

