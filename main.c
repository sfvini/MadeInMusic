#include <stdio.h>
#include <string.h>
#include "./utils/file_utils.h"
#include "./utils/function_utils.h"
#include "./utils/instrument_utils.h"

int main()
{
    Instrumento instrumentos[MAX];

    int total = 0, proxId = 1, op;

    carregar(instrumentos, &total, &proxId);

    do
    {
        printf("\n--MENU--\n 1 Listar\n 2 Cadastrar\n 3 Alterar preço\n 4 Excluir\n 5 Listar por naipe\n 6 Listar por nome\n 7 Sair\n Opção: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            listar(instrumentos, total);
            break;
        case 2:
            cadastrar(instrumentos, &total, &proxId);
            break;
        case 3:
            alterar(instrumentos, total);
            break;
        case 4:
            remover(instrumentos, &total);
            break;
        case 5:
            listarPorNaipe(instrumentos, total);
            break;
        case 6:
            listarPorNome(instrumentos, total);
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
