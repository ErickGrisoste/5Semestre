#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>



//invariantes de laço (estudar)


void imprimir(int A[], int n, int tempo);
void delay(int number_of_seconds);
int* criarArranjo(int n);
int* criarArranjoSemRepetir(int n);
int* criarArranjoOrdemCrescente(int n);
int* crirarArranjoOrdemDescrescente(int n);
void troca(int *x, int *y);
void insertionSort(int A[], int n);
void selectionSort(int A[], int n);
void bubbleSort(int A[], int n);
void mergeSort(int A[], int p, int r); //Divide
void merge(int A[], int p, int q, int r); //Conquista


int main(){
	clock_t t, t2, t3;
	
	/**
	int n = 100;
	
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
	
	bubbleSort(A, n); **/
	
	int* A = criarArranjoSemRepetir(10);
	imprimir(A, 10, 0);
	
	
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

int* criarArranjoSemRepetir(int n){
	int* arranjo = (int*)malloc(n * sizeof(int));
	if (arranjo == NULL){
		printf("Problema na alocacao de Memohria!\n");
		exit(1);
	}
	srand(time(NULL));
	//rand() % (n*2)
	for (int i = 0; i < n; i++){
		arranjo[i] = i + 1;
	}
	
	for (int i = 0; i < n; i++){
		troca(&arranjo[rand() % (n)], &arranjo[rand() % (n)]);
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

void mergeSort(int A[], int p, int r){
	if (p < r) {
		int q = (p + q) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q+1, r);
		merge(A, p, q, r);
	}
}

void merge(int A[], int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	
	int* L = (int*) malloc(n1*sizeof(int));
	int* R = (int*) malloc(n2*sizeof(int));
	
	for(int i = 0; i < n1; i++) L[i] = A[p+i-1];
	for(int i = 0; i < n2; i++) R[i] = A[q+i];
	
	int i = 0, j = 0;
	
	for(int k = p; k < r; k++){
		//se i > n1
		//se j > n2
		if(L[k] <= R[k]){
			A[k] = L[i];
			i++;
		} else{
			A[k] = R[i];
			j++;
		}
	}
	
}
