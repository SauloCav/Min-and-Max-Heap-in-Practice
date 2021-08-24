#include "filas.h"

heap* criar(int nmax){
	
	heap *h = (heap *) malloc(sizeof(heap));
	h->n = 0;
	h->nmax = nmax;
	h->v = (int *) malloc(h->nmax * sizeof(int));
	
	return h;
	
}

void heap_libera(heap *h){
	
	free(h->v);
	free(h);
	
}

int heap_vazia(heap *h){
	
	if(h->n == 0){
		return 0;
	} 
	else{
		return 1;
	} 
	
}

void sobe_max(heap *h, int i){
	
	int pai;
	
	while(i>0){
		pai = pai(i);
		
		if((h->v[pai])> (h->v[i]))
			break;
		
		troca(h, pai, i);
		i = pai;
	}
	
}

void desce_max(heap *h, int i){
	
	int aux = esq(i);
	int filho_dir;
	
	while(aux < h->n){
		filho_dir = dir(i);
		
		if((filho_dir < h->n) && (h->v[filho_dir] > h->v[aux]))
			aux = filho_dir;
		if(h->v[aux] < h->v[i])
			break;	
			
		troca(h, i, aux);
		i = aux;
		aux = esq(i);		
	}
	
}

void heap_insere_max(heap *h, int valor){
	
	h->v[h->n++] = valor;
	sobe_max(h, h->n-1);	
	
}

int heap_retira_max(heap *h){
	
	int topo = h->v[0];
	
	h->v[0] = h->v[--(h->n)];
	desce_max(h,0);
	
	return topo;
	
}

void sobe_min(heap *h, int i){
	
	int pai;
	
	while(i>0){
		pai = pai(i);
		
		if((h->v[pai]) < (h->v[i]))
			break;
		
		troca(h, pai, i);
		i = pai;
	}
	
}

void desce_min(heap *h, int i){
	
	int aux = esq(i);
	int filho_dir;
	
	while(aux < h->n){
		filho_dir = dir(i);
		
		if((filho_dir < h->n) && (h->v[filho_dir] < h->v[aux]))
			aux = filho_dir;
		if(h->v[aux] > h->v[i])
			break;	
			
		troca(h, i, aux);
		i = aux;
		aux = esq(i);		
	}
	
}

void heap_insere_min(heap *h, int valor){
	
	h->v[h->n++] = valor;
	sobe_min(h, h->n-1);
	
}

int heap_retira_min(heap *h){
	
	int topo = h->v[0];
	
	h->v[0] = h->v[--(h->n)];
	desce_min(h, 0);
	
	return topo;
	
}

void troca(heap *h, int i, int j){
	
	int temp = h->v[i];
	
	h->v[i] = h->v[j];
	h->v[j] = temp;
	
}

void mostrar(heap *h){
	
	int i=0;
	
	for(int i=0;i<h->n;i++){
		printf(" %d |", h->v[i]);
	}
}

