#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<windows.h>

#define pai(i) (((i)-1)/2)
#define esq(i) (2*(i)+1)
#define dir(i) (2*(i)+2)

typedef struct{
	int n;
	int nmax;
	int *v;
} heap;

heap* criar(int nmax);
void heap_libera(heap *h);
int heap_vazia (heap *h);

void sobe_max (heap *h, int i);
void desce_max (heap *h, int i);
void heap_insere_max (heap *h, int valor);
int heap_retira_max (heap *h);

void sobe_min (heap *h, int i);
void desce_min (heap *h, int i);
void heap_insere_min (heap *h, int valor);
int heap_retira_min (heap *h);

void troca (heap *h, int i, int j);

void mostrar(heap *h);

