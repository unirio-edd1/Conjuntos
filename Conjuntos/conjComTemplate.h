/* 
 conj.h: Declaração de classe Gabarito para conjuntos de TIPO usando lista encadeada. TIPO deve ter definição para operadores de comparação <, > e ==
 */

#ifndef Conjuntos_conjComTemplate_h
#define Conjuntos_conjComTemplate_h

#include <iostream>
using namespace std;

template<class TIPO>
class conj{
    /* Classe auxiliar para guardar cada elem. do conj. */
    struct elo{
        TIPO dado;
        elo * prox;
        elo():prox(NULL){};
        elo(TIPO elem, elo *prox_elem = NULL):
        dado(elem),prox(prox_elem) {}
    };
    elo *prim;  /* ponteiro para primeiro elemento */
    /* Funções privadas usadas em construtores, destruidores e operador de atribuição. */
    void copia(const conj<TIPO>& cj2);
    void apaga();
    
public:
    conj():prim(NULL) {};
    /* Construtor de cópia */
    conj(const conj<TIPO>& cj2);
    ~conj();
    /* Operador de atribuição sobrecarregado */
    conj<TIPO>& operator=(const conj<TIPO>& cj2);
    bool vazio() const;
    bool insere(const TIPO& valor);
    bool remove(const TIPO& valor);
    bool pertence(const TIPO& valor) const;
    conj<TIPO> operator+(const conj<TIPO>& cj2) const; /* União */
    conj<TIPO> operator*(const conj<TIPO>& cj2) const; /* Intersecção */
    int tamanho() const;  /* número de elementos */
    void imprime() const;
};

#endif