#include "Lista_enc.h"
#include <iostream>

lista::lista(){
    head = NULL;
    tamanho = 0;
}
bool lista::vazia(){
    if(tamanho <= 0){
        return true;
    }
    return false;
}
int lista::get_tamanho(){
    return tamanho;
}

bool lista::inserir_inicio(int dado){
    no *novono = new no(dado);
    novono->set_prox(head);
    head = novono;

    tamanho++;

    return true;
}
bool lista::inserir_meio(int pos, int dado){
    int cont = 1;
    no *novono = new no(dado);
    no *aux = head;
    while(cont < pos-1 && aux != NULL){
        aux = aux->get_prox();
        cont++;
    }
    if(aux == NULL){
        return false;
    }
    novono->set_prox(aux->get_prox());
    aux->set_prox(novono);
    tamanho++;

    return true;

}
bool lista::inserir_fim(int dado){
    no *novono = new no(dado);

    no *aux = head;

    while(aux->get_prox() != NULL){
        aux = aux->get_prox();
    }

    aux->set_prox(novono);
    tamanho++;

    return true;


}

bool lista::inserir(int pos, int dado){
    if(vazia() && pos != 1){
        return false;
    }
    if(pos == 1){
        inserir_inicio(dado);
    }
    else if(pos == tamanho+1){
        inserir_fim(dado);
    }
    else{
        inserir_meio(pos, dado);
    }


}

int lista::elemento(int pos){
    no *aux = head;
    int cont = 1;
    if(vazia()){
        return -1;
    }
    if(pos < 1 || pos > tamanho){
        return -1;
    }

    while(cont < pos){
        aux = aux->get_prox();
        cont++;
    }
    return aux->get_dado();
}

int lista::pos(int dado){
    no *aux = head;
    int cont = 1;
    if(vazia()){
        return -1;
    }

    while(aux != NULL){
        if(aux->get_dado() == dado){
            return cont;
        }
        aux = aux->get_prox();
        cont++;
    }


    return -1;
}

bool lista::remover(int pos){
    if(vazia()){
        return false;
    }
    if(pos == 1){
        return remove_inicio();
    }
    else{
        return remover_lista(pos);
    }
}

bool lista::remove_inicio(){
    no *aux = head;
    head = aux->get_prox();
    delete(aux);
    tamanho--;
    return true;
}

bool lista::remover_lista(int pos){
    no *atual = NULL;
    no *antecessor = NULL;
    int cont = 1;
    
    atual = head;

    while(cont < pos && atual != NULL){
        antecessor = atual;
        atual = atual->get_prox();
        cont++;
    }
    if(atual == NULL){
        return false;
    }
    antecessor->set_prox(atual->get_prox());
    tamanho--;
    delete(atual);
    return true;
}



no::no(int d){
    prox = NULL;
    dado = d;
}
int no::get_dado(){
    return dado;
}
no* no::get_prox(){
    return prox;
}
void no::set_dado(int d){
    dado = d;
}
void no::set_prox(no *p){
    prox = p;
}

