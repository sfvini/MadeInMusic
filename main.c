#include <stdio.h>
#include <string.h>
#include "./utils/function_utils.h"

int main(void)
{
    Instrumento instrumentos[MAX];
    int total = 0, proxId = 1, op;

    carregar(instrumentos, &total, &proxId);

    do
    {
        printf("\n--MENU--\n"
               " 1 Listar\n"
               " 2 Cadastrar\n"
               " 3 Alterar preço\n"
               " 4 Excluir\n"
               " 5 Listar por naipe\n"
               " 6 Listar por nome\n"
               " 7 Sair\n"
               " Opção: ");
        scanf("%d", &op);
        getchar();

        switch (op)
        {
        case 1:
        {
            if (total == 0)
                printf("Nenhum instrumento cadastrado.\n");
            else
                for (int i = 0; i < total; i++)
                    printf("Id: %d  Nome: %s  Naipe: %s  Preço: %.2f\n",
                           instrumentos[i].id,
                           instrumentos[i].nome,
                           instrumentos[i].naipe,
                           instrumentos[i].preco);
            break;
        }
        case 2:
        {
            char nome[SIZE], naipe[SIZE];
            float preco;
            printf("Nome: ");
            fgets(nome, SIZE, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            printf("Naipe: ");
            scanf("%29s", naipe);
            printf("Preço: ");
            scanf("%f", &preco);
            getchar();
            if (cadastrar(instrumentos, &total, &proxId, nome, naipe, preco))
                printf("Instrumento cadastrado!\n");
            else
                printf("Erro ao cadastrar (limite atingido).\n");
            break;
        }
        case 3:
        {
            int id;
            float novo;
            printf("ID: ");
            scanf("%d", &id);
            printf("Novo preço: ");
            scanf("%f", &novo);
            getchar();
            if (alterar(instrumentos, total, id, novo))
                printf("Preço alterado!\n");
            else
                printf("Instrumento não encontrado.\n");
            break;
        }
        case 4:
        {
            int id;
            printf("ID: ");
            scanf("%d", &id);
            getchar();
            if (remover(instrumentos, &total, id))
                printf("Instrumento removido!\n");
            else
                printf("Instrumento não encontrado.\n");
            break;
        }
        case 5:
        {
            char naipe[SIZE];
            int achou = 0;
            printf("Naipe: ");
            scanf("%29s", naipe);
            getchar();
            for (int i = 0; i < total; i++)
                if (strcmp(instrumentos[i].naipe, naipe) == 0)
                {
                    printf("Id: %d  Nome: %s  Preço: %.2f\n",
                           instrumentos[i].id,
                           instrumentos[i].nome,
                           instrumentos[i].preco);
                    achou = 1;
                }
            if (!achou)
                printf("Nenhum instrumento encontrado.\n");
            break;
        }
        case 6:
        {
            char nome[SIZE];
            int achou = 0;
            printf("Nome: ");
            fgets(nome, SIZE, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            for (int i = 0; i < total; i++)
                if (strcmp(instrumentos[i].nome, nome) == 0)
                {
                    printf("Id: %d  Naipe: %s  Preço: %.2f\n",
                           instrumentos[i].id,
                           instrumentos[i].naipe,
                           instrumentos[i].preco);
                    achou = 1;
                }
            if (!achou)
                printf("Nenhum instrumento encontrado.\n");
            break;
        }
        case 7:
            printf("Encerrando...\n");
            break;
        default:
            printf("Opção inválida.\n");
        }
    } while (op != 7);

    return 0;
}