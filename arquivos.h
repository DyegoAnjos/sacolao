/*
	A biblioteca "arquivo.h" tem funções que usam struct como parâmetros, será necessário adicionar a struct usada e mudar
	o tipo da struct nas funções e caso você não esteja usando uma biblioteca que tenha a sua struct você terá que adicionar
	ela aqui no arquivo.
*/

/*Sintaxes
	ArqDeletarStc: ArqDeletarStc(Struct usada, tamanho, posição da struct para deletar, ponteiro do arquivo, nome do arquivo, método para abri)
		Deleta uma struct de uma posição, retornando o novo tamanho da struct e escrevendo tudo no arquivo de texto.
	
	ArqEscreverStc: ArqEscreverStc(Struct usada, tamanho, ponteiro do arquivo, nome do arquivo, método para abri)
		Escreve toda a struct em um arquivo e retorna 1, caso o arquivo não exista ela retorna -1
		
	ArqLerStc: ArqLerStc(Strct usada, ponteiro do arquivo, nome do arquivo)
		Ler um arquivo que guarda uma struct o colocando na memória, retorna o tamanho da struct-1, caso de erro ou o arquivo não tiver nada ela retorna -1
*/

int ArqDeletarStc(Produtos *Struct, int tamanho, int deletar, FILE *arquivo, char *arquivoNome, char *metodo){
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

int ArqEscreverStc(Produtos *Struct, int tamanho, FILE *arquivo, char *arquivoNome, char *metodo){
	arquivo=fopen(arquivoNome, metodo);
	if(arquivo== NULL)
		return -1;
	
	for(int i=0;i<=tamanho;i++)
		fwrite(&Struct[i],sizeof(struct tprodutos),1,arquivo);
	
	
	fclose(arquivo);
	return 1;
}

int ArqLerStc(Produtos *Struct, FILE *arquivo, char *arquivoNome){
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
