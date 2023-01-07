/*Biblioteca feita por Dyego dos Anjos Cordeiro*/
/*vers�o 2.0 ajustes em nomes*/

/*
	A biblioteca "arquivo.h" tem fun��es que usam struct como par�metros, ser� necess�rio adicionar a struct usada e mudar
	o tipo da struct nas fun��es e caso voc� n�o esteja usando uma biblioteca que tenha a sua struct voc� ter� que adicionar
	ela aqui no arquivo.
*/



int ArqDeletarStc(Produtos *Struct, int tamanho, int deletar, char *arquivoNome){
	
	FILE *arquivo;
	
	for(int i=deletar;i<=tamanho;i++){
		Struct[i]=Struct[i+1];
	}
	
	arquivo=fopen(arquivoNome, "w");
	for(int i=0;i<tamanho;i++){
		fwrite(&Struct[i],sizeof(struct tprodutos),1,arquivo);
	}
	fclose(arquivo);
	tamanho--;
	if(tamanho<0){
		remove(arquivoNome);
		arquivo=fopen(arquivoNome,"w");
		fclose(arquivo);
	}
		
	return tamanho;
}

int ArqEscreverStc(Produtos *Struct, int tamanho, char *arquivoNome, char *metodo){
	FILE *arquivo;
	
	arquivo=fopen(arquivoNome, metodo);
	if(arquivo== NULL)
		return -1;
	
	for(int i=0;i<=tamanho;i++)
		fwrite(&Struct[i],sizeof(struct tprodutos),1,arquivo);
	
	
	fclose(arquivo);
	return 1;
}

int ArqLerStc(Produtos *Struct, char *arquivoNome){
	FILE *arquivo;
	
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
