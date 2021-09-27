#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<stdlib.h>
#include<vector>
template <typename G>
struct Nodo {//Nodo Doble
    G elemento;
    Nodo* siguiente;//puntero al siguiente nodo
    Nodo* anterior;
    Nodo(G e, Nodo* s = nullptr, Nodo* a = nullptr) :elemento(e), siguiente(s), anterior(a) {}
};
