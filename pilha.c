/*
Escreva um algoritmo para determinar se uma string de caracteres deentrada é  da  forma:

xCy 

onde x é uma string consistindo nas letras 'A' e 'B', e y é o inverso
de x (isto é, se x = "ABABBA", y deve equivaler a "ABBABA").
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#define TAM 10

typedef struct pilha
{
    int top;
    char str[TAM];
}pilha;

pilha * aloca_pilha();
int empty(pilha * p);
int estouro(pilha * p);
void push(pilha * p, char ch);
char pop(pilha * p);
int verifica(pilha * p, char * str);

int main(){
    char x[TAM];
    char y[TAM];
    int i, inverso;
    pilha * p;
    p = aloca_pilha();

    __fpurge(stdin);
    fgets(x, TAM, stdin);
    x[strlen(x)-1] = '\0';
    
    for (i = 0; i < strlen(x); i++)
    {
        push(p, x[i]);
    }

    for (i = 0; i < strlen(x); i++)
    {
        y[i] = pop(p);
    }

    printf("\nX: ");
    puts(x);
    printf("\nY: ");
    puts(y);

    if (inverso = verifica(p, y))
    {
        printf("\nY é inverso de X");
    }
    else
    {
        printf("\nY não é inverso de X");
    }
    
    printf("\n");
    return 0;
}

pilha * aloca_pilha(){
    pilha * nova_pilha;
    nova_pilha = (pilha *)malloc(sizeof(pilha));
    nova_pilha->top = -1;
    return nova_pilha;
}

int empty(pilha * p){
    if (p->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int estouro(pilha * p){
    if (p->top == TAM-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(pilha * p, char ch){
    if (estouro(p))
    {
        printf("\nA pilha esta cheia");
    }
    else
    {
        p->top++;
        p->str[p->top] = ch; 
    }   
}

char pop(pilha * p){
    char letra;
    if (empty(p))
    {
        printf("\nPilha vazia");
    }
    else
    {
        letra = p->str[p->top--];
        return letra;
    }
}

int verifica(pilha * p, char * str){
    int i;
    for (i = 0; i < (strlen(p->str) && strlen(str)); i++)
    {
        if (p->str[i] != str[i])
        {
            return 0;
        }        
    }
    return 1;
}
