#include <iostream>
#include "Lista_enc.h"

using namespace std;


int main(void){

    lista *l1 = new lista();

    cout << l1->get_tamanho() << endl;

    cout << l1->inserir(1, 5) << endl;
    cout << l1->inserir(2, 15) << endl;
    cout << l1->inserir(2, 25) << endl;
    cout << l1->get_tamanho() << endl;

    cout << l1->pos(15) << endl;

    cout << l1->remover_lista(2) << endl;

    cout << l1->get_tamanho() << endl;

    cout << l1->elemento(2) << endl;
    
    return 1;
}