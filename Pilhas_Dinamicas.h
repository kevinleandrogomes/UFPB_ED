// Diretivas de pré-processador para evitar múltiplas definições da classe
#ifndef PILHA_DINAMICA_H
#define PILHA_DINAMICA_H


// Definição da classe Nó, que será utilizada na implementação da pilha
class No{
    No *prox; // Ponteiro para o próximo nó na pilha
    int dado; // Dado armazenado no nó
public:
    No(int d); // Construtor que recebe um dado e inicializa o nó
    No* get_prox(); // Método para retornar o ponteiro para o próximo nó
    int get_dado(); // Método para retornar o dado armazenado no nó
    void set_dado(int elemento); // Método para alterar o dado armazenado no nó
    void set_prox(No *p); // Método para alterar o ponteiro para o próximo nó
};

// Definição da classe Pilhadinamica, que será a pilha implementada com lista encadeada
class Pilhadinamica{
    No *topo; // Ponteiro para o topo da pilha
    int tamanho; // Tamanho atual da pilha
public:
    Pilhadinamica(); // Construtor que inicializa a pilha vazia
    int get_tamanho(); // Método para retornar o tamanho atual da pilha
    bool vazia(); // Método para verificar se a pilha está vazia
    int get_topo(); // Método para retornar o elemento no topo da pilha
    bool empilhar(int elemento); // Método para inserir um elemento no topo da pilha
    bool desempilhar(); // Método para remover o elemento no topo da pilha
};


#endif
