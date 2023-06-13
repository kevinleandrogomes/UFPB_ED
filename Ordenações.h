//Dupla: Natanael de Lima Costa Neto e Kevin Leandro Gomes
//Matrículas: 20190038391 e 20190098694

#ifndef ORDENACAO_H
#define ORDENACAO_H


#include <time.h>

// DEFININDO AS FUNÇÕES DE ORDENAÇÃO E TEMPO.
static clock_t t;

void Start();

double End();

int* bubbleSort(int *vetor, int tamanho);

int* selectionSort(int *vetor, int tamanho);

int* insertionSort(int *vetor, int tamanho);

int* mergeSort(int *vetor, int tamanho);

int* quickSort(int *vetor, int tamanho);





#endif