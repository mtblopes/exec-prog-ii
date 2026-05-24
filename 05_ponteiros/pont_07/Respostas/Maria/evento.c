#include <stdio.h>
#include <string.h>
#include "evento.h"


/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */
void cadastrarEvento(Evento* eventos, int* numEventos)
{   
   
    char nome[50];
    scanf(" %[^\n]\n", nome);
    strcpy(eventos[*numEventos].nome, nome);
    scanf("%d %d %d\n", &eventos[*numEventos].dia, 
                        &eventos[*numEventos].mes, 
                        &eventos[*numEventos].ano);

    (*numEventos)++;
    
}

/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento* eventos, int* numEventos)
{
    for(int i=0; i<*numEventos; i++)
    {
        printf("%d - %s - ", i, eventos[i].nome);
        printf("%02d/%02d/%04d\n", eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }
}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarDataEvento(Evento* eventos, int* numEventos)
{
    int n;  //numero do evento
    int diaN, mesN, anoN;
    scanf("%d\n", &n);
    scanf("%d %d %d\n", &diaN, &mesN, &anoN);

    if(n < 0 || n >= *numEventos)
    {
        printf("Indice invalido!\n");
        return;
    }

    eventos[n].dia = diaN;
    eventos[n].mes = mesN;
    eventos[n].ano = anoN;

}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos)
{
   Evento temp = eventos[*indiceA];
   eventos[*indiceA] = eventos[*indiceB];
   eventos[*indiceB] = temp;
}