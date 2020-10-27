/*
Faça um programa que disponibilize 3 opções para o usuário

1 - Incluir na Fila

2 - Chamar alguém da fila

3 - Sair.

implemente utilizando uma estrutura de lista ligada ou duplamente ligada.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct fila
{
    int qtd;
    struct reg_fila * inicio;
    struct reg_fila * fim;
} fila;

typedef struct reg_fila
{
    int valor;
    struct reg_fila * prox;
}reg_fila;

fila *aloca_fila();
reg_fila * aloca_reg_fila();
void insert(fila *f, int x);
int fila_vazia(fila *f);
int rem(fila * f);

int main()
{
    fila *f;
    f = aloca_fila();
    int opcao, num, chamar;

    do
    {
        printf("\n1 - Incluir na fila");
        printf("\n2 - Chamar alguém da fila");
        printf("\n3 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\nDigite o numero a ser inserido na fila: ");
            scanf("%d", &num);
            insert(f, num);
            break;

        case 2:
            if (fila_vazia(f))
            {
                printf("\nA fila esta vazia\n");
            }
            else
            {
                chamar = rem(f);
                printf("\nO %d foi chamado da fila\n", chamar);
            }
            break;

        case 3:
            printf("\nSaindo do programa");
            break;

        default:
            break;
        }
    } while (opcao != 3);

    return 0;
}

fila * aloca_fila()
{
    fila *nova_fila;
    nova_fila = (fila *)malloc(sizeof(fila));
    nova_fila->qtd = 0;
    nova_fila->inicio = NULL;
    nova_fila->fim = NULL;
    return nova_fila;
}

reg_fila * aloca_reg_fila(){
    reg_fila * novo_reg;
    novo_reg = (reg_fila *)malloc(sizeof(reg_fila));
    novo_reg->valor = 0;
    novo_reg->prox = NULL;
    return novo_reg;
}

void insert(fila *f, int x)
{
    reg_fila * novo_reg;
    novo_reg = aloca_reg_fila();
    novo_reg->valor = x;
    if (f->inicio == NULL && f->fim == NULL)
    {
        f->inicio = novo_reg;
        f->fim = novo_reg;
    }
    else
    {
        f->fim->prox = novo_reg;
        f->fim = novo_reg;
    }
    f->qtd++;

}

int fila_vazia(fila *f)
{
    return (f->inicio == NULL && f->fim == NULL);
}

int rem(fila * f){
    int x;
    x = f->inicio->valor;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }
    
    return x;
}