#include <stdio.h>
#include <string.h>
#include "file_utils.h"
#include "instrument_utils.h"

#define ARQ "instrumentos.txt"

void salvar(Instrumento instrumentos[], int total)
{
    FILE *f = fopen(ARQ, "w");
    if (!f)
        return;
    for (int i = 0; i < total; i++)
        fprintf(f, "%d %s %s %.2f\n",
                instrumentos[i].id,
                instrumentos[i].nome,
                instrumentos[i].naipe,
                instrumentos[i].preco);
    fclose(f);
}

void carregar(Instrumento instrumentos[], int *total, int *proxId)
{
    FILE *f = fopen(ARQ, "r");
    if (!f)
        return;
    int id, maior = 0;
    char nome[50], naipe[20];
    float preco;
    *total = 0;
    while (fscanf(f, "%d %49s %19s %f",
                  &id, nome, naipe, &preco) == 4 &&
           *total < MAX)
    {
        instrumentos[*total].id = id;
        strcpy(instrumentos[*total].nome, nome);
        strcpy(instrumentos[*total].naipe, naipe);
        instrumentos[*total].preco = preco;
        if (id > maior)
            maior = id;
        (*total)++;
    }
    *proxId = maior + 1;
    fclose(f);
}
