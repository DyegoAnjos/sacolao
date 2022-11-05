#include <stdio.h>
#include <conio.h>  
#include <stdlib.h>
#include <locale.h> 
#include <string.h> 
#include <ctype.h>

struct tprodutos{
	char nome[20];
	char codigo[20];
	float preco;
};
struct tprodutos produtos[50];

int main(){
	
	int cont=-1, opc;
	char SouN;
	FILE *arq;
	
	setlocale(LC_ALL, "portuguese");
	
	do{	
		arq=fopen("Produtos.bin", "r");
		if(arq== NULL){
			printf("[ERRO] O arquivo não existe.");
			system("pause");
			return 0;
		}
		
		system("cls");
		printf("::::::::::Menu::::::::::");
		printf("\n1-Compras\n2-Guia de preços\n3-Cadastro de produtos\n0-Sair\n");
		scanf("%d", &opc);
		switch(opc){
			case 1:{
			
			break;}
			case 2:{
				arq=fopen("Produtos.bin", "r");
				fread(produtos,sizeof(tprodutos),1,arq);
				printf("%s", produtos[0].nome);
				system("pause");
			break;}
			case 3:{
				arq=fopen("Produtos.bin", "a");
				do{
					system("cls");
					cont++;
					printf("::::::::::Cadastro::::::::::");
					printf("\nDigite o nome do produto:");
					scanf("%s", &produtos[cont].nome);
				
					printf("\nDigite o preço do produto:");
					scanf("%f", &produtos[cont].preco);
				
					printf("\nDigite o código do produto:");
					scanf("%s", &produtos[cont].codigo);
					
					printf("\nDeseja continuar? S/N");
					SouN=toupper(getch());
					
					fwrite(produtos, sizeof(tprodutos), 1, arq);
					
					if(SouN == 'N') break;
				}while(1);
			break;}
		}
	}while(opc!=0);
}
