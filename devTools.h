//Funções Gerais
void linha(){
	printf("\n------------------------------");
}

//A bilioteca "devTools" usa struct como parâmetros então será necessário adiconar a struct usada e mudar algumas coisas dos códigos

typedef struct tprodutos{
	char nome[20];
	char codigo[20];
	float preco;
}Produtos;

/*Sintaxes
	StcExisteStr: StcExiste(tamanho da struct, string para comparar, Struct usada)
		Compara o valor de uma string e de uma string dentro de uma struct e retorna a posição dela, caso não exista elá retorna -1.
		
	StcExisteInt: StcExisteInt(tamanho da struct, número inteiro para comparar, Struct usada)
		Compara o valor de um int e de um int dentro de uma struct e retorna a posição dele, caso não exista ela retorna -1
		
	StcExisteFloat: StcExisteFloat(tamanho da struct, número decimal para comparar, Struct usada)
		Compara o valor de um float e de um float dentro de uma struct e retorna a posição dele, caso não exista ela retorna -1
	
	StcDeletar: StcDeletar(tamanho, posição da struct para deletar, Struct usada)
		Deleta uma struct de uma posição, retornando o novo tamanho da struct
		
	ArqStcDeletar: ArqStcDeletar (tamanho, posição da struct para deletar, Struct usada, ponteiro no arquivo)
		Deleta uma strict de uma posição, retornando o novo tamanho da struct e escrevendo no arquivo
*/

int StcExisteStr(int tamanho, char *indice, Produtos *structe ,char *codigo){
	for(int i=0;i<=tamanho;i++){
		if(strcmp(indice, codigo)==0)
			return i;
	}
	
	return -1;
}

int StcExisteInt(int tamanho, int indice, Produtos *structe){
	for(int i=0;i<=tamanho;i++){
		if(structe[i].preco == indice)
			return i;
	}
	
	return -1;
}

//int StcExisteFloat(int tamanho, float indice, Produtos *structe){
//	for(int i=0;i<=tamanho;i++){
//		if(structe[i].preco == indice)
//			return i;
//	}
//	
//	return -1;
//}

//int StcDeletar(int tamanho, int deletar, Produtos *produtos){
//	for(int i=deletar;i<=tamanho;i++){
//		produtos[i]=produtos[i+1];
//	}
//	tamanho--;
//	return tamanho;
//}

int ArqStcDeletar(int tamanho, int deletar, Produtos *produtos, FILE *produ){
	for(int i=deletar;i<=tamanho;i++){
		produtos[i]=produtos[i+1];
	}
	
	produ=fopen("Produtos.txt", "w");
	for(int i=0;i<tamanho;i++){
		fwrite(&produtos[i],sizeof(struct tprodutos),1,produ);
	}
	fclose(produ);
	tamanho--;
	if(tamanho<0){
		remove("Produtos.txt");
		produ=fopen("Produtos.txt", "w+");
		fclose(produ);
	}
		
	return tamanho;
}
