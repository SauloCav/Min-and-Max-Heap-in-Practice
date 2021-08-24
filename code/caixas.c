#include "caixas.h"

struct fila{
	int lim;
	int cont;
	int* tipos;
	int* dados;
	int* fichas;
};

Fila* create(int n){
	
	Fila* fi = (Fila*) malloc(sizeof(Fila));
	
	if(fi == NULL){
		return NULL;
	}
	else{
		fi->dados = (int*) malloc(n * sizeof(int));
		fi->tipos = (int*) malloc(n * sizeof(int));
		fi->fichas = (int*) malloc(n * sizeof(int));
		fi->lim = n;
		fi->cont = 0;
		return fi;
	}
			
}

int add(Fila* fi, int e){
	
	if(((fi!=NULL) && (fi->cont < fi->lim)) && (check_add(fi, e))) {
		int posicaoDaInsercao = fi->cont;
		
		fi->dados[posicaoDaInsercao] = e;
		fi->fichas[posicaoDaInsercao] = -1;
		
		fi->cont++;
		
		check_prioridade(fi);
		
		return 1;
	}
	else{
		return 0;
	}	
		
}

void check_prioridade(Fila* fi){
	
	int j = 0;
	
	if(fi->cont == 1){
		fi->tipos[0] = 2;
	}
	else{
		for(int i = 0; i <= fi->cont; i++){
			if(i == 0){
				fi->tipos[i] = 0;
			} 
			else if(i == 4){
				fi->tipos[i] = 0;
			}
			else if(i == 8){
				fi->tipos[i] = 0;
			}
			else{
				fi->tipos[i] = 1;
			}
			j++;
		}
	}
	
		
}	

bool check_add(Fila* fi, int e){
	
	if((e >= 0) && (e <= 9)){
		for(int i = 0; i < fi->cont; i++){
			if(e == fi->dados[i]){
				return false;
			}
		}
		return true;
	}
	else{
		return false;
	}
	
}

bool check_pop(Fila* fi, int e){
	
	if((e >= 0) && (e <= 9)){
		for(int i = 0; i < fi->cont; i++){
			if(e == fi->dados[i]){
				return true;
			}
		}
		return false;
	}
	else{
		return false;
	}
	
}

int pop(Fila* fi, int e){
	
	if((fi!=NULL && !isEmpty(fi)) && (check_pop(fi, e))){
		int i=0, j=0;
		int vetor[fi->cont];
		int vetorFichas[fi->cont];
		
		for(i=0; i<fi->cont; i++){
			if(fi->dados[i] != e){
				vetor[j] = fi->dados[i];
				vetorFichas[j] = fi->fichas[i];
				j++;
			}
		}
		j=0;
		for(i=0; i<(fi->cont); i++){
			fi->dados[j] = vetor[i];
			fi->fichas[j] = vetorFichas[i];
			j++;
		}
		
		fi->cont--;
		
		check_prioridade(fi);
		
		return 1;
	}
	else{	
		return 0;	
	}
	
}

int size(Fila* fi){
	
	if(fi!=NULL && !isEmpty(fi)){
		return fi->cont;
	}
	else{	
		return 0;
	}
	
}

int isFull(Fila* fi){
	
	if(fi==NULL){	
		return 0;	
	}
	else{
		if((fi->cont)==(fi->lim)){	
			return 1;	
		}
		else{
			return 0;	
		}
	}
	
}

int isEmpty(Fila* fi){
	
	if(fi == NULL){	
		return 1;	
	}
	if(fi->cont <= 0){	
		return 1;	
	}	
	else{	
		return 0;	
	}
	
}

int find(Fila* fi, int e){
	
	for(int i = 0; i <= fi->cont; i++){
		if(fi->dados[i] == e){
			return i;
		}
	}
	
	return -1;
	
}

int tipReturn(Fila* fi, int e){
	
	int fin = find(fi, e);
	
	if(fin != -1){
		return fi->tipos[fin];
	}
	else{
		return -1;
	}
	
}

void callTokens(Fila* fi, int e, int f){
	
	int fin = find(fi, e);
	
	fi->fichas[fin] = f;
	
}

void printFila(Fila* fi){
	
	int i=0;
	
	printf("\n              --------------------------- CAIXAS ABERTOS ---------------------------");
	for(i=0; i<fi->cont; i++){
		printf("\n              | [%d] ", fi->dados[i]);
		if(fi->fichas[i] != (-1)){
			if(fi->tipos[i] == 0){
				printf("[Prioritario] [Ficha Atual: %d]", fi->fichas[i]);
			}
			if(fi->tipos[i] == 1){
				printf("[Nao Prioritario] [Ficha Atual: %d]", fi->fichas[i]);
			}
			if(fi->tipos[i] == 2){
				printf("[Prioritario] [Nao Prioritario] [Ficha Atual: %d]", fi->fichas[i]);
			}
		}
		else{
			if(fi->tipos[i] == 0){
				printf("[Prioritario]", fi->fichas[i]);
			}
			if(fi->tipos[i] == 1){
				printf("[Nao Prioritario]", fi->fichas[i]);
			}
			if(fi->tipos[i] == 2){
				printf("[Prioritario] [Nao Prioritario]", fi->fichas[i]);
			}
		}
			
		
	}
	printf("\n              ----------------------------------------------------------------------\n");
	
}

