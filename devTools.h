//Fun��es Gerais
void linha(){
	printf("\n------------------------------");
}

//A bilioteca "devTools" usa struct como par�metros ent�o ser� necess�rio adiconar a struct usada e mudar algumas coisas dos c�digos

typedef struct tprodutos{
	char nome[20];
	char codigo[20];
	float preco;
}Produtos;

/*Sintaxes
	StcPesquisaStr: StcExiste(tamanho da struct, string para comparar, Struct usada)
		Compara o valor de uma string e de uma string dentro de uma struct e retorna a posi��o dela, caso n�o exista el� retorna -1.
		
	StcPesquisaInt: StcExisteInt(tamanho da struct, n�mero inteiro para comparar, Struct usada)
		Compara o valor de um int e de um int dentro de uma struct e retorna a posi��o dele, caso n�o exista ela retorna -1
		
	StcPesquisaFloat: StcExisteFloat(tamanho da struct, n�mero decimal para comparar, Struct usada)
		Compara o valor de um float e de um float dentro de uma struct e retorna a posi��o dele, caso n�o exista ela retorna -1
	
	StcDeletar: StcDeletar(tamanho, posi��o da struct para deletar, Struct usada)
		Deleta uma struct de uma posi��o, retornando o novo tamanho da struct
	
	StcDeletarArq: StcDeletar(tamanho, posi��o da struct para deletar, Struct usada)
		Deleta uma struct de uma posi��o, retornando o novo tamanho da struct e escrevendo tudo no arquivo de texto.
*/

int StcPesquisaStr(int tamanho, char *indice, char *valor){
	for(int i=0;i<=tamanho;i++){
		if(strcmp(indice, valor)==0)
			return i;
	}
	
	return -1;
}

int StcPesquisaInt(int tamanho, int indice, int valor){
	for(int i=0;i<=tamanho;i++){
		if(valor == indice)
			return i;
	}
	
	return -1;
}

int StcPesquisaFloat(int tamanho, float indice, float valor){
	for(int i=0;i<=tamanho;i++){
		if(valor == indice)
			return i;
	}
	
	return -1;
}

int StcDeletar(Produtos *Struct, int tamanho, int deletar){
	for(int i=deletar;i<=tamanho;i++){
		Struct[i]=Struct[i+1];
	}
	tamanho--;
	return tamanho;
}

int StcDeletarArq(Produtos *Struct, int tamanho, int deletar, FILE *arquivo, char *arquivoNome, char *metodo){
	for(int i=deletar;i<=tamanho;i++){
		Struct[i]=Struct[i+1];
	}
	
	arquivo=fopen(arquivoNome, metodo);
	for(int i=0;i<tamanho;i++){
		fwrite(&Struct[i],sizeof(struct tprodutos),1,arquivo);
	}
	fclose(arquivo);
	tamanho--;
	if(tamanho<0){
		remove(arquivoNome);
		arquivo=fopen(arquivoNome, metodo);
		fclose(arquivo);
	}
		
	return tamanho;
}

int StcEscreverArq (Produtos *Struct, int tamanho, FILE *arquivo, char *arquivoNome, char *metodo){
	arquivo=fopen(arquivoNome, metodo);
	if(arquivo== NULL)
		return -1;
	
	for(int i=0;i<=tamanho;i++)
		fwrite(&Struct[i],sizeof(struct tprodutos),1,arquivo);
	
	
	fclose(arquivo);
	return 1;
}

int StcLerArq (Produtos *Struct, FILE *arquivo, char *arquivoNome){
	int i=-1;
	arquivo=fopen(arquivoNome, "r");
	if(arquivo == NULL)
		return -1;
	
	while(!feof(arquivo)){
		i++;	
		fread(&Struct[i],sizeof(struct tprodutos),1,arquivo);
	}
	fclose(arquivo);
	return i-1;
}
