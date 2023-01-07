/*Biblioteca feita por Dyego dos Anjos Cordeiro*/
/*versão 2.0 ajustes em nomes*/
//A bilioteca "struct.h" usa struct como parâmetros, será necessário adiconar a struct usada e mudar o tipo da struct nas funções
typedef struct tprodutos{
	char nome[20];
	char codigo[20];
	float preco;
}Produtos;


int stcdeletar(Produtos *Struct, int tamanho, int deletar){
	for(int i=deletar;i<=tamanho;i++){
		Struct[i]=Struct[i+1];
	}
	tamanho--;
	return tamanho;
}
