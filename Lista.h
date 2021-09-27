#pragma once
#include"Nodo.h"
#include<functional>
#ifndef __LISTA_HPP__

#define __LISTA_HPP__

template <class G>

class Lista {

    Nodo<G>* inicio;
    Nodo<G>* fin;
    long cantidad;

public:

    Lista() {
        inicio = nullptr;
        fin = nullptr;
        cantidad = 0;
    }
    void push_front(G valor) {
        Nodo<G>* nuevo = new Nodo<G>(valor);
        if (cantidad == 0)
            inicio = fin = nuevo;
        else {
            nuevo->siguiente = inicio;
            nuevo->siguiente->anterior = nuevo;
            inicio = nuevo;
        }
        ++cantidad;
    }
    void clear() {
        while (0 < cantidad) {
            delete_front();
        }
    }
    void push_back(G valor) {
        Nodo<G>* nuevo = new Nodo<G>(valor);
        if (cantidad == 0)
            inicio = fin = nuevo;
        else {
            fin->siguiente = nuevo;
            nuevo->anterior = fin;
            fin = nuevo;
        }
        ++cantidad;
    }
    int size() { return cantidad; }
    void insert(G valor, long pos) {
        if (pos<0 || pos>cantidad)return;
        if (pos == 0)
            push_front(valor);
        else if (pos == cantidad)
            push_back(valor);
        else {
            Nodo<G>* nuevo = new Nodo<G>(valor);
            Nodo<G>* aux = inicio;
            for (long i = 0; i < pos - 1; ++i) {
                aux = aux->siguiente;
            }
            nuevo->siguiente = aux->siguiente;
            nuevo->anterior = aux;
            nuevo->siguiente->anterior = nuevo;
            aux->siguiente = nuevo;
            ++cantidad;
        }
    }
    void print(const std::function<void(G)>& key) {
        Nodo<G>* aux = inicio;
        while (aux != nullptr) {
            key(aux->valor);
            aux = aux->siguiente;
        }
    }
    void delete_front() {
        if (cantidad == 0)return;
        else if (cantidad == 1) {
            delete inicio;
            inicio = fin = nullptr;
        }
        else {
            Nodo<G>* aux = inicio;
            inicio = inicio->siguiente;
            delete aux;
            inicio->anterior = nullptr;
        }
        --cantidad;
    }
    void delete_back() {
        if (cantidad == 0)return;
        else if (cantidad == 1)
        {
            delete fin;
            inicio = fin = nullptr;
            --cantidad;
        }
        else {
            fin = fin->anterior;
            delete fin->siguiente;
            fin->siguiente = nullptr;
            --cantidad;
        }
    }
    void delete_at(int pos) {
        if (pos == 0) { delete_front(); }
        else if (pos == cantidad - 1) { delete_back(); }
        else {
            Nodo<G>* aux = inicio;
            for (int i = 0; i < pos; i++) {
                aux = aux->siguiente;
            }
            Nodo<G>* obj = aux->siguiente;
            aux->anterior->siguiente = obj;
            obj->anterior = aux->anterior->siguiente;
            cantidad--;
        }
    }
    G& operator[](const int& pos) {
        Nodo<G>* aux = inicio;
        for (int i = 0; i < pos; i++) {
            aux = aux->siguiente;
        }
        return aux->valor;
    }
    void show() {
        Nodo<G>* aux = inicio;
        for (int i = 0; i < cantidad; i++) {
            cout << aux->elemento << " ";
            aux = aux->siguiente;
        }
        //	if(aux == nullptr) cout << "?";
        cout << endl;
    }

};

#endif
