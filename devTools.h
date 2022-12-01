void linha(){
	printf("\n------------------------------");
}

//A bilioteca "devTools" usa struct como 

typedef struct tprodutos{
	char nome[20];
	char codigo[20];
	float preco;
}Produtos;

bool validarIgual(int tamanho, char *indice, Produtos *produtos, char *codigo){
	for(int i=0;i<=tamanho;i++){
		if(strcmp(indice,produtos[i].codigo)==0)
			return false;
	}
	
	return true;
}

int comparaNome(char *codigo, int cont, Produtos *produtos){
	int i=0;
	
	for(i=0;i<=cont;i++){
		if(strcmp(codigo, produtos[i].codigo)==0)
			return i;
	}
	
	return -1;
}

int deletar(int deletar,int cont, FILE *produ, Produtos *produtos){
	for(int i=deletar;i<=cont;i++){
		produtos[i]=produtos[i+1];
	}
	
	produ=fopen("Produtos.txt", "w");
	for(int i=0;i<cont;i++){
		fwrite(&produtos[i],sizeof(struct tprodutos),1,produ);
	}
	fclose(produ);
	cont--;
	if(cont<0){
		remove("Produtos.txt");
		produ=fopen("Produtos.txt", "w+");
		fclose(produ);
	}
		
	return cont;
}
