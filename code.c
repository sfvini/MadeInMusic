#include <stdio.h>

#define MAX 50

typedef struct
{
    int id;
    char nome[50];
    char naipe[20];
    float preco;
} Instrumento;

Instrumento instrumentos[MAX];
int total = 0;
int id = 1;

void listar()
{
    printf("\n--LISTA DE INSTRUMENTOS--\n");

    if (total == 0)
    {
        printf("Nenhum instrumento cadastrado.\n");
        return;
    }


    for (int i = 0; i < total; i++)
    {
        printf("Id: %d\n", instrumentos[i].id);
        printf("Nome: %s\n", instrumentos[i].nome);
        printf("Naipe: %s\n", instrumentos[i].naipe);
        printf("Preço: %.2f\n\n", instrumentos[i].preco);
    }
}

void cadastrar()
{
    if (total >= MAX)
    {
        printf("Limite de instrumentos atingido!\n");
        return;
    }

    Instrumento instrumento;

    printf("\n--CADASTRAR INSTRUMENTO--\n");
    printf("Nome: ");
    scanf("%s", &instrumento.nome);
    printf("Naipe: ");
    scanf("%s", &instrumento.naipe);
    printf("Preço: ");
    scanf("%f", &instrumento.preco);

    instrumento.id = id;

    instrumentos[total] = instrumento;
    total++;
    id++;
    printf("Instrumento cadastrado com sucesso!\n");
}

int main()
{
    int op;

    do
    {
        printf("\nBem-vindo(a) ao Made In Music!\n");
        printf("Este é um programa de gerenciamento de instrumentos musicais.\n");
        printf("Você pode listar, cadastrar, alterar ou excluir instrumentos do catálogo.\n");
        printf("\n--MENU--\n");
        printf("1. Listar\n2. Cadastrar\n3. Alterar\n4. Excluir\n5. Sair\n");
        printf("OPÇÃO: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            listar();
            break;

        case 2:
            cadastrar();
            break;

            // case 3:
            //     alterar();
            //     break;

            // case 4:
            //     excluir();
            //     break;

        case 5:
            printf("\n--FIM--\n");
            printf("Obrigado por usar o Made In Music!\n");
            break;

        default:
            printf("\n--ERRO--\n");
            printf("OPÇÃO INVÁLIDA\n");
            break;
        }

    } while (op != 5);

    return 0;
}