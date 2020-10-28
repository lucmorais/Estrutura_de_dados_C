/*
Construa um programa que receba N números do usuário e insira esses números de forma ordenada em uma lista ligada
Não é permitido a utilização de vetores;

O programa deverá ler números do usuário até que seja digitado o número -1
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
void mostrar(lista *l);

int main()
{
    lista *l;
    int numero = 0;

    l = aloca_lista();

    int opcao;

    do
    {
        mostrar(l);
        printf("\n Digite um numero para ser includo na lista: ");
        scanf("%d", &numero);
        
        incluir_ordenado(l, numero);
    } while (numero !=-1);
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
        aux = l->inicio;

        if (aux->valor > novo->valor)
        {
            novo->prox = l->inicio;
            l->inicio = novo;
        }
        else
        {
            while (aux->prox != NULL)
            {
                if (aux->prox->valor < novo->valor)
                {
                    aux = aux->prox;
                }
                else
                {
                    break;
                }
            }

            novo->prox = aux->prox;
            aux->prox = novo;
        }
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
