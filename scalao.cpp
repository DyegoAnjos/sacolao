#include <stdio.h>
#include <conio.h>  
#include <stdlib.h>
#include <locale.h> 
#include <string.h> 
#include <ctype.h>

void linha(){
	printf("\n------------------------------");
}

struct tprodutos{
	char nome[20];
	char codigo[20];
	float preco;
};
struct tprodutos produtos[50];

int main(){
	
	int cont=-1, opc, auxN;
	char SouN,indice[50];
	float compra;
	FILE *produ;
	
	setlocale(LC_ALL, "portuguese");
	
	do{	
		produ=fopen("Produtos.bin", "r");
		if(produ== NULL){
			printf("[ERRO] O arquivo não existe.");
			system("pause");
			return 0;
		}
		
		system("cls");
		printf("::::::::::Menu::::::::::");
		printf("\n1-Compras\n2-Guia de produtos\n3-Cadastro de produtos\n0-Sair\n");
		scanf("%d", &opc);
		switch(opc){
			case 1:{
				system("cls");
				do{
					printf("::::::::::Compras::::::::::");
					printf("\nDigite o nome do produto:");
					scanf("%s", &indice);
					for(int i=0;i<=cont;i++){
						if(strcmp(indice,produtos[i].nome)==0){
							compra+=produtos[i].preco;
						}
					}
					
					printf("\nIndice da compra:%.2f", compra);
					
					printf("\nDeseja continuar? S/N\n");
					SouN=toupper(getch());
					
					if(SouN == 'N'){
						printf("\nTotal da Compra:%.2f", compra);
						printf("\n1-Compra\n2-Cancelar");
						scanf("%d", &opc);
						
						if(opc==1){
							printf("\nCompra feita");
							getch();
							break;
						}
						
						if(opc==2){
							printf("\nCompra cancelada");
							getch();
							break;
						}
					} 
				}while(1);
			break;}
			
			case 2:{
				system("cls");
				printf("::::::::::Guia de produtos::::::::::");
				for(int i=0;i<=cont;i++){
					printf("\nProduto:%s", produtos[i].nome);
					printf("\nPreço:%.2f", produtos[i].preco);
					printf("\nCódigo:%s", produtos[i].codigo);
					linha();
				}
				getch();
			break;}
			
			case 3:{
				do{
					system("cls");
					cont++;
					printf("::::::::::Cadastro::::::::::");
					printf("\nDigite o nome do produto:");
					do{
						fflush(stdin);
						scanf("%s", &indice);
						auxN=strlen(indice);
					}while(auxN==0);
					if(strcmp(indice,"0")==0)	break;
						
					strcpy(produtos[cont].nome,indice);
					produtos[cont].nome[0]=toupper(produtos[cont].nome[0]);
					
			
					printf("\nDigite o preço do produto:");
					scanf("%f", &produtos[cont].preco);
				
					printf("\nDigite o código do produto:");
					do{
						fflush(stdin);
						scanf("%s", &indice);
						auxN=strlen(indice);
					}while(auxN==0);
					if(strcmp(indice,"0")==0)	break;
						
					strcpy(produtos[cont].codigo,indice);
					produtos[cont].codigo[0]=toupper(produtos[cont].codigo[0]);
					
				
					printf("\nDeseja continuar? S/N");
					SouN=toupper(getch());
					
					if(SouN == 'N') break;
				}while(1);
			break;}
		}
	}while(opc!=0);
}
