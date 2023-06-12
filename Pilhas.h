#ifndef PILHA_VETOR_H // Verifica se a constante PILHA_VETOR_H não foi definida
#define PILHA_VETOR_H // Define a constante PILHA_VETOR_H

#define TAM_MAX 5 // Define a constante TAM_MAX com valor 5

class Pilha{ // Define a classe Pilha
    int topo; // Atributo inteiro que representa o topo da pilha
    int *vetor; // Atributo ponteiro para inteiro que representa o vetor que armazena os elementos da pilha
public:
    Pilha(); // Construtor padrão da classe Pilha
    int get_topo(); // Método que retorna o elemento no topo da pilha
    bool vazia(); // Método que verifica se a pilha está vazia
    bool cheia(); // Método que verifica se a pilha está cheia
    int tamanho(); // Método que retorna o tamanho da pilha
    bool empilhar(int elemento); // Método que adiciona um elemento na pilha
    bool desempilhar(); // Método que remove o elemento no topo da pilha
};

#endif // Fecha a verificação da constante PILHA_VETOR_H
