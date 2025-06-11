#include <stdio.h>

int main()
{

    int op;

    do
    {
        printf("Bem vindo(a) à Made In Music!\n");
        printf("Digite o número relativo a opção desejada");
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

        case 3:
            alterar();
            break;

        case 4:
            listar();
            break;

        default:
            printf("\n--ERRO--\n");
            printf("OPÇÃO INVÁLIDA\n");
            break;
        }

    } while (op != 5);

    return 0;
}