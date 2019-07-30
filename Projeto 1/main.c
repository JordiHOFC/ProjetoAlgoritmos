#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"insertionsort.h"
#include"merge.h"
#include"selectionsort.h"
#include"shellsort.h"
#include"quicksort.h"
#include"heapsort.h"

void escrevevetor(int *vet, int tamanho){
	int i=0;
	printf("\n");
	for(i=0;i<tamanho;i++){
		printf("%d\t", vet[i]);
	}
}

int  leituraInstacia(FILE * arq, int * vetor){
	int i, menu, op,tamanho;
	printf("\nPara ler as instancias selecione o tamanho:  \n 1 - 10 \n 2 - 1000 \n 3- 10000 \n 4-100000 \n 5 - 1000000");
	scanf("%d",&menu);
	switch(menu){
		case 1:
			tamanho=10;
			printf("\nselecione a ordem: \n1-crescente \n2-descrecent \n3-randomico");
			scanf("%d",&op);
			if(op==1){
				
				arq=fopen("instancias10c.txt","r");//le o arquivo
				fflush(stdin);
				for(i=0;i<tamanho;i++){			
					fscanf(arq,"%d\t",&vetor[i]);
					}
				fclose(arq);
			
			}
			if(op==2){
				arq=fopen("instancias10d.txt","r");//le o arquivo
				fflush(stdin);
				for(i=0;i<tamanho;i++){			
					fscanf(arq,"%d\t",&vetor[i]);
					}
				fclose(arq);
			
			}	
			
			if(op==3){
				arq=fopen("instancias10a.txt","r");//le o arquivo
				fflush(stdin);
				for(i=0;i<tamanho;i++){			
					fscanf(arq,"%d\t",&vetor[i]);
					}
				fclose(arq);
			
			}
			return tamanho;
		case 2:
			tamanho=1000;
			printf("\nselecione a ordem: \n1-crescente \n2-descrecent \n3-randomico");
			scanf("%d",&op);
			if(op==1){
				
				arq=fopen("instancias1000c.txt","r");//le o arquivo
				fflush(stdin);
				for(i=0;i<tamanho;i++){			
					fscanf(arq,"%d\t",&vetor[i]);
					}
				fclose(arq);
			
			}
			if(op==2){
				arq=fopen("instancias1000d.txt","r");//le o arquivo
				fflush(stdin);
				for(i=0;i<tamanho;i++){			
					fscanf(arq,"%d\t",&vetor[i]);
					}
				fclose(arq);
			
				
			}
			if(op==3){
				arq=fopen("instancias1000a.txt","r");//le o arquivo
				fflush(stdin);
				for(i=0;i<tamanho;i++){			
					fscanf(arq,"%d\t",&vetor[i]);
					}
				fclose(arq);
			
			}
			
			return tamanho;
		case 3:
			tamanho=10000;
			printf("\nselecione a ordem: \n1-crescente \n2-descrecent \n3-randomico");
			scanf("%d",&op);
			if(op==1){
				
				arq=fopen("instancias10000c.txt","r");//le o arquivo
				fflush(stdin);
				for(i=0;i<tamanho;i++){			
					fscanf(arq,"%d\t",&vetor[i]);
					}
				fclose(arq);
			
			}
			if(op==2){
				arq=fopen("instancias10000d.txt","r");//le o arquivo
				fflush(stdin);
				for(i=0;i<tamanho;i++){			
					fscanf(arq,"%d\t",&vetor[i]);
					}
				fclose(arq);
			
			}	
			
			if(op==3){
				arq=fopen("instancias10000a.txt","r");//le o arquivo
				fflush(stdin);
				for(i=0;i<tamanho;i++){			
					fscanf(arq,"%d\t",&vetor[i]);
					}
				fclose(arq);
			
			}
			
			return tamanho;
		case 4:
			tamanho=100000;
			printf("\nselecione a ordem: \n1-crescente \n2-descrecent \n3-randomico");
			scanf("%d",&op);
			if(op==1){
				
				arq=fopen("instancias100000c.txt","r");//le o arquivo
				fflush(stdin);
				for(i=0;i<tamanho;i++){			
					fscanf(arq,"%d\t",&vetor[i]);
					}
				fclose(arq);
			
			}
			if(op==2){
				arq=fopen("instancias100000d.txt","r");//le o arquivo
				fflush(stdin);
				for(i=0;i<tamanho;i++){			
					fscanf(arq,"%d\t",&vetor[i]);
					}
				fclose(arq);
			
			}	
			
			if(op==3){
				arq=fopen("instancias100000a.txt","r");//le o arquivo
				fflush(stdin);
				for(i=0;i<tamanho;i++){			
					fscanf(arq,"%d\t",&vetor[i]);
					}
				fclose(arq);
			
			}
			
			return tamanho;
		case 5:
			tamanho=1000000;
			printf("\nselecione a ordem: \n1-crescente \n2-descrecent \n3-randomico");
			scanf("%d",&op);
			if(op==1){
				
				arq=fopen("instancias1000000c.txt","r");//le o arquivo
				fflush(stdin);
				for(i=0;i<tamanho;i++){			
					fscanf(arq,"%d\t",&vetor[i]);
					}
				fclose(arq);
			
			}
			if(op==2){
				arq=fopen("instancias1000000d.txt","r");//le o arquivo
				fflush(stdin);
				for(i=0;i<tamanho;i++){			
					fscanf(arq,"%d\t",&vetor[i]);
					}
				fclose(arq);
			
			}	
			
			if(op==3){
				arq=fopen("instancias1000000a.txt","r");//le o arquivo
				fflush(stdin);
				for(i=0;i<tamanho;i++){			
					fscanf(arq,"%d\t",&vetor[i]);
					}
				fclose(arq);
			
			}
			
			return tamanho;
	
}
}

void createinstancia(){
	int *vetordenumero;	
	FILE *instancias;
	int i=0, n;
	int menu, op,tamanho;

	
	printf("\nPara criar as instancias selecione o tamanho e a ordem:  \n 1 - 10 \n 2 - 1000 \n 3- 10000 \n 4-100000 \n 5 - 1000000");
	scanf("%d",&menu);
	switch(menu){
		case 1:
			tamanho=10;
				
			vetordenumero=(int*)malloc(tamanho*sizeof(int)); //cria um vetor dinamincamento com a quantidade de elementos
							
			printf("escolha a ordem\n\n 1- crescente \n 2 - decrescente \n 3- aleatorio");
			scanf("%d",&op);
			if(op==1){
				instancias=fopen("instancias10c.txt","w+");//criar o arquivo
				for(i=0;i<tamanho;i++){
					fprintf(instancias,"%d\t",i);	
				}
				fclose(instancias);
				
			
			
			}
			
			if(op==2){
				instancias=fopen("instancias10d.txt","w+");//criar o arquivo
				for(i=tamanho;i>0;i--){
					fprintf(instancias,"%d\t",i);	
				}
				fclose(instancias);		
			}
			if (op==3){
				instancias=fopen("instancias10a.txt","w+");//criar o arquivo
				for(i=0;i<tamanho;i++){
					n=rand();
					fprintf(instancias,"%d\t",n);	
				}
				fclose(instancias);
			}
			break;
		case 2:
			tamanho=1000;
	
			
			
			vetordenumero=(int*)malloc(tamanho*sizeof(int)); //cria um vetor dinamincamento com a quantidade de elementos
		
				
	
			printf("escolha a ordem\n\n 1- crescente \n 2 - decrescente \n 3- aleatorio");
	
			scanf("%d",&op);
		
			if(op==1){
				instancias=fopen("instancias1000c.txt","w+");//criar o arquivo
				for(i=0;i<tamanho;i++){
					fprintf(instancias,"%d\t",i);	
				}
				fclose(instancias);
				
			
			
			}
			
			if(op==2){
				instancias=fopen("instancias1000d.txt","w+");//criar o arquivo
				for(i=tamanho;i>0;i--){
					fprintf(instancias,"%d\t",i);	
				}
				fclose(instancias);		
			}
			if (op==3){
				instancias=fopen("instancias1000a.txt","w+");//criar o arquivo
				for(i=0;i<tamanho;i++){
					n=rand();
					fprintf(instancias,"%d\t",n);	
				}
				fclose(instancias);
			}
			break;	
		case 3:
			tamanho=10000;
	
			int *vetordenumero;
			
			vetordenumero=(int*)malloc(tamanho*sizeof(int)); //cria um vetor dinamincamento com a quantidade de elementos
			int i=0, n;
				
	
			printf("escolha a ordem\n\n 1- crescente \n 2 - decrescente \n 3- aleatorio");
	
			scanf("%d",&op);
		
			if(op==1){
				instancias=fopen("instancias10000c.txt","w+");//criar o arquivo
				for(i=0;i<tamanho;i++){
					fprintf(instancias,"%d\t",i);	
				}
				fclose(instancias);
				
			
			
			}
			
			if(op==2){
				instancias=fopen("instancias10000d.txt","w+");//criar o arquivo
				for(i=tamanho;i>0;i--){
					fprintf(instancias,"%d\t",i);	
				}
				fclose(instancias);		
			}
			if (op==3){
				instancias=fopen("instancias10000a.txt","w+");//criar o arquivo
				for(i=0;i<tamanho;i++){
					n=rand();
					fprintf(instancias,"%d\t",n);	
				}
				fclose(instancias);
			}
			break;
		case 4:
			tamanho=100000;
	
			
			vetordenumero=(int*)malloc(tamanho*sizeof(int)); //cria um vetor dinamincamento com a quantidade de elementos
					
	
			printf("escolha a ordem\n\n 1- crescente \n 2 - decrescente \n 3- aleatorio");
	
			scanf("%d",&op);
		
			if(op==1){
				instancias=fopen("instancias100000c.txt","w+");//criar o arquivo
				for(i=0;i<tamanho;i++){
					fprintf(instancias,"%d\t",i);	
				}
				fclose(instancias);
				
			
			
			}
			
			if(op==2){
				instancias=fopen("instancias100000d.txt","w+");//criar o arquivo
				for(i=tamanho;i>0;i--){
					fprintf(instancias,"%d\t",i);	
				}
				fclose(instancias);		
			}
			if (op==3){
				instancias=fopen("instancias100000a.txt","w+");//criar o arquivo
				for(i=0;i<tamanho;i++){
					n=rand();
					fprintf(instancias,"%d\t",n);	
				}
				fclose(instancias);
			}
			break;		
		case 5:
				tamanho=1000000;
	
			
			
			vetordenumero=(int*)malloc(tamanho*sizeof(int)); //cria um vetor dinamincamento com a quantidade de elementos
			
				
	
			printf("escolha a ordem\n\n 1- crescente \n 2 - decrescente \n 3- aleatorio");
	
			scanf("%d",&op);
		
			if(op==1){
				instancias=fopen("instancias1000000c.txt","w+");//criar o arquivo
				for(i=0;i<tamanho;i++){
					fprintf(instancias,"%d\t",i);	
				}
				fclose(instancias);
				
			
			
			}
			
			if(op==2){
				instancias=fopen("instancias1000000d.txt","w+");//criar o arquivo
				for(i=tamanho;i>0;i--){
					fprintf(instancias,"%d\t",i);	
				}
				fclose(instancias);		
			}
			if (op==3){
				instancias=fopen("instancias1000000a.txt","w+");//criar o arquivo
				for(i=0;i<tamanho;i++){
					n=rand();
					fprintf(instancias,"%d\t",n);	
				}
				fclose(instancias);
			}
			break;
		case 0:
			return;
		
	}

		
}

void leituradeInstacia(FILE * arq, int * vetor, int tamanho){
	int i;
	arq=fopen("instancias1000.txt","r");//le o arquivo
	fflush(stdin);
	for(i=0;i<tamanho;i++){

		fscanf(arq,"%d\t",&vetor[i]);

		}
	fclose(arq);	
	
}
void escolheMetodo(FILE * arq, int *vetor){
	int op, tamanho;
	float start,end,tempoGasto;
		printf("\n1- Selection Sort \n2- Insertion Sort \n3- Shell Sort \n4- Merge Sort \n5- Quick Sort \n6- Heap Sort");
		scanf("%d",&op);
		switch(op){
			
			case 1:				
				tamanho=leituraInstacia(arq,vetor);
				escrevevetor(vetor,tamanho);
				start=clock();
				selection_sort(vetor,tamanho);
				end = clock();
				escrevevetor(vetor,tamanho);
				tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
				printf("\nTempo gasto =%f  ",tempoGasto);
				break;
			case 2:
				tamanho=leituraInstacia(arq,vetor);
				escrevevetor(vetor,tamanho);
				start=clock();
				insertionSort(vetor,tamanho);
				end = clock();
				escrevevetor(vetor,tamanho);
				tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
				printf("\nTempo gasto =%f  ",tempoGasto);
				break;
			case 3:	
				tamanho=leituraInstacia(arq,vetor);
				escrevevetor(vetor,tamanho);
				start=clock();
				shellSort(vetor,tamanho);
				end = clock();
				escrevevetor(vetor,tamanho);
				tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
				printf("\nTempo gasto =%f  ",tempoGasto);
				break;
			case 4:	
				tamanho=leituraInstacia(arq,vetor);
				escrevevetor(vetor,tamanho);
				start=clock();
				mergeSort(vetor,0,tamanho);
				end = clock();
				escrevevetor(vetor,tamanho);
				tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
				printf("\nTempo gasto =%f  ",tempoGasto);
				break;
			case 5:	
				tamanho=leituraInstacia(arq,vetor);
				start=clock();
				escrevevetor(vetor,tamanho);
				quick_sort(vetor,0,tamanho);
				end = clock();
				escrevevetor(vetor,tamanho);
				tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
				printf("\nTempo gasto =%f  ",tempoGasto);
				break;
			case 6:	
				tamanho=leituraInstacia(arq,vetor);
				escrevevetor(vetor,tamanho);
				start=clock();
				heapsort(vetor,tamanho);
				end = clock();
				printf("a");
				escrevevetor(vetor,tamanho);
				tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
				printf("\nTempo gasto =%f  ",tempoGasto);
				break;	
				
		}
}
void relatorio(int *vetor, int tamanho){
	FILE * relatorio;
	float tempoGasto,start,end;
	relatorio=fopen("Relatorio1.txt","a+");
	//fprintf(relatorio,"\n",NULL);
//	rewind(relatorio);
	//fseek(relatorio,2*sizeof(double),2);
	
	start=clock();
	selection_sort(vetor,tamanho);
	end = clock();
	tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
	fprintf(relatorio,"\n Tempo gasto por Selection Sort %f  quantidade de instancias %d",tempoGasto,tamanho);
	//fseek(relatorio,10*sizeof(double),2);
	
	start=clock();
	insertionSort(vetor,tamanho);
	end = clock();
	tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
	fprintf(relatorio,"\n Tempo gasto por Insertion Sort %f  quantidade de instancias %d ",tempoGasto,tamanho);
	//fseek(relatorio,2*sizeof(double),2);
	
	start=clock();
	mergeSort(vetor,0,tamanho);
	end = clock();
	tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
	fprintf(relatorio,"\n Tempo gasto por Merge Sort %f  quantidade de instancias %d",tempoGasto,tamanho);
	//fseek(relatorio,2*sizeof(double),2);
	
	start=clock();
	shellSort(vetor,tamanho);
	end = clock();
	tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
	fprintf(relatorio,"\n Tempo gasto por Shell Sort %f  quantidade de instancias %d",tempoGasto,tamanho);
	//fseek(relatorio,2*sizeof(double),2);
	

	start=clock();
	quick_sort(vetor,0,tamanho);
	end = clock();
	tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
	fprintf(relatorio,"\n Tempo gasto por Quick Sort %f  quantidade de instancias %d",tempoGasto,tamanho);	
	//fseek(relatorio,2*sizeof(double),2);
	
	start=clock();
	heapsort(vetor,tamanho);
	end = clock();
	tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC);
	fprintf(relatorio,"\n Tempo gasto por Heap Sort %f  quantidade de instancias %d",tempoGasto,tamanho);
	//fseek(relatorio,2*sizeof(double),2);
	fclose(relatorio);	
	

}



int main(){
	int i,tamanho=10000000;
	int menu;
	FILE *arq;
	int *vetor=(int*)malloc(tamanho*sizeof(int));
	
	printf("\n\nMenu\n1-Criar instancias\n2-selecionar algoritmos \n3-GerarRelatorio\n0-sair");
	scanf("%d",&menu);

	switch(menu){
		case 1:
			createinstancia();
			break;
		case 2:
			escolheMetodo(arq,vetor);
			break;
		case 3:
			
			relatorio(vetor,leituraInstacia(arq,vetor));
			break;	
		case 0:
			return;
	}
	//createinstancia();

	return 0;
}
