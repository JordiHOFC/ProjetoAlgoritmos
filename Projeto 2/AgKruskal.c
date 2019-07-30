#include<stdio.h>
#include<stdlib.h>

typedef struct Aresta{
	int verticeDestino;
	double peso;
	struct Aresta * prox;	
}ARESTA;

typedef struct  svertice{
	int vertice;
	ARESTA * arestas;
}Vertice;
typedef struct grafo{
	int numeroVertices;
	int numeroArestas;
	Vertice * vertices;
}GRAFO;
typedef struct SarestaMenorcusto{
	int vOrigem;
	int vDestino;
	double Peso;
	int tamanho;
}AMENOR;

GRAFO * criarGrafo(int nV,int nA){
	GRAFO * gr;
	gr=(GRAFO*)malloc(sizeof(GRAFO));
	gr->vertices=(Vertice*)malloc(nV*sizeof(Vertice));
	gr->numeroVertices=nV;
	gr->numeroArestas=nA;
	return gr;
}
void inicializarLista(ARESTA **lista){
	(*lista)=NULL;
}
int listaVazio(ARESTA **lista){
	if((*lista)==NULL){
		return 1;
	}
	
	return 0;
}
ARESTA * criarAresta(){
	ARESTA * celula=(ARESTA*)malloc(sizeof(ARESTA));
	celula->prox=NULL;
	return celula;
}
AMENOR * ArestaMenorCusto(){
	AMENOR  * celula =(AMENOR*)malloc(sizeof(AMENOR));
	return celula;
}



int inserirAresta(ARESTA ** lista,int vertice,float peso){
	ARESTA *nova=criarAresta();
	ARESTA * aux;
	nova->peso=peso;
	nova->verticeDestino=vertice;
	//verificamos se a lista esta vazia
	if(listaVazio(lista)==1){
		(*lista)=nova;
		return 1;
	}
	//se nao tiver vazia
	aux = (*lista);
	while(aux->prox != NULL)
	{
		aux = aux->prox;
	}
	
	aux->prox=nova;
	return 1;
}

ARESTA * removerARESTA(ARESTA ** lista,int arestacmVertice){
	ARESTA *aux=(*lista);
	ARESTA *auxanterior;
	ARESTA *removida=criarAresta();
	//removida->peso=peso;
	removida->verticeDestino=arestacmVertice;
	//percorre a lista de adj
	
	//verificamos se a lista esta no inicio
	if(listaVazio(&aux)==1){
		return NULL;
	}
	while(aux!=NULL){
		if(arestacmVertice==aux->verticeDestino){			
			//verificamos se a primeira da lista
			if(aux==(*lista)){
				removida->peso=aux->peso;
				(*lista)=aux->prox;
				free(aux);
				return removida;
			}
			//caso a celula estaja no meio ou final da lista
			auxanterior->prox=aux->prox;
			removida->peso=aux->peso;
			free(aux);
			return removida;
			
			
		}
		auxanterior=aux;
		aux=aux->prox;
	}
	
	
}
void imprimirLista(ARESTA **lista){
	ARESTA * aux=(*lista);
	while(aux!=NULL){
		printf("\t%d(%lf) ",aux->verticeDestino,aux->peso);
		aux=aux->prox;
	}
}

int existezero(GRAFO * gr,int vertice){
	int n=0;
	ARESTA *aux;
		aux=gr->vertices[vertice].arestas;
		while(aux!=NULL){
			if(aux->peso==0.00000000){
				n++;
			}
			aux=aux->prox;	
		}
	
		return n;	
}
void imprimirGrafo(GRAFO *gr){
	int i;
	for(i=0;i<gr->numeroVertices;i++){
		printf("\n\n%d->\n\n",gr->vertices[i].vertice);
		imprimirLista(&gr->vertices[i].arestas);
		printf("\n (%d)",existezero(gr,i));
	}
}
int existeVertice(GRAFO * gr, int vertinho){
	int i;
	for(i=0;i<gr->numeroVertices;i++){
		if(gr->vertices[i].vertice==vertinho){
			return i;
		}
		
	}
	return -1;
}




void lerinstancia(GRAFO * gr)
{
	int i = 0, verticePai, verticeDest,x;
	double pesoRecv;
	
	FILE *fp=fopen("arquivo.txt","r");
	for(i=0;i<gr->numeroVertices;i++){
		gr->vertices[i].vertice=i+1;
		inicializarLista(&gr->vertices[i].arestas);
	}
	i = 0;
	
	while(fscanf(fp,"%d %d %lf",&verticePai,&verticeDest,&pesoRecv)!=EOF && i<=gr->numeroVertices){
		x=existeVertice(gr,verticePai);
		if(x==-1){
			gr->vertices[i].vertice=verticePai;
			inserirAresta(&gr->vertices[i].arestas,verticeDest,pesoRecv);
				//printf("\nfreekick\n");
		}
			inserirAresta(&gr->vertices[x].arestas,verticeDest,pesoRecv);
			//	printf("\nfreekick\n");		
	}
	i++;
	
}
AMENOR * getArestaMenorC(GRAFO * gr){
	int i;
	ARESTA * aux;
	AMENOR *celula=ArestaMenorCusto();
	float menor=1000000;
	for(i=0;i<gr->numeroVertices;i++){
		aux=gr->vertices[i].arestas;
		while(aux!=NULL){
			if(menor>aux->peso && aux->peso!=0.000000){
				menor=aux->peso;
				celula->Peso=aux->peso;
				celula->vDestino=aux->verticeDestino;
				celula->vOrigem=i;
				
			}
		aux=aux->prox;
		}
	}
	removerARESTA(&gr->vertices[celula->vOrigem].arestas,celula->vDestino);
	return celula;
}
AMENOR * getpesoZero(GRAFO * gr){
	int i;
	ARESTA *aux;
	AMENOR *celula=ArestaMenorCusto();
	float menor=1000000;
	for(i=0;i<gr->numeroVertices;i++){
		aux=gr->vertices[i].arestas;
		while(aux!=NULL){
			if(aux->peso==0.00000){
				menor=aux->peso;
				celula->Peso=aux->peso;
				celula->vDestino=aux->verticeDestino;
				celula->vOrigem=i;
				
			}
		aux=aux->prox;
		
		}
		
	}
	
	return celula;
}

AMENOR * gerarVetordeMenorCusto(GRAFO * gr){
	int i;
	AMENOR *celula = (AMENOR*)malloc((22348)*sizeof(AMENOR));
	AMENOR *aux1;	

	for(i=0;i<(22348);i++){ // São 22348 arestas pois são 22500 arestas menos 152 arestas de peso 0;
		                     // no caso 150 pesos 0 pois são as distancias dos vertices para eles mesmos
		aux1=getArestaMenorC(gr);  // e mais duas arestas de peso 0, não entra no caso. 
		celula[i].vOrigem = aux1->vOrigem;
		celula[i].vDestino = aux1->vDestino;
		celula[i].Peso = aux1->Peso;
		
	}
	return celula;
}
int buscar(int  pai[], int vertice){
	if(pai[vertice] == -1){
		return vertice;
	}		
	return buscar(pai, pai[vertice]);

}
void unir(int  pai[], int vertice1, int vertice2){
	int v1_set = buscar(pai, vertice1);
	int v2_set = buscar(pai, vertice2);
	pai[v1_set] = v2_set;
}




void AlgoritmoKruskal(GRAFO *gr) {
	//SALVA A SAIDA NO ARQUIVO 
	FILE * a=fopen("respostasK.txt","w+");
	//arvore geradora minima
	int i, cont = 0, iteracoes =gr->numeroArestas-152 ;
	AMENOR agm[gr->numeroVertices - 1];// grafo
	
	//chamar as arestas ordedanas de menor para maior peso
	AMENOR * arestas=gerarVetordeMenorCusto(gr);
	
	//criamos o vertor de rotulos do tamanho da quantidade de vertices do grafo
	int *pai = (int*)malloc(gr->numeroVertices * sizeof(int));
	
	//inicializar o subset com valor de vazio(-1)
	                                                                              
	for (i = 0; i <150; i++) {
		pai[i] = -1;
	}

	//agora vamos verificar se as arestas fazem uniao uma com as outras gr->numeroArestas
	for (i = 0; i < iteracoes; i++) {
		int v1 = buscar(pai, arestas[i].vOrigem);
		int v2 = buscar(pai, arestas[i].vDestino);

		if (v1 != v2) {
			agm[cont].vOrigem = arestas[i].vOrigem;
			agm[cont].vDestino = arestas[i].vDestino;
			agm[cont].Peso = arestas[i].Peso;
			printf(" ");
			unir(pai, v1, v2);	
			cont++;
		}
	}
	
	printf("\n ARVORE GERADORA MINIMA\n");
	double custoTotalA = 0.000000;
	for (i = 0; i < 149; i++) {

		printf("%d \t %d \t %lf\n", agm[i].vOrigem, agm[i].vDestino, agm[i].Peso);
		custoTotalA = custoTotalA+agm[i].Peso;	
		fprintf(a,"%d \t %d \t %lf\n", agm[i].vOrigem, agm[i].vDestino, agm[i].Peso);	
	}
	printf("\n\nCUSTO TOTAL DA ARVORE:   %lf \n\n",custoTotalA);
	fprintf(a,"\n\nCUSTO TOTAL DA ARVORE:   %lf \n\n",custoTotalA);
	fclose(a);

}



int main(){
	GRAFO * gr;
	gr=criarGrafo(150,22500);	
	lerinstancia(gr);	
	AlgoritmoKruskal(gr);

	return 0;
}
