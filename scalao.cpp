#include <stdio.h>
#include <conio.h>  
#include <stdlib.h>
#include <locale.h> 
#include <string.h> 
#include <ctype.h>
#include "struct.h"
#include "devTools.h"
#include "files.h"

int main(){
	int cont=-1, opc, auxN, contPesquisa;
	char SouN,indice[50];
	float compra;
	FILE *produ;
	
	Produtos produtos[50];
	
	produ=fopen("Produtos.txt", "r");
	if(produ == NULL){
		printf("Erro [404] O arquivo não existe.");
		system("pause");
		return 0;
	}
	fclose(produ);
	
	
	if(cont=StcLerArq(produtos,produ,"Produtos.txt")==NULL){
		printf("Erro [404] O arquivo não existe.");
		system("pause");
		return 0;
	}
	
	else
		cont=StcLerArq(produtos,produ,"Produtos.txt");
	
	setlocale(LC_ALL, "portuguese");
	do{	
		system("cls");
		printf("::::::::::Menu::::::::::");
		printf("\n1-Compras\n2-Guia de produtos\n3-Cadastro de produtos\n0-Sair\n");
		scanf("%d", &opc);
		
		
		switch(opc){
			case 1:{
				system("cls");
				printf("::::::::::Compras::::::::::");
				printf("\ndigite N para parar.");
				compra=0;
				do{
					printf("\nDigite o codigo do produto:");
					scanf("%s", &indice);
					indice[0]=toupper(indice[0]);
					
					for(int i=0;i<=cont;i++){
						if(strcmp(indice,produtos[i].codigo)==0){
							compra+=produtos[i].preco;
						}
					}
					
					printf("\nIndice da compra:%.2f\n", compra);
					
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
				printf("\n1-Pesquisar		2-Deletar	\n	     0-Voltar\n");
				
				for(int i=0;i<=cont;i++){
					printf("\nProduto:%s", produtos[i].nome);
					printf("\nPreço:%.2f", produtos[i].preco);
					printf("\nCódigo:%s", produtos[i].codigo);
					linha(30);
				}
			
				scanf("%d", &opc);
				
				if(opc == 1){
					system("cls");
					printf("::::::::::Pesquisar produtos::::::::::");
					printf("\nDigite o código do produto:");
					scanf("%s", indice);
					indice[0]=toupper(indice[0]);
					
					for(int i=0;i<=cont;i++){
						contPesquisa=PesquisaStr(cont, indice,produtos[i].codigo);
					
					if(contPesquisa != -1){
						printf("\nNome:%s", produtos[contPesquisa].nome);
						printf("\nPreço%.2f:", produtos[contPesquisa].preco);
						printf("\nCódigo:%s\n", produtos[contPesquisa].codigo);
					}
					
					
					
					}
					if(contPesquisa == -1){
						printf("\nProduto não encontrado!!");
					}
					system("pause");
				}
				
				else if(opc == 2){
					system("cls");
					printf("::::::::::Deletar produtos::::::::::");
					printf("\nDigite o código do produto:");
					scanf("%s", indice);
					indice[0]=toupper(indice[0]);
					
					for(int i=0;i<=cont;i++){
						contPesquisa=PesquisaStr(cont, indice ,produtos[i].codigo);
						if(contPesquisa != -1){
							cont=StcDeletarArq(produtos,cont,contPesquisa,produ,"Produtos.txt", "w+");
							printf("\nProduto deletado\n");
							system("pause");
						
						}
					
						else{
							printf("\nProduto não encontrado!!\n");
							system("pause");
						}
					}
				}	
						
				else if(opc==0)	
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
						
					indice[0]=toupper(indice[0]);
					
					strcpy(produtos[cont].nome,indice);
			
					printf("\nDigite o preço do produto:");
					scanf("%f", &produtos[cont].preco);
				
					printf("\nDigite o código do produto:");
					do{
						fflush(stdin);
						scanf("%s", &indice);
						auxN=strlen(indice);
					}while(auxN==0);
					
					if(strcmp(indice,"0")==0)	break;
					
					indice[0]=toupper(indice[0]);
					
					for(int i=0;i<=cont;i++)
					if(PesquisaStr(cont,indice,produtos[i].codigo) != -1){
						printf("Produto já existente\n");
						system("pause");
						cont--;
						break;
					}
					
					strcpy(produtos[cont].codigo,indice);
					
					if(StcEscreverArq(produtos,cont,produ,"Produtos.txt","w")==false){
						printf("Erro [404] O arquivo não existe.");
						system("pause");
						return 0;
					}
					
					printf("\nDeseja continuar? S/N");
					SouN=toupper(getch());
					
					if(SouN == 'N') break;
				}while(1);
			break;}
			
			case 0:{
				return 0;	
			break;}
		}
	}while(1);
	
}
