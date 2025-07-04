#include <stdio.h>
#include <string.h>

#define MAX 50
#define SIZE 30
#define ARQ "instrumentos.txt"

typedef struct
{
    int id;
    char nome[50];
    char naipe[20];
    float preco;
} Instrumento;

Instrumento instrumentos[MAX];
int total = 0;
int proxId = 1;

void salvar()
{
    FILE *f = fopen(ARQ, "w");
    if (!f)
        return;
    for (Instrumento *p = instrumentos; p < instrumentos + total; p++)
        fprintf(f, "%d| %s %s R$%.2f\n", p->id, p->nome, p->naipe, p->preco);
    fclose(f);
}

void carregar()
{
    FILE *f = fopen(ARQ, "r");
    if (!f)
    {
        return;
    }
    int id;
    char nome[50], naipe[20];
    float preco;
    int maior = 0;
    while (fscanf(f, "%d %49s %19s %f", &id, nome, naipe, &preco) == 4 && total < MAX)
    {
        instrumentos[total].id = id;
        strcpy(instrumentos[total].nome, nome);
        strcpy(instrumentos[total].naipe, naipe);
        instrumentos[total].preco = preco;
        if (id > maior)
            maior = id;
        total++;
    }
    proxId = maior + 1;
    fclose(f);
}

void listar()
{
    printf("\n--LISTA DE INSTRUMENTOS--\n");
    if (total == 0)
    {
        printf("Nenhum instrumento cadastrado.\n");
        return;
    }
    for (Instrumento *p = instrumentos; p < instrumentos + total; p++)
        printf("Id: %d\nNome: %s\nNaipe: %s\nPreço: %.2f\n\n", p->id, p->nome, p->naipe, p->preco);
}

void listarPorNaipe()
{
    char busca[SIZE];
    printf("Digite o naipe: ");
    scanf("%19s", busca);
    int achou = 0;
    for (Instrumento *p = instrumentos; p < instrumentos + total; p++)
        if (strcmp(p->naipe, busca) == 0)
        {
            printf("Id: %d  Nome: %s  Preço: %.2f\n", p->id, p->nome, p->preco);
            achou = 1;
        }
    if (!achou)
        printf("Nenhum instrumento encontrado.\n");
}

void listarPorNome()
{
    char busca[SIZE];
    printf("Digite o nome: ");
    scanf("%49s", busca);
    int achou = 0;
    for (Instrumento *p = instrumentos; p < instrumentos + total; p++)
        if (strcmp(p->nome, busca) == 0)
        {
            printf("Id: %d  Naipe: %s  Preço: %.2f\n", p->id, p->naipe, p->preco);
            achou = 1;
        }
    if (!achou)
        printf("Nenhum instrumento encontrado.\n");
}

void cadastrar()
{
    if (total >= MAX)
    {
        printf("Limite de instrumentos atingido!\n");
        return;
    }

    Instrumento inst;

    printf("\n--CADASTRAR INSTRUMENTO--\nNome: ");
    scanf("%49s", inst.nome);

    printf("Naipe: ");
    scanf("%19s", inst.naipe);

    printf("Preço: ");
    scanf("%f", &inst.preco);

    inst.id = proxId++;
    instrumentos[total++] = inst;

    salvar();
    printf("Instrumento cadastrado!\n");
}

void alterar()
{
    int busca;
    printf("Digite o ID: ");
    scanf("%d", &busca);
    for (Instrumento *p = instrumentos; p < instrumentos + total; p++)
        if (p->id == busca)
        {
            printf("Preço atual %.2f. Novo preço: ", p->preco);
            scanf("%f", &p->preco);

            salvar();
            printf("Preço alterado!\n");
            return;
        }
    printf("Instrumento não encontrado.\n");
}

void remover()
{
    int busca;
    printf("Digite o ID: ");
    scanf("%d", &busca);
    for (int i = 0; i < total; i++)
        if (instrumentos[i].id == busca)
        {
            for (int j = i; j < total - 1; j++)
                instrumentos[j] = instrumentos[j + 1];
            total--;
            salvar();
            printf("Instrumento removido!\n");
            return;
        }
    printf("Instrumento não encontrado.\n");
}

int main()
{
    carregar();
    int op;
    do
    {
        printf("\n--MENU--\n1 Listar\n2 Cadastrar\n3 Alterar preço\n4 Excluir\n5 Listar por naipe\n6 Listar por nome\n7 Sair\nOpção: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            listar();
            break;
        case 2:
            cadastrar();
            break;
        case 3:
            alterar();
            break;
        case 4:
            remover();
            break;
        case 5:
            listarPorNaipe();
            break;
        case 6:
            listarPorNome();
            break;
        case 7:
            printf("Encerrando...\n");
            break;
        default:
            printf("Opção inválida.\n");
        }
    } while (op != 7);
    return 0;
}