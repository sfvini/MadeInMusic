#include <stdio.h>
#include <string.h>
#include "function_utils.h"

void salvar(Instrumento instrumentos[], int total)
{
    FILE *f = fopen(ARQ, "w");
    if (!f)
        return;
    for (int i = 0; i < total; i++)
        fprintf(f, "%d|%s|%s|%.2f\n",
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
    {
        *total = 0;
        *proxId = 1;
        return;
    }
    int id, maior = 0;
    char nome[SIZE], naipe[SIZE];
    float preco;
    *total = 0;
    while (fscanf(f, "%d|%29[^|]|%29[^|]|%f\n",
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

int cadastrar(Instrumento instrumentos[], int *total, int *proxId, char *nome, char *naipe, float preco)
{
    if (*total >= MAX)
        return 0;
    instrumentos[*total].id = (*proxId)++;
    strcpy(instrumentos[*total].nome, nome);
    strcpy(instrumentos[*total].naipe, naipe);
    instrumentos[*total].preco = preco;
    (*total)++;
    salvar(instrumentos, *total);
    return 1;
}

int alterar(Instrumento instrumentos[], int total,
            int id, float novoPreco)
{
    for (int i = 0; i < total; i++)
        if (instrumentos[i].id == id)
        {
            instrumentos[i].preco = novoPreco;
            salvar(instrumentos, total);
            return 1;
        }
    return 0;
}

int remover(Instrumento instrumentos[], int *total, int id)
{
    for (int i = 0; i < *total; i++)
        if (instrumentos[i].id == id)
        {
            for (int j = i; j < *total - 1; j++)
                instrumentos[j] = instrumentos[j + 1];
            (*total)--;
            salvar(instrumentos, *total);
            return 1;
        }
    return 0;
}