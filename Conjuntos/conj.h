#ifndef CONJ_H
#define CONJ_H

#include <iostream>

using namespace std;

class conj{
    
    /* Classe auxiliar para guardar cada elem. do conj. */
    struct elo{
        int dado;
        elo * prox;
        elo():prox(NULL){};
        elo(int elem, elo *prox_elem=NULL):
        dado(elem),prox(prox_elem) {}
    };
    
    elo *prim;  /* ponteiro para primeiro elemento */
    
    /* Funções privadas usadas em construtores, destruidores
     e operador de atribuição. */
    void copia(const conj& cj2);
    void apaga();
    
public:
    conj():prim(NULL) {};
    
    /* Construtor de cópia */
    conj(const conj& cj2);
    
    ~conj();
    
    /* Operador de atribuição sobrecarregado */
    conj& operator=(const conj& cj2);
    
    bool vazio() const;
    bool insere(const int& valor);
    bool remove(const int& valor);
    bool pertence(const int& valor) const;
    conj operator+(const conj& cj2) const;  /* União */
    conj operator*(const conj& cj2) const;  /* Intersecção */
    conj operator-(const conj& cj2) const;  /* Diferenca */
    int tamanho() const;  /* número de elementos */
    void imprime() const;
};

#endif