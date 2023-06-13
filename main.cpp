//Dupla: Natanael de Lima Costa Neto e Kevin Leandro Gomes
//Matrículas: 20190038391 e 20190098694

#include <iostream>
#include "ordenacao.h"
#include <string>
#include <fstream>



// Usando o namespace std.
using namespace std;



int main(){
    
    ifstream arquivo("instancia1.txt");

    int tamanho = 0;
    string lendo;

    while(!arquivo.eof()){
        arquivo >> lendo;
        tamanho++;
    }
    arquivo.close();

    ifstream arquivo2("instancia1.txt");
    int *vetorDesordenado = new int[tamanho];
    for(int i = 0; i < tamanho; i++){
        arquivo2 >> vetorDesordenado[i];
    }
    arquivo2.close();
    // Criando um vetor de inteiros
    int *vetorOrdenado1 = new int[tamanho];
    int *vetorOrdenado2 = new int[tamanho];
    int *vetorOrdenado3 = new int[tamanho];
    int *vetorOrdenado4 = new int[tamanho];
    int *vetorOrdenado5 = new int[tamanho];


    cout << "VETOR DESORDENADO" << endl;   
    // Imprimindo o vetor Desordenado. 
    for(int i = 0; i < tamanho; i++){
        cout << vetorDesordenado[i] << " ";
    }
    cout << endl; 
    cout << "BUBBLE SORT" << endl; 

   // Ordenando o vetor com o Bubble Sort.
    Start();
    vetorOrdenado1 = bubbleSort(vetorDesordenado, tamanho);
    cout << "Tempo de execução: " << End() << " segundos" << endl;
   // Imprimindo o vetor ordenado. 
    for(int i = 0; i < tamanho; i++){
        cout << vetorOrdenado1[i] << " ";
    }


    cout << endl; 
    cout << "SELECTION SORT" << endl; 
    // Ordenando o vetor com o Selection Sort e marcando o tempo.
    Start();
    vetorOrdenado2 = selectionSort(vetorDesordenado, tamanho);
    cout << "Tempo de execução: " << End() << " segundos" << endl;

   // Imprimindo o vetor ordenado. 
    for(int i = 0; i < tamanho; i++){
        cout << vetorOrdenado2[i] << " ";
    }

    cout << endl; 
    cout << "INSERTION SORT" << endl; 
    // Ordenando o vetor com o Selection Sort.
    Start();
    vetorOrdenado3 = insertionSort(vetorDesordenado, tamanho);
    cout << "Tempo de execução: " << End() << " segundos" << endl;
   // Imprimindo o vetor ordenado. 
    for(int i = 0; i < tamanho; i++){
        cout << vetorOrdenado3[i] << " ";
    }

    cout << endl; 
    cout << "MERGE SORT" << endl; 
    // Ordenando o vetor com o Merge Sort.
    Start();
    vetorOrdenado4 = mergeSort(vetorDesordenado, tamanho);
    cout << "Tempo de execução: " << End() << " segundos" << endl;
   // Imprimindo o vetor ordenado. 
    for(int i = 0; i < tamanho; i++){
        cout << vetorOrdenado4[i] << " ";
    }

    cout << endl; 
    cout << "QUICK SORT" << endl; 
    // Ordenando o vetor com o Quick Sort.
    Start();
    vetorOrdenado5 = quickSort(vetorDesordenado, tamanho);
    cout << "Tempo de execução: " << End() << " segundos" << endl;
   // Imprimindo o vetor ordenado. 
    for(int i = 0; i < tamanho; i++){
        cout << vetorOrdenado5[i] << " ";
    }
    




    return 0;
}