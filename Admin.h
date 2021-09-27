#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
#include<string>
#include <vector>
#include"Usuario.h"
#include"Lista.h"
using namespace std;
struct Plantilla
{
    string tipo_nombre;
    string id;
    Plantilla(string tipo_nombre, string id) : tipo_nombre(tipo_nombre), id(id) {  }

};

class Admin {
	Lista<Usuario> usuarios;
public:
    Admin() {
		usuarios = Lista<Usuario>();
	}
    void salen(vector<Plantilla> p, function<void(vector<Plantilla>)> criterio) {
        criterio(p);
    }
	void read(vector<Plantilla>& personas, string file_name) {

		ifstream file(file_name);
		if (!file.is_open()) {
			cerr << "No se pudo abrir el archivo" << endl;
		}
		string nombre_archivo, tipo_dat;
		while (getline(file, nombre_archivo, '*')) {
			file >> tipo_dat; file.get();
			personas.push_back(Plantilla(nombre_archivo, tipo_dat));
		}

		file.close();

	}
	void registrar_usuario(string new_user) {

		usuarios.push_back(Usuario(new_user));
		ofstream file("Users.txt", ios::app);
		file << new_user << endl;
		file.close();
	}
	void mostrar_usuarios(string new_file,string new_user) {

		ofstream file("files_users.txt", ios::app);
		file << new_user << "->" << new_file << endl;
		file.close();
	}
	void coment(vector<Plantilla>& personas, string file_name) {

		string comentario;
        ofstream file;
		file.open(file_name.c_str(), ios::app);
		if (file.fail()) {
			cout << "No se pudo abrir el archivo" << endl;
		}
		fflush(stdin);
		cout << "Ingrese su comentario:(//) ";
        cin >> comentario;
	    getline(cin,comentario);
		file << comentario << endl;
		file.close();
	}

   
};