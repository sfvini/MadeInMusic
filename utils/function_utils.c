#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "function_utils.h"

void salvar(Instrumento instrumentos[], int total)
{
    FILE *f = fopen(ARQ, "w");
    if (!f)
        return;

    for (int i = 0; i < total; i++)
        fprintf(f, "%d| Nome: %s Naipe: %s R$%.2f\n",
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

    while (fscanf(f, "%d|%29[^|]|%29[^|]|%f\n", &id, nome, naipe, &preco) == 4 && *total < MAX)
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

bool cadastrar(Instrumento instrumentos[], char nome[], char naipe[], float preco, int *total, int *proxId)
{
    if (*total >= MAX)
        return false;

    instrumentos[*total].id = (*proxId)++;
    strcpy(instrumentos[*total].nome, nome);
    strcpy(instrumentos[*total].naipe, naipe);
    instrumentos[*total].preco = preco;
    (*total)++;
    salvar(instrumentos, *total);
    return true;
}

bool alterar(Instrumento instrumentos[], int id, float novo, int *total)
{
    for (int i = 0; i < *total; i++)
        if (instrumentos[i].id == id)
        {
            instrumentos[i].preco = novo;
            salvar(instrumentos, *total);
            return true;
        }
    return false;
}

bool remover(Instrumento instrumentos[], int id, int *total)
{
    for (int i = 0; i < *total; i++)
        if (instrumentos[i].id == id)
        {
            for (int j = i; j < *total - 1; j++)
                instrumentos[j] = instrumentos[j + 1];
            (*total)--;
            salvar(instrumentos, *total);
            return true;
        }
    return false;
}