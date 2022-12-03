/*Sintaxes
	linha(){

	PesquisaStr: StcPesquisaStr(tamanho do vetor, string para comparar, variav�l do vetor)
		Compara o valor de uma string e de uma string dentro de um vetor , caso n�o exista el� retorna -1.
		
	PesquisaInt: StcPesquisaInt(tamanho do vetor, n�mero inteiro para comparar, variav�l do vetor)
		Compara o valor de um int e de um int dentro de um vetor e retorna a posi��o dele, caso n�o exista ela retorna -1.
		
	PesquisaFloat: StcPesquisaFloat(tamanho do vetor, n�mero decimal para comparar, variav�l do vetor)
		Compara o valor de um float e de um float dentro de um vetor e retorna a posi��o dele, caso n�o exista ela retorna -1.
*/


void linha(int tamanho){
	printf("\n");
	for(int i=0;i<tamanho;i++)
		printf("-");
//	30
}

int PesquisaStr(int tamanho, char *indice, char *valor){
	for(int i=0;i<=tamanho;i++){
		if(strcmp(indice, valor)==0)
			return i;
	}
	
	return -1;
}

int PesquisaInt(int tamanho, int indice, int valor){
	for(int i=0;i<=tamanho;i++){
		if(valor == indice)
			return i;
	}
	
	return -1;
}

int PesquisaFloat(int tamanho, float indice, float valor){
	for(int i=0;i<=tamanho;i++){
		if(valor == indice)
			return i;
	}
	
	return -1;
}
