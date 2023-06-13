//Dupla: Natanael de Lima Costa Neto e Kevin Leandro Gomes
//Matrículas: 20190038391 e 20190098694

#include "ordenacao.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

// IMPLEMENTANDO AS FUNÇÕES DE ORDENAÇÃO E A FUNÇÃO PRA CONTROLE DE TEMPO.



void Start(){

    
    t = clock();

}


double End(){


    t = clock() - t;

    return ((double)t)/((CLOCKS_PER_SEC));
}

// Bubble Sort

int* bubbleSort(int *vetor, int tamanho){
    // Variáveis auxiliares.
    int i, j, aux;
    // Ordenando o vetor.
    for(i = 0; i < tamanho - 1 ; i++){
        // Percorrendo o vetor.
        for(j = 0; j < tamanho - 1; j++){
            // Verificando se o elemento atual é maior que o próximo.
            if(vetor[j] > vetor[j + 1]){
                // Trocando os elementos de posição.
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }


    return vetor;
}

// Selection Sort

int* selectionSort(int *vetor, int tamanho){
    // Variáveis auxiliares.
    int i, j, aux, menor;
    // Ordenando o vetor.
    for(i = 0; i < tamanho - 1; i++){
        // Definindo o menor elemento como o primeiro.
        menor = i;
        // Percorrendo o vetor.
        for(j = i + 1; j < tamanho; j++){
            // Verificando se o elemento atual é menor que o menor.
            if(vetor[j] < vetor[menor]){
                // Definindo o menor como o elemento atual.
                menor = j;
            }
        }
        // Trocando os elementos de posição.
        aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }
    return vetor;
}

// Insertion Sort

int* insertionSort(int *vetor, int tamanho){
    // Variáveis auxiliares.
    int i, j, atual;
    // Ordenando o vetor.
    for(i = 1; i < tamanho; i++){
        // Definindo o elemento atual como o atual.
        atual = vetor[i];
        // Definindo o elemento anterior como o anterior ao atual.
        j = i - 1;
        // Percorrendo o vetor.
        while(j >= 0 && vetor[j] > atual){
            // Trocando os elementos de posição.
            vetor[j + 1] = vetor[j];
            j--;
        }
        // Definindo o elemento atual como o atual que guardei.
        vetor[j + 1] = atual;
    }
    return vetor;
}

// Merge Sort

int* mergeSort(int *vetor, int tamanho){
    // Variáveis auxiliares.
    int i, j, k, metade, *vetorAuxiliar;
    // Verificando se o vetor tem mais de um elemento.
    if(tamanho > 1){
        // Definindo a metade do vetor.
        metade = tamanho / 2;
        // Alocando memória para o vetor auxiliar.
        vetorAuxiliar = (int*)malloc(metade * sizeof(int));
        // Percorrendo o vetor.
        for(i = 0; i < metade; i++){
            // Definindo o vetor auxiliar como o vetor.
            vetorAuxiliar[i] = vetor[i];
        }
        // Chamando a função recursivamente.
        mergeSort(vetorAuxiliar, metade);
        // Percorrendo o vetor.
        for(i = metade, j = 0, k = 0; j < metade && k < tamanho; i++){
            // Verificando se o elemento do vetor auxiliar é menor que o do vetor.
            if(vetorAuxiliar[j] < vetor[i]){
                // Definindo o vetor como o vetor auxiliar.
                vetor[k] = vetorAuxiliar[j];
                j++;
            }
            // Verificando se o elemento do vetor auxiliar é maior que o do vetor.
            else{
                // Definindo o vetor como o vetor auxiliar.
                vetor[k] = vetor[i];
                k++;
            }
        }
        // Verificando se o vetor auxiliar ainda tem elementos.
        while(j < metade){
            // Definindo o vetor como o vetor auxiliar.
            vetor[k] = vetorAuxiliar[j];
            j++;
            k++;
        }
        // Liberando a memória do vetor auxiliar.
        free(vetorAuxiliar);
    }
    return vetor;
}

// Quick Sort

int* quickSort(int *vetor, int tamanho){
    // Variáveis auxiliares.
    int i, j, pivo, aux;
    // Verificando se o vetor tem mais de um elemento.
    if(tamanho > 1){
        // Definindo o pivo como o primeiro elemento.
        pivo = vetor[0];
        // Definindo o i como o segundo elemento.
        i = 1;
        // Definindo o j como o último elemento.
        j = tamanho - 1;
        // Percorrendo o vetor.
        while(i <= j){
            // Verificando se o elemento atual é menor que o pivo.
            while(i < tamanho && vetor[i] <= pivo){
                i++;
            }
            // Verificando se o elemento atual é maior que o pivo.
            while(j > 0 && vetor[j] > pivo){
                j--;
            }
            // Verificando se o i é menor que o j.
            if(i <= j){
                // Trocando os elementos de posição.
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
                i++;
                j--;
            }
        }
        // Trocando os elementos de posição.
        vetor[0] = vetor[j];
        vetor[j] = pivo;
        // Chamando a função recursivamente.
        quickSort(vetor, j);
        quickSort(vetor + i, tamanho - i);
    }
    return vetor;
}


