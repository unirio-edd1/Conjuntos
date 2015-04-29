//
//  conj.cpp
//  Conjuntos
//
//  Created by Diogo Martins on 4/29/15.
//  Copyright (c) 2015 Diogo Martins. All rights reserved.
//

#include "conj.h"

void conj::apaga(){
    for (elo *p = prim; p != NULL; p = prim){
        prim = prim->prox;
        delete p;
    }
}

conj::conj(const conj& cj2){
    copia(cj2);
}

conj::~conj(){
    apaga(); }

void conj::copia(const conj &cj2){

}

bool conj::vazio() const{
    return prim == NULL;
}

bool conj::insere(const int& valor){
    elo *p = prim, *ant = NULL;
    
    for (p = prim;(p != NULL); p = p->prox){
        if (p->dado == valor) return false;
        if (p->dado > valor) break;
        ant = p;
    }
    
    elo *q = new elo(valor);
    
    if (p == prim)
        prim = q;
    else
        ant->prox = q;
    q->prox = p;
    return true;
}

bool conj::remove(const int& valor){
    elo *p = prim, *ant = NULL;
    
    for (p = prim;(p != NULL); p = p->prox){
        if (p->dado > valor) return false;
        if (p->dado == valor) break;
        ant = p;
    }
    if (p == NULL)
        return false;
    if (p == prim)
        prim = prim->prox;
    else
        ant->prox = p->prox;
    
    delete p;
    
    return true;
}

bool conj::pertence(const int& valor) const{
    elo *p;
    for (p = prim;((p != NULL) && (p->dado < valor)); p = p->prox){
        if ((p == NULL) || (p->dado > valor)) return false;
    }
    return true;
}

conj& conj::operator=(const conj& cj2){
    if (this != &cj2)
    {
        apaga();
        copia(cj2);
    }
    return (*this);
}

conj conj::operator+(const conj& cj2) const{
    elo *q, *p1 = prim, *p2 = cj2.prim, *ult = NULL; conj uniao;
    while ( (p1 != NULL) || (p2 != NULL) ){
    }
    if ( (p1 != NULL) && ( (p2 == NULL) || (p1->dado < p2->dado))){ q = new elo(p1->dado);
        p1 = p1->prox;
    } else {
        q = new elo(p2->dado);
        if ((p1 != NULL) && (p1->dado == p2->dado))
            p1 = p1->prox;
        p2 = p2->prox;
    }
    if (ult == NULL)
        uniao.prim = q;
    else
        ult->prox = q;
    ult = q;
    return uniao;
}

conj conj::operator*(const conj& cj2) const{
    elo *q, *p1 = prim, *p2 = cj2.prim, *ult = NULL;; conj intersec;
    while ( (p1 != NULL) && (p2 != NULL) ){
        if (p1->dado == p2->dado){ q = new elo(p1->dado);
            if (ult == NULL)
                intersec.prim = q;
            else
                ult->prox = q;
            ult = q;
            p1 = p1->prox;
            p2 = p2->prox;
        }
        else if (p1->dado < p2->dado)
            p1 = p1->prox;
        else
            p2 = p2->prox;
    }
    return intersec;
}

conj conj::operator-(const conj& cj2) const{
    elo *q, *p1 = prim, *p2 = cj2.prim, *ult = NULL;
    conj diff;
    
    while ( (p1 != NULL) && (p2 != NULL) )
    {
        if ( p1->dado < p2->dado )
        {
            q = new elo(p1->dado);
            p1 = p1->prox;
            if (ult == NULL)
                diff.prim = q;
            else{
                ult->prox = q;
            }
            ult = q;
        }
        else
        {
            if ( p1->dado == p2->dado ){
                p1 = p1->prox;
                p2 = p2->prox;
            }
            else{
                p2 = p2->prox;
            }
        }
    }
    while (p1 != NULL)
    {
        q = new elo(p1->dado);
        p1 = p1->prox;
        if (ult == NULL) 
            diff.prim = q;
        else{
            ult->prox = q;
        }
        ult = q;	
    }
    return diff;
}

int conj::tamanho() const{
    int tam = 0;
    elo *p;
    
    for(p = prim; p != NULL; p = p->prox)
        tam++;
    
    return tam;
    
}

void conj::imprime() const{
    elo *p;
    cout << "Elementos do conjunto" << endl; for(p = prim; p != NULL; p = p->prox)
        cout << p->dado << ' ';
    cout << endl;
}