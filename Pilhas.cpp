#include <iostream> // Inclui a biblioteca iostream para utilizar as operações de entrada e saída
#include "Pilhas.h" // Inclui o arquivo de cabeçalho "pilha.h"

Pilha::Pilha(){ // Implementação do construtor da classe Pilha
    topo = -1; // Inicializa o topo com valor -1, indicando que a pilha está vazia
    vetor = new int[TAM_MAX]; // Aloca o vetor com tamanho máximo TAM_MAX
}

int Pilha::get_topo(){ // Implementação do método que retorna o elemento no topo da pilha
    if(vazia()){ // Verifica se a pilha está vazia
        return -1; // Retorna -1 se a pilha estiver vazia
    }
    return vetor[topo]; // Retorna o elemento no topo da pilha
}

int Pilha::tamanho(){ // Implementação do método que retorna o tamanho da pilha
    return (topo+1); // Retorna a quantidade de elementos na pilha, que é igual ao valor do topo mais um
}

bool Pilha::vazia(){ // Implementação do método que verifica se a pilha está vazia
    if(topo <= -1){ // Verifica se o topo é menor ou igual a -1
        return true; // Retorna true se a pilha estiver vazia
    }
    return false; // Retorna false caso contrário
}

bool Pilha::cheia(){ // Implementação do método que verifica se a pilha está cheia
    if(topo == (TAM_MAX - 1 )){ // Verifica se o topo é igual ao tamanho máximo menos um
        return true; // Retorna true se a pilha estiver cheia
    }
    return false; // Retorna false caso contrário
}

bool Pilha::empilhar(int elemento){ // Implementação do método que adiciona um elemento na pilha
    if(cheia()){ // Verifica se a pilha está cheia
        return false; // Retorna false se a pilha estiver cheia
    }
    topo++; // Incrementa o topo
    vetor[topo] = elemento; // Adiciona o elemento no topo da pilha
    return true; // Retorna true se a operação foi bem sucedida
}

bool Pilha::desempilhar(){ // Implementação do método que remove o elemento no topo da pilha
    if(vazia()){ // Verifica se a pilha está vazia
        return false; // Retorna false se a pilha estiver vazia
    }
    topo--; // Decrementa o topo
    return true; // Retorna true se a operação foi bem sucedida
}
