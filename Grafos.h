#ifndef GRAFO_H
#define GRAFO_H

#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

class Grafo{
    int n_vertices; // número de vértices
    int **matriz_adj; // matriz de adjacência
    vector<vector<int>> lista_adj; // lista de adjacência
    int *pai; // vetor pros pais
    string *vetordebug; // Obs: To criando um vetor genérico com letras, pra simbolizar os vértices, pra não ficar só números e ficar melhor de debugar
public:
    Grafo(); // construtor
    void ler_grafo(string txt); // função para ler grafo a partir de um arquivo txt
    void imprimir_lista_adj(); // função para imprimir a lista de adjacência
    int get_n_vertices(); // função para obter o número de vértices
    void bfs(int v); // função de busca em largura
    void dfs(int v); // função de busca em profundidade
};

#endif
