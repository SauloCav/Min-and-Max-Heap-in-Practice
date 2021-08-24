#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<windows.h>

typedef struct fila Fila;

Fila* create(int n);

int add(Fila* fi, int e);
bool check_add(Fila* fi, int e);
bool check_pop(Fila* fi, int e);
void check_prioridade(Fila* fi);
int pop(Fila* fi, int e);

int size(Fila* fi);
int isFull(Fila* fi);
int isEmpty(Fila* fi);

int find(Fila* fi, int e);
int tipReturn(Fila* fi, int e);
void callTokens(Fila* fi, int e, int f);

void printFila(Fila* fi);

