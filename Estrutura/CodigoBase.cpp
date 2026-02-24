#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>



//invariantes de laço (estudar)


void imprimir(int A[], int n, int tempo);
void delay(int number_of_seconds);
int* criarArranjo(int n);
void troca(int *x, int *y);
void insertionSort(int A[], int n); 



int main(){
	//clock_t t;
	//int n = 30000;
//	t = clock();
//		int* A = criarArranjo(n);
	//t = clock() - t;
	//printf("\n\nTempo de execucao: %1f\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	
	
	int A[] = {9, 7, 2, 5, 3, 1};
	int n = sizeof(A) / sizeof(A[0]);
	
	printf("Antes da Ordenacao:\n");
	for(int i = 0; i < n; i++){
		printf("%d ", A[i]);
	}
	
	insertionSort(A, n);
	
	printf("\n\nDepois da Ordenacao:\n");
	for(int i = 0; i < n; i++){
		printf("%d ", A[i]);
	}
	
	
	
	return 0;
}

void imprimir(int A[], int n, int tempo){
	for(int k=0; k < n; k++){
		printf("%d", A[k]);
	}
	delay(tempo);
	printf("\n");
}

void delay(int number_of_seconds){
	int milli_seconds = 1000 * number_of_seconds;
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds);
}


int* criarArranjo(int n){
	int* arranjo = (int*)malloc(n * sizeof(int));
	if (arranjo == NULL){
		printf("Problema na alocacao de Memohria!\n");
		exit(1);
	}
	srand(time(NULL));
	for (int i = 0; i < n; i++){
		arranjo[i] = rand() % (n*2);
	}
	return arranjo;
}

void troca(int *x, int *y){
	int aux = *x;
	*x = *y;
	*y = aux;
}

void insertionSort(int A[], int n){
	
	for (int j = 1; j < n; j++){
		int chave = A[j];
		int i = j-1;
		
		while (i >= 0 && A[i] > chave){
			A[i + 1] = A[i];
			i = i - 1;
		}
		A[i + 1] = chave;
	}
	
}

