#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define TAM 22500
#define QUAT_VERT 150

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
// estruturas do min heap
struct MinHeapNode {
    int v;
    int key;
};

struct MinHeap {
    int size;
    int capacity;
    int* pos; // necessario para o metodo decreaseKey()
    struct MinHeapNode** array;
};


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
void lerinstancia(GRAFO * gr){
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
/* FUNCOES HEAPIFY */

// criar nova celula min heap
struct MinHeapNode* newMinHeapNode(int v, int key) {
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->key = key;
    return minHeapNode;
}

// criar e inicializar a min heap
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->pos = (int*)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// funcao que troca dois nos da min heap. minHeapify() usa
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Executar heap em determinado indice
// Essa funcao tambem atualiza a posicao dos nos quando eles sao trocados
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->key < minHeap->array[smallest]->key)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->key < minHeap->array[smallest]->key)
        smallest = right;

    if (smallest != idx) {
        // Os nos a serem trocados em min heap
        struct MinHeapNode* smallestNode = minHeap->array[smallest];
        struct MinHeapNode* idxNode = minHeap->array[idx];

        // trocar posicoes
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        // trocar posicoes
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

// checar se a min heap ta vazia
int isEmpty(struct MinHeap* minHeap) {
    return minHeap->size == 0;
}

// encontrar o menor no da heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    if (isEmpty(minHeap))
        return NULL;

    // guarda no raiz
    struct MinHeapNode* root = minHeap->array[0];

    // Substitui o no raiz pelo ultimo no
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    // atualiza posicao do ultimo no
    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    // decrementa o tamanho da heap
    // e raiz do heapify
    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

// Funcao para diminuir o valor da chave de um determinado vertice v
// Esta funcao usa a posicao (*pos) do min heap para obter o indice atual do no no heap minimo
void decreaseKey(struct MinHeap* minHeap, int v, int key) {
    // pegar indice de v no vetor de heap
    int i = minHeap->pos[v];

    // pega o no e atualiza o valor de sua chave
    minHeap->array[i]->key = key;

    // Loop com complexidade O(logN)
    while (i && minHeap->array[i]->key < minHeap->array[(i - 1) / 2]->key) {
        // trocar no com seu no pai
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

        // mover o indice do no pai
        i = (i - 1) / 2;
    }
}

// verificar se o vertice v eh min heap ou nao
int isInMinHeap(struct MinHeap* minHeap, int v) {
    if (minHeap->pos[v] < minHeap->size) return 1;
    else return 0;
}

// imprimir mst (nos pais)
void printArr(int* pai, int n) {
 	FILE* a=fopen("respostasP.txt","w+");
    int i;
    for (i = 1; i < n; ++i){
	
        printf("Vertice: %d => Pai: %d\n",i,pai[i]);
        fprintf(a,"Vertice: %d => Pai: %d\n",i,pai[i]);
	}
	fclose(a);
}

/* ./ FUNCOES HEAPIFY */

/* ------------ Algoritmo de PRIM ------------
* Parte de um vertice inicialmente na arvore, o algoritmo procura
* a aresta de menor peso que conecte um vertice da arvore a outro
* que ainda nao esteja na arvore. Esse vertice eh entao adicionado
* na arvore e o processo se repete ate que todos os vertices
* facam parte da arvore ou quando nao se pode encontrar uma
* aresta que satisfaca essa condicao. */
void primMST(GRAFO* grafo) {
    int V = grafo->numeroVertices; // numero dos vertices do grafo
    int parent[V]; // vetor para guardar o resultado da arvore geradora minima
    int key[V]; // vetor de chaves usadas para pegar aresta de menor peso

    // inicializa min Heap com o tamanho de vertices
    struct MinHeap* minHeap = createMinHeap(V);

    // inicializa min heap sendo V total de vertices do grafo.
    // valor da chave de todos os vertices eh, inicialmente
    // infinito (INT_MAX) <limits.h> (exceto o primeiro vertice)
    int v;
    for (v = 0; v < V; ++v) {
        parent[v] = -1;
        key[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, key[v]);
        minHeap->pos[v] = v;
    }

    // setar chave do vertice da primeira posicao
    key[0] = 0;
    minHeap->array[0] = newMinHeapNode(0, key[0]);
    minHeap->pos[0] = 0;

    // inicializa tamanho da min heap com o numero de vertices do grafo
    minHeap->size = V;

    // loop enquanto min heap nao estiver vazio
    while (!isEmpty(minHeap)) {
        // encontrar o vertice com valor minimo de chave
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v; // guardar numero de vertice encontrado

        // andar em todos os vertices adjacentes de u (vertice extraido)
        // e atualizar os valores da chave
        ARESTA *pCrawl=grafo->vertices[u].arestas;
        //CELULA* pCrawl = grafo[u].adj.primeiro;
        while (pCrawl != NULL) {
            int v = pCrawl->verticeDestino;

            // se v ainda nao esta incluido na MST e o peso de u-v
            // eh menor que o valor da chave de v, entao atualiza seu valor
            // e o no pai de v
            if (isInMinHeap(minHeap, v) && pCrawl->peso < key[v]) {
                key[v] = pCrawl->peso;
                parent[v] = u;
                decreaseKey(minHeap, v, key[v]);
            }
            pCrawl = pCrawl->prox;
        }
    }

    printf("\n\t\t PRIM - Arvore geradora minima resultante \n\n");
    printArr(parent,V);
}



int main(){
	GRAFO * gr;
	gr=criarGrafo(150,22500);	
	lerinstancia(gr);	
	primMST(gr);
	//imprimirGrafo(gr);

	return 0;
}
