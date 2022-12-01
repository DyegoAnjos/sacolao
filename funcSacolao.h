//Struct Usada
bool escreverArq (int cont, FILE *produ, Produtos *produtos){
	produ=fopen("Produtos.txt", "w");
	if(produ== NULL)
		return false;
	
	for(int i=0;i<=cont;i++){
		fwrite(&produtos[i],sizeof(struct tprodutos),1,produ);
	}
	
	fclose(produ);
	return true;
}

int lerArq (FILE *produ, Produtos *produtos){
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
