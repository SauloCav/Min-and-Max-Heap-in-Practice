#include "filas.h"
#include "caixas.h"

int main(){
	
	int op, valor, tipo_cliente, maximo_elementos = 50;
	int valor_min = 1, valor_max = 100, caixa_num = 0, troca_caixa = 0;
	char cpf_cnpj[4];
	
	heap *hmax = criar(maximo_elementos);
	heap *hmin = criar(maximo_elementos);
	
	int esc;
	
	printf("\n         Pressione Qualquer Tecla para Abrir 2 Caixas e Iniciar os Atendimentos");
	getch();
	Sleep(200); printf("."); Sleep(200); printf("."); Sleep(200); printf("."); Sleep(200); printf(".");
	system("cls");
	Fila* fi = create(10);
	add(fi, caixa_num);
	caixa_num++;
	add(fi, caixa_num);
	
	do{
		
	fflush(stdin);
	
	printFila(fi);
	
	printf("\n              ------------------------------- FILAS --------------------------------\n");
	printf("              | Nao Prioritaria:");
	mostrar(hmax);
	printf("\n              | Prioritaria:");
	mostrar(hmin);
	printf("\n              ----------------------------------------------------------------------\n");	
	
	printf("\n              -------------------------------- MENU --------------------------------");
	printf("\n              |  |1| Gerar Senha para um Novo Cliente       |2| Abrir Novo Caixa   |");
	printf("\n              |  |3| Chamar Cliente para Atendimento        |4| Fechar um Caixa    |");
	printf("\n              |  |0| Sair                                                          |");
	printf("\n              ----------------------------------------------------------------------\n\n");
	
	printf("                                   Escolha uma das opcoes: ");
	scanf("%d", &esc);
	
	if(esc==0){
		system("cls");
	}
	
	switch(esc){
		
		case (1):{
			
			printf("\n  O Cliente Deseja entrar com CPF ou CNPJ? ");
			scanf("%s", cpf_cnpj);
				printf("\n  Com Relacao ao Cliente:\n");
				printf("  1 - Se Declara Deficiente Fisico\n");
				printf("  2 - Se Declara Idoso com 60 Anos ou Mais\n");
				printf("  3 - Se Declara Gestante\n");
				printf("  4 - Se Declara Lactante\n");
				printf("  5 - Esta Acompanhado de uma crianca de colo\n");
				printf("  6 - Nenhum dos Anteriores\n");
			do{
				printf("  Escolha uma das opcoes: ");
				scanf("%d", &tipo_cliente);
			}while((tipo_cliente <= 0) || (tipo_cliente > 6));
			
			if(tipo_cliente == 6){
				heap_insere_max(hmax, valor_max);
				valor_max--;
			}
			else{
				heap_insere_min(hmin, valor_min);
				valor_min++;
			}
			
			printf("\n\n");
			Sleep(200);
			printf("  .");
			Sleep(200);
			printf("  .");
			Sleep(200);
			printf("  .");
			break;
			
		}
		
		case (2):{
			
			printf("\n  Sao 10 Caixas (0-9)\n");
			printf("  Insira o Caixa: ");
			scanf("%d", &caixa_num);
			
			int ad = add(fi, caixa_num);
			if(ad == 0){
				printf("\n  Entrada Invalida! Nao foi Possivel Abrir O Caixa!\n");
			}
    		
			printf("\n\n");
			Sleep(200);
			printf("  .");
			Sleep(200);
			printf("  .");
			Sleep(200);
			printf("  .");	
			break;
			
		}
		
		case (3):{
			
			if(((heap_vazia(hmin)) == 0) && ((heap_vazia(hmax) == 0))){
				printf("\n  As Filas Estao Vazias!\n");
			}
			else{
				printf("\n  Insira o Caixa Que Atendera o Cliente: ");
				scanf("%d", &caixa_num);
				
				int fil = tipReturn(fi, caixa_num);
				if(fil == 0){
					int vaz = heap_vazia(hmin);
					
					if(vaz == 1){
						int ficha = heap_retira_min(hmin);
						callTokens(fi, caixa_num, ficha);
					}
					else{
						int ficha = heap_retira_max(hmax);
						callTokens(fi, caixa_num, ficha);
					}
				}
				else if(fil == 1){
					int vaz = heap_vazia(hmax);
					
					if(vaz == 1){
						int ficha = heap_retira_max(hmax);
						callTokens(fi, caixa_num, ficha);
					}
					else{
						int ficha = heap_retira_min(hmin);
						callTokens(fi, caixa_num, ficha);
					}
				}
				else if(fil == 2){
					int vazmax = heap_vazia(hmax);
					int vazmin = heap_vazia(hmin);
					
					if(troca_caixa == 0){
						if(vazmax == 1){
							int ficha = heap_retira_max(hmax);
							callTokens(fi, caixa_num, ficha);
						}
						else{
							int ficha = heap_retira_min(hmin);
							callTokens(fi, caixa_num, ficha);
						}
						troca_caixa = 1;
					}
					else{
						if(vazmin == 1){
							int ficha = heap_retira_min(hmin);
							callTokens(fi, caixa_num, ficha);
						}
						else{
							int ficha = heap_retira_max(hmax);
							callTokens(fi, caixa_num, ficha);
						}
						troca_caixa = 0;
					}
					
				}
				else if(fil == -1){
					printf("\n  Entrada Invalida! Este Caixa Nao Existe ou Nao Foi Aberto!\n");
				}
			}
			
			printf("\n\n");
			Sleep(200);
			printf("  .");
			Sleep(200);
			printf("  .");
			Sleep(200);
			printf("  .");	
			break;
			
		}
		
		case (4):{
			
			printf("\n  Insira o Caixa: ");
			scanf("%d", &caixa_num);
			
			int tam = size(fi);
			if(tam == 1){
				if((heap_vazia(hmax)) && (heap_vazia(hmax))){
					printf("\n  Nao foi Possivel Fechar O Caixa!\n");
					printf("\n  Para Fachar Todos os Caixas Deve-se Esvaziar Ambas as Filas!\n");
				}
				else{
					int po = pop(fi, caixa_num);
					if(po == 0){
						printf("\n  Nao foi Possivel Fechar O Caixa!\n");
					}
					
					esc = 0;
					
					printf("\n\n              ------------------------ PROGRAMA FINALIZADO -------------------------");
					printf("\n                                        Filas Finalizadas!");
					printf("\n                                         Caixas Fechados!");
					printf("\n                                        Fim de Expediente!");
					printf("\n              ----------------------------------------------------------------------");
					
				}
			}
			else{
				int po = pop(fi, caixa_num);
				if(po == 0){
					printf("\n  Nao foi Possivel Fechar O Caixa!\n");
				}
			}
			
			printf("\n\n");
			Sleep(200);
			printf("  .");
			Sleep(200);
			printf("  .");
			Sleep(200);
			printf("  .");	
			break;
			
		}
		
		case (0):{
			
			printf("\n              ------------------------ PROGRAMA FINALIZADO -------------------------");
			printf("\n              ----------------------------------------------------------------------");
			
			printf("\n\n");
			Sleep(200);
			printf("  .");
			Sleep(200);
			printf("  .");
			Sleep(200);
			printf("  .");	
			break;
			
		}
		
	}
	
	getch();
	system("cls");
	}while(esc!=0);	
	
}

