#ifndef LISTA_ENC_H
#define LISTA_ENC_H

class no{
    int dado;
    no *prox;
public:
    no(int d);
    int get_dado();
    no* get_prox();
    void set_dado(int d);
    void set_prox(no *p);
};

class lista{
    int tamanho;
    no *head;
public:
    lista();
    bool vazia();
    int get_tamanho();
    int elemento(int pos);
    int pos(int dado);
    bool inserir(int pos, int dado);
    bool inserir_inicio(int dado);
    bool inserir_fim(int dado);
    bool inserir_meio(int pos, int dado);
    bool remover(int pos);
    bool remove_inicio();
    bool remover_lista(int pos);
};



#endif