#include <stdio.h>
#include <stdlib.h>
#define TAM 4

typedef struct fila
{
    int items[TAM];
    int inicio, qtd;
} fila;

fila *aloca_fila();
void insert(fila *f, int x);
int fila_cheia(fila *f);
int fila_vazia(fila *f);
int rem(fila * f);

int main()
{
    fila *f;
    f = aloca_fila();
    int opcao, num, chamar;

    do
    {
        printf("\n1 - Incluir na Fila");
        printf("\n2 - Chamar alguém da fila");
        printf("\n3 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            if (fila_cheia(f))
            {
                printf("\nA fila esta cheia");
            }
            else
            {
                printf("\nDigite o numero a ser inserido na fila: ");
                scanf("%d", &num);
                insert(f, num);
            }
            break;

        case 2:
            if (fila_vazia(f))
            {
                printf("\nA fila esta vazia");
            }
            else
            {
                if (chamar = rem(f)){
                    printf("\nO %d foi chamado da fila", chamar);
                }
                else
                {
                    printf("\nNão tem mais elementos a serem chamados");
                }
                
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

fila *aloca_fila()
{
    fila *nova_fila;
    nova_fila = (fila *)malloc(sizeof(fila));
    nova_fila->inicio = 0;
    nova_fila->qtd = 0;
    return nova_fila;
}

void insert(fila *f, int x)
{
    f->items[f->qtd] = x;
    if (f->qtd < 1)
    {
        f->inicio = f->qtd;
    }
    f->qtd++;
}

int fila_cheia(fila *f){
    if (f->qtd == TAM)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int fila_vazia(fila *f)
{
    if(f->qtd == 0){
        return 1;
    }
    else
    {
        return 0;
    }
}

int rem(fila * f){
    int x;
    if (f->qtd >= 4 && f->inicio >= 4)
    {
        return 0;
    }
    else
    {
        x = f->items[f->inicio];
        f->inicio++;
        f->qtd--;    
        return x;
    }
}