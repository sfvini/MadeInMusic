#include <stdio.h>
#include <string.h>
#include "function_utils.h"
#include "instrument_utils.h"

#define ARQ "instrumentos.txt"

void salvar(Instrumento instrumentos[], int total)
{
    FILE *f = fopen(ARQ, "w");
    if (!f)
        return;

    for (int i = 0; i < total; i++)
        fprintf(f, "%d| %s (%s) R$%.2f\n",
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

void listar(Instrumento instrumentos[], int total)
{
    printf("\n--LISTA DE INSTRUMENTOS--\n");

    if (total == 0)
    {
        printf("Nenhum instrumento cadastrado.\n");
        return;
    }
    for (int i = 0; i < total; i++)
        printf("Id: %d\nNome: %s\nNaipe: %s\nPreço: %.2f\n\n",
               instrumentos[i].id,
               instrumentos[i].nome,
               instrumentos[i].naipe,
               instrumentos[i].preco);
}

void listarPorNaipe(Instrumento instrumentos[], int total)
{
    char busca[SIZE];

    printf("Digite o naipe: ");
    scanf("%19s", busca);

    int achou = 0;

    for (int i = 0; i < total; i++)
        if (strcmp(instrumentos[i].naipe, busca) == 0)
        {
            printf("Id: %d  Nome: %s  Preço: %.2f\n",
                   instrumentos[i].id,
                   instrumentos[i].nome,
                   instrumentos[i].preco);
            achou = 1;
        }

    if (!achou)
        printf("Nenhum instrumento encontrado.\n");
}

void listarPorNome(Instrumento instrumentos[], int total)
{
    char busca[SIZE];

    printf("Digite o nome: ");
    scanf("%49s", busca);

    int achou = 0;

    for (int i = 0; i < total; i++)
        if (strcmp(instrumentos[i].nome, busca) == 0)
        {
            printf("Id: %d  Naipe: %s  Preço: %.2f\n",
                   instrumentos[i].id,
                   instrumentos[i].naipe,
                   instrumentos[i].preco);
            achou = 1;
        }

    if (!achou)
        printf("Nenhum instrumento encontrado.\n");
}

void cadastrar(Instrumento instrumentos[], int *total, int *proxId)
{
    if (*total >= MAX)
    {
        printf("Limite de instrumentos atingido!\n");
        return;
    }

    Instrumento inst;

    printf("\n--CADASTRAR INSTRUMENTO--\nNome: ");
    getchar();
    fgets(inst.nome, 49, stdin);
    inst.nome[strcspn(inst.nome, "\n")] = '\0';

    printf("Naipe: ");
    scanf("%19s", inst.naipe);

    printf("Preço: ");
    scanf("%f", &inst.preco);

    inst.id = (*proxId)++;
    instrumentos[(*total)++] = inst;

    salvar(instrumentos, *total);
    printf("Instrumento cadastrado!\n");
}

void alterar(Instrumento instrumentos[], int total)
{
    int busca;

    printf("Digite o ID: ");
    scanf("%d", &busca);

    for (int i = 0; i < total; i++)
        if (instrumentos[i].id == busca)
        {
            printf("Preço atual %.2f. Novo preço: ", instrumentos[i].preco);
            scanf("%f", &instrumentos[i].preco);
            salvar(instrumentos, total);
            printf("Preço alterado!\n");
            return;
        }
    printf("Instrumento não encontrado.\n");
}

void remover(Instrumento instrumentos[], int *total)
{
    int busca;

    printf("Digite o ID: ");
    scanf("%d", &busca);

    for (int i = 0; i < *total; i++)
        if (instrumentos[i].id == busca)
        {
            for (int j = i; j < *total - 1; j++)
                instrumentos[j] = instrumentos[j + 1];
            (*total)--;
            salvar(instrumentos, *total);
            printf("Instrumento removido!\n");
            return;
        }
    printf("Instrumento não encontrado.\n");
}