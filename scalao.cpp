#include <stdio.h>
#include <conio.h>  
#include <stdlib.h>
#include <locale.h> 
#include <string.h> 
#include <ctype.h>

void linha(){
	printf("\n------------------------------");
}

typedef struct tprodutos{
	char nome[20];
	char codigo[20];
	float preco;
}Produtos;

Produtos produtos[50];

bool validarIgual(int cont, char *indice){
	for(int i=0;i<=cont;i++){
		if(strcmp(indice,produtos[i].codigo)==0)
			return false;
	}
	
	return true;
}

bool escreverArq (int cont, FILE *produ){
	produ=fopen("Produtos.txt", "a");
	if(produ== NULL)
		return false;
	
	for(int i=0;i<=cont;i++){
		fwrite(&produtos[i],sizeof(struct tprodutos),1,produ);
	}
	
	fclose(produ);
	return true;
}

int lerArq ( FILE *produ){
	int i=-1;
	produ=fopen("Produtos.txt", "r");
	if(produ == NULL)
		return 404;
	
	while(!feof(produ)){
		i++;	
		fread(&produtos[i],sizeof(struct tprodutos),1,produ);
	}
	fclose(produ);
	return i-1;
}

int comparaNome(char *codigo, int cont){
	int i=0;
	
	for(i=0;i<=cont;i++){
		if(strcmp(codigo, produtos[i].codigo)==0)
			return i;
	}
	
	return -1;
}

int deletar(int deletar,int cont, FILE *produ){
	for(int i=deletar;i<=cont;i++){
		produtos[i]=produtos[i+1];
	}
	
	produ=fopen("Produtos.txt", "w");
	for(int i=0;i<=cont;i++){
		fwrite(&produtos[i],sizeof(struct tprodutos),1,produ);
	}
	
	fclose(produ);
	
	return cont-1;
}

int main(){
	
	int cont=-1, opc, auxN, contPesquisa;
	char SouN,indice[50];
	float compra;
	FILE *produ;
	
	
	produ=fopen("Produtos.txt", "r");
	if(produ== NULL){
		printf("Erro [404] O arquivo não existe.");
		system("pause");
		return 0;
	}
	fclose(produ);
	
	setlocale(LC_ALL, "portuguese");
	
	if(cont=lerArq(produ)==404){
		printf("Erro [404] O arquivo não existe.");
		system("pause");
		return 0;
	}
	
	else
		cont=lerArq(produ);
	
	do{	
		system("cls");
		printf("::::::::::Menu::::::::::");
		printf("\n1-Compras\n2-Guia de produtos\n3-Cadastro de produtos\n0-Sair\n");
		scanf("%d", &opc);
		switch(opc){
			case 1:{
				system("cls");
				do{
					compra=0;
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
				printf("\n1-Pesquisar		2-Deletar	\n	     0-Voltar\n");
				
				for(int i=0;i<=cont;i++){
					printf("\nProduto:%s", produtos[i].nome);
					printf("\nPreço:%.2f", produtos[i].preco);
					printf("\nCódigo:%s", produtos[i].codigo);
					linha();
				}
				
				scanf("%d", &opc);
				
				if(opc == 1){
					system("cls");
					printf("::::::::::Pesquisar produtos::::::::::");
					printf("\nDigite o código do produto:");
					scanf("%s", indice);
					contPesquisa=comparaNome(indice, cont);
					if(contPesquisa != -1){
						printf("\nNome:%s", produtos[contPesquisa].nome);
						printf("\nPreço%.2f:", produtos[contPesquisa].preco);
						printf("\nCódigo:%s\n", produtos[contPesquisa].codigo);
					}
					
					else
						printf("\nProduto não encontrado!!");
					
					system("pause");
				}
				
				else if(opc == 2){
					system("cls");
					printf("::::::::::Pesquisar produtos::::::::::");
					printf("\nDigite o código do produto:");
					scanf("%s", indice);
					contPesquisa=comparaNome(indice, cont);
					if(contPesquisa != -1){
						cont=deletar(contPesquisa,cont,produ);
						printf("\nProduto deletado\n");
						system("pause");
						
					}
					
					else{
						printf("\nProduto não encontrado!!\n");
						system("pause");
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
					
					if(validarIgual(cont,indice)==false){
						printf("Produto já existente\n");
						system("pause");
						cont--;
						break;
					}
					
					strcpy(produtos[cont].codigo,indice);
					
					if(escreverArq(cont, produ)==false){
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
