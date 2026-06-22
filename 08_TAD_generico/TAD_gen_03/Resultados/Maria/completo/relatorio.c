#include "relatorio.h"
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "aluno.h"

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos)
{
    float mediaNotas = 0;
    float nota = 0;
    float aprovados = 0;
    char genero = ' ';
    float fem = 0;
    float masc = 0;
    float outro = 0;

    int qtd = VectorSize(alunos);
    for(int i = 0; i < qtd; i++)
    {
        tAluno *aluno = (tAluno *) VectorGet(alunos, i);

        nota = GetNotaAluno(aluno);
        mediaNotas += nota;
        //verifica aprovado
        if(nota >= 6.00)
        {
            aprovados++;
        }

        genero = GetGeneroAluno(aluno);
        if(genero == 'F')
        {
            fem++;
        }
        else 
        {
            if(genero == 'M')
            {
                masc++;
            }
            else
                outro++;
        }
        
    }

    //Media das notas:
    printf("Media das notas: %.2f\n", (mediaNotas/qtd));

    //Porcentagem de alunos aprovados:
    printf("Porcentagem de alunos aprovados: %.2f%%\n", (aprovados/qtd)*100.00);

    //Porcentagem de cada genero:
    printf("Porcentagem de cada genero:\n");
    //Masculino:
    printf("Masculino: %.2f%%\n", (masc/qtd)*100.00);
    //Feminino:
    printf("Feminino: %.2f%%\n", (fem/qtd)*100.00);
    //Outro:
    printf("Outro: %.2f%%", (outro/qtd)*100.00);

}