#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>



//invariantes de laço (estudar)


void imprimir(int A[], int n, int tempo);
void delay(int number_of_seconds);
int* criarArranjo(int n);
int* criarArranjoOrdemCrescente(int n);
int* crirarArranjoOrdemDescrescente(int n);
void troca(int *x, int *y);
void insertionSort(int A[], int n);
void selectionSort(int A[], int n);
void bubbleSort(int A[], int n); 



int main(){
	clock_t t, t2, t3;
	//int n = 30000;
	
//		int* A = criarArranjo(n);
	//t = clock() - t;
	//printf("\n\nTempo de execucao: %1f\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	
	
	//int A[] = {9, 7, 2, 5, 3, 1};
	
	int n = 100000;
	
	int* A = criarArranjo(n);
	t = clock();
	selectionSort(A, n);
	t = clock() - t;

	double tempo1 = ( (double)t)/(CLOCKS_PER_SEC/1000);
	
	int* B = criarArranjo(n);
	t2 = clock();
	bubbleSort(B, n);
	t2 = clock() - t2;

	double tempo2 = ( (double)t2)/(CLOCKS_PER_SEC/1000);
	
	int* C = criarArranjo(n);
	t3 = clock();
	insertionSort(C, n);
	t3 = clock() - t3;

	double tempo3 = ( (double)t3)/(CLOCKS_PER_SEC/1000);
	
	
	printf("\nTempo Selection Sort: %1f\nTempo Bubble Sort: %1f\nTempo Insertion Sort: %1f", tempo1, tempo2, tempo3);
	
	bubbleSort(A, n);
	
	return 0;
}

void imprimir(int A[], int n, int tempo){
	for(int k=0; k < n; k++){
		printf("%d ", A[k]);
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

void selectionSort(int A[], int n){
	
	for(int i = 0; i < n - 1; i++){
		int indiceMenor = i;
		
		for(int j = i + 1; j < n; j++){
			if (A[indiceMenor] > A[j]) indiceMenor = j;
		}
		
		if(indiceMenor != i) troca(&A[indiceMenor], &A[i]);
	}
	
}

void bubbleSort(int A[], int n){
	
	for(int i = 0; i < n; i++){
		for(int j = 1; j < n - i; j++){
			if(A[j - 1] > A[j]) troca(&A[j - 1], &A[j]);
		}
	}
	
}

