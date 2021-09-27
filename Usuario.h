#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
#include<string>
#include <vector>
using namespace std;
class Usuario {
	string nombre;
public:
	Usuario(string nombre) {
		this->nombre = nombre;

	}
	void agregar_archivos(string nuevoArchivo) {
		string auxNombre = nombre;
		ofstream archi(auxNombre);
		archi << nuevoArchivo << endl;
		archi.close();
	}
	string obtNombre() {
		return nombre;
	}

};
