//A bilioteca "struct.h" usa struct como parâmetros, será necessário adiconar a struct usada e mudar o tipo da struct nas funções

typedef struct tprodutos{
	char nome[20];
	char codigo[20];
	float preco;
}Produtos;

/*Sintaxes
	StcDeletar: StcDeletar(Struct usada,tamanho, posição da struct para deletar)
		Deleta uma struct de uma posição, retornando o novo tamanho da struct.
*/

int StcDeletar(Produtos *Struct, int tamanho, int deletar){
	for(int i=deletar;i<=tamanho;i++){
		Struct[i]=Struct[i+1];
	}
	tamanho--;
	return tamanho;
}
