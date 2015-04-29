#include <iostream>
#include <cstdlib>
#include "conj.h"

using namespace std;

int main(){
    
    conj c1, c2, c3;
    
    c1.insere(1);
    c1.insere(3);
    c1.insere(5);
    c1.insere(2);
    c1.insere(4);
    
    cout << "Imprimindo c1"<<endl;
    c1.imprime();
    
    c2.insere(4);
    c2.insere(5);
    c2.insere(7);
    c2.insere(6);
    c2.insere(8);
    c2.insere(9);
    
    cout << "Imprimindo c2"<<endl;
    c2.imprime();
    
    c2.remove(9);
    
    cout << "Imprimindo c2 apos remocao de 9"<<endl;
    c2.imprime();
    
    cout << "Imprimindo uniao"<<endl;
    c3 = c1 + c2;
    c3.imprime();
    
    c3 = c1 * c2;
    cout << "Imprimindo interseccao"<<endl;
    c3.imprime();
    
    c3 = c1 - c2;
    cout << "Imprimindo diferenca"<<endl;
    c3.imprime();
    
    system("PAUSE");
    return 1;
    
}