#include "Grafos.h"




// construtor padrão da classe Grafo
Grafo::Grafo(){
    n_vertices = 0;
}

// método para ler um grafo a partir de um arquivo de texto
void Grafo::ler_grafo(string txt){
    ifstream arquivo(txt); // abre o arquivo
    arquivo >> n_vertices; // lê o número de vértices
    pai = new int[n_vertices];
    matriz_adj = new int*[n_vertices]; // aloca a matriz de adjacência com n_vertices linhas
    for(int i = 0; i < n_vertices; i++){
        matriz_adj[i] = new int[n_vertices]; // aloca n_vertices colunas para cada linha
        for(int j = 0; j < n_vertices; j++){
            arquivo >> matriz_adj[i][j]; // lê cada elemento da matriz de adjacência
        }
    }

    lista_adj.resize(n_vertices); // redimensiona o vetor lista_adj para n_vertices
    for(int i = 0; i < n_vertices; i++){
        for(int j = 0; j < n_vertices; j++){
            if(matriz_adj[i][j] == 1){ // se há uma aresta entre os vértices i e j
                lista_adj[i].push_back(j); // adiciona j na lista de adjacência de i
            }
        }
    }
    vetordebug = new string[n_vertices]; // vetor para fazer debug do código
    vetordebug[0] = "A";
    vetordebug[1] = "B";
    vetordebug[2] = "C";
    vetordebug[3] = "D";
    vetordebug[4] = "E";
    vetordebug[5] = "F";
}

// método para imprimir a lista de adjacência do grafo
void Grafo::imprimir_lista_adj(){
    if(n_vertices <= 0){ // se não há vértices no grafo
        cout << "O grafo nao existe" << endl;
    }
    for(int i = 0; i < n_vertices; i++){
        cout << endl << "Vizinhos do vertice " << vetordebug[i] << ":"; // imprime o nome do vértice
        for(int j = 0; j < lista_adj[i].size(); j++){
            if(j+1 == lista_adj[i].size()){ // se é o último vizinho do vértice
                cout << " " << vetordebug[lista_adj[i][j]] << "."; // imprime o nome do vértice com ponto
            }else{
                cout << " " << vetordebug[lista_adj[i][j]] << ", "; // imprime o nome do vértice com vírgula
            }    
        }
    }
}

// método para retornar o número de vértices do grafo
int Grafo::get_n_vertices(){
    return n_vertices;
}

// BFS - Busca em largura
void Grafo::bfs(int v){
    // Checa se o vértice v é válido
    if(v >= n_vertices || v < 0){
        cout << "Vertice nao valido" << endl;
        return;
    }
    
    // Inicializa o vetor de visitados
    bool *visitados = new bool[n_vertices];
    
    // Inicializa a fila
    queue<int> fila;

    // Inicializa o vetor de pais
    for(int i = 0; i < n_vertices; i++){
        visitados[i] = false;
        pai[i] = -1;
    }

    // Visita o vértice inicial e o adiciona à fila
    visitados[v] = true;
    fila.push(v);

    // Realiza a busca em largura
    while(!fila.empty()){
        // Pega o próximo vértice da fila
        int verticeatual = fila.front();
        fila.pop();
        cout << "Vertice Atual: " << vetordebug[verticeatual] << endl;
        // Visita todos os vértices adjacentes do vértice atual
        for(int i = 0; i < lista_adj[verticeatual].size(); i++){
            int verticeadj = lista_adj[verticeatual][i];
            if(!visitados[verticeadj]){
                cout << "Vertice ADJ: " << vetordebug[verticeadj] << endl;
                // Se o vértice adjacente não foi visitado, visita e adiciona à fila
                visitados[verticeadj] = true;
                fila.push(verticeadj);
                pai[verticeadj] = verticeatual; // Define o pai do vértice adjacente
            }
        }
    }

    // Libera a memória alocada
    delete[] visitados;
}

// DFS - Busca em profundidade
void Grafo::dfs(int v){
    // Checa se o vértice v é válido
    if(v >= n_vertices || v < 0){
        cout << "Vertice Invalido" << endl;
        return;
    }
    
    // Inicializa o vetor de visitados e o vetor de pais
    bool *visitados = new bool[n_vertices];
    pai = new int[n_vertices];
    
    // Inicializa a pilha
    stack<int> pilha;
    pilha.push(v);

    // Inicializa o vetor de pais
    for(int i = 0; i < n_vertices; i++){
        visitados[i] = false;
        pai[i] = -1;
    }

    // Realiza a busca em profundidade
    while(!pilha.empty()){
        // Pega o próximo vértice da pilha
        int verticeatual = pilha.top();
        pilha.pop();

        // Se o vértice ainda não foi visitado, visita e adiciona todos os vértices adjacentes à pilha
        if(!visitados[verticeatual]){
            visitados[verticeatual] = true;
            cout << "Vertice Atual: " << vetordebug[verticeatual] << endl;

            for(int i = 0; i < lista_adj[verticeatual].size(); i++){
                int verticeadj = lista_adj[verticeatual][i];
                if(!visitados[verticeadj]){
                    cout << "Vertice ADJ: " << vetordebug[verticeadj] << endl;
                    pilha.push(verticeadj);
                    pai[verticeadj] = verticeatual; // Define o pai do vértice adjacente
                }
            }
        }
    }
}


