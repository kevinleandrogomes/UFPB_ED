// Inclui a biblioteca iostream para uso de entrada/saída padrão e o arquivo header "pilhadinamica.h"
#include <iostream>
#include "Pilhas_Dinamicas.h"

// Implementa a classe No com o construtor que recebe um inteiro como parâmetro, inicializa o próximo elemento com NULL e guarda o dado.
No::No(int d){
prox = NULL;
dado = d;
}

// Métodos get para obter o dado e o próximo elemento
int No::get_dado(){
return dado;
}
No* No::get_prox(){
return prox;
}

// Método set para modificar o próximo elemento e o dado
void No::set_prox(No *p){
prox = p;
}
void No::set_dado(int elemento){
dado = elemento;
}

// Implementa a classe Pilhadinamica com o construtor que inicializa a variável topo com NULL e o tamanho com 0
Pilhadinamica::Pilhadinamica(){
topo = NULL;
tamanho = 0;
}

// Método get para obter o tamanho da pilha
int Pilhadinamica::get_tamanho(){
return tamanho;
}

// Método booleano que verifica se a pilha está vazia
bool Pilhadinamica::vazia(){
if(tamanho == 0){
return true;
}
return false;
}

// Método get para obter o elemento no topo da pilha
int Pilhadinamica::get_topo(){
// Verifica se a pilha está vazia, retorna -1 se estiver
if(topo == NULL){
return -1;
}
// Retorna o dado do elemento no topo da pilha
return topo->get_dado();
}

// Método booleano que adiciona um elemento no topo da pilha, recebendo um inteiro como parâmetro
bool Pilhadinamica::empilhar(int elemento){
// Verifica se a pilha está vazia
if(vazia()){
// Cria um novo nó com o elemento a ser adicionado
No *novono = new No(elemento);
// O topo da pilha aponta para esse novo nó
topo = novono;
}
// Se a pilha não está vazia
No *novono = new No(elemento); // Cria um novo nó com o elemento a ser adicionado
novono->set_prox(topo); // Faz com que o próximo elemento seja o que estava no topo
topo = novono; // O topo da pilha agora aponta para esse novo nó
tamanho++; // Incrementa o tamanho da pilha
return true; // Retorna verdadeiro
}

// Método booleano que remove o elemento no topo da pilha
bool Pilhadinamica::desempilhar(){
// Verifica se a pilha está vazia
if(vazia()){
return false; // Retorna falso, indicando que não foi possível remover
}
No *aux = topo; // Cria um ponteiro auxiliar que aponta para o elemento no topo da pilha
topo = topo->get_prox(); // Faz com que o topo da pilha agora aponte para o próximo elemento
delete(aux); // Deleta o elemento que estava no topo
tamanho--; // Decrementa o tamanho da pilha
return true; // Retorna verdadeiro
}