/*

Construa um programa que insira números em uma lista ligada.
O usuário poderá escolher se deseja incluir o número no ínício da lista ou no final da lista;

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

registro *aloca_registro();
lista *aloca_lista();
void incluir_ordenado(lista *l, int x);
void incluir_no_final(lista *l, int x);
void mostrar(lista *l);

int main()
{
    lista *l;
    int numero = 0;

    l = aloca_lista();

    int opcao;

    do
    {
        printf("\n 1 - incluir no inicio:");
        printf("\n 2 - incluir no final:");
        printf("\n 3 - Mostrar lista");
        printf("\n 5 - Sair");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Digite um numero para ser includo no inicio lista: ");
            scanf("%d", &numero);
            incluir_ordenado(l, numero);
            break;
        case 2:
            printf("\n Digite um numero para ser includo no final da lista: ");
            scanf("%d", &numero);
            incluir_no_final(l, numero);
            break;
        case 3:
            mostrar(l);
            break;
        case 5:
            printf("\n Saindo do programa");
            break;
        default:
            printf("\n Opcao invalida");
            break;
        }
    } while (opcao != 5);
}

lista *aloca_lista()
{
    lista *nova_lista;

    nova_lista = (lista *)malloc(sizeof(lista));
    nova_lista->qtd = 0;
    nova_lista->inicio = NULL;
    return nova_lista;
}

registro *aloca_registro()
{
    registro *novo_registro;
    novo_registro = (registro *)malloc(sizeof(registro));
    novo_registro->valor = 0;
    novo_registro->prox = NULL;
    return novo_registro;
}

void incluir_ordenado(lista *l, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else
    {
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    l->qtd++;
}
void incluir_no_final(lista *l, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else
    {
        aux = l->inicio;

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        aux->prox = novo;
    }

    l->qtd++;
}

void mostrar(lista *l)
{
    registro *aux;

    if (l->qtd == 0)
    {
        printf("\n Lista vazia");
    }
    else
    {
        aux = l->inicio;
        while (aux != NULL)
        {
            printf("\n%d", aux->valor);
            aux = aux->prox;
        }
    }
}