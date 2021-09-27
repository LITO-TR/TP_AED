#include"Admin.h"

void menu1() {
   cout<<"\t\tRegistro de Usuarios\n";
   cout <<"1. Registrar nuevos usuarios \n";
   cout <<"2. Mostrar archivo creado por usuario \n";
   cout <<"0. Para continuar al filtrado de datos \n";
   cout << "Ingrese una opcion: \n";
}
void menu2() {

    cout << "\t\tFiltrado de datos\n";
    cout << "1. Filtrar Igual a: \n";
    cout << "2. Filtrar inicia con: \n";
    cout << "3. Filtrar finaliza con: \n";
    cout << "4. Filtrar contenido en: \n";
    cout << "5. Comentar  en: \n";
    cout << "0. Para SALIR \n";
    cout << "10. Volver a escoger el archivo que desea filtrar \n";
    cout << "Ingrese una opcion: \n";

}

int main() {
    Admin lamb;
    vector<Plantilla> personas;
    int op, x;
    string file_name;
    string nombre_nuevo_usuario, nuevo_archivo;
 
    

    auto igual_a = [](vector<Plantilla> p) {
        string name;
        cout << "De que nombre desea saber su id: ";
        cin >> name;
        for (size_t i = 0; i < p.size(); ++i) {
            if (p[i].tipo_nombre == name)
                cout << "El id de: " << p[i].tipo_nombre << " es igual a: " << p[i].id << endl;
        }
    };
    //lamb.salen(personas,igual_a);

    auto inicia_con = [](vector<Plantilla> p) {

        char inicio;
        cout << "Con que inicia: ? ";
        cin >> inicio;
        for (size_t i = 0; i < p.size(); ++i) {
            if (p[i].tipo_nombre[0] == inicio)
                cout << p[i].tipo_nombre << " " << p[i].id << endl;
        }

    };
    // lamb.salen(personas, inicia_con);

    auto finaliza_con = [](vector<Plantilla> p) {
        char fin;
        int cont = 0;
        cout << "Con que finaliza? ";
        cin >> fin;

        for (size_t i = 0; i < p.size(); ++i) {
            for (size_t j = 0; j < p[i].tipo_nombre.length(); ++j)
                if (p[i].tipo_nombre[j] == fin)
                    cout << p[i].tipo_nombre << " " << p[i].id << endl;
        }
    };
    //salen(personas,finaliza_con);

    auto contenido_y_no_contenido = [](vector<Plantilla> p) {
        size_t i;
        string name;
        cout << "Escriba el nombre de lo que desea buscar: ";
        cin >> name;

        for (i = 0; i < p.size(); ++i) {
            if (p[i].tipo_nombre == name) {
                cout << p[i].tipo_nombre << "  Esta contenido en esta carpeta. \n";
            }
        }
    };

    do {
        menu1();
        cin >> op;

        switch (op)
        {
        case 0:
            continue;
        case 1:
            cout << "Ingrese nombre de usuario: ";
            cin >> nombre_nuevo_usuario;
            lamb.registrar_usuario(nombre_nuevo_usuario);
            break;
            break;
        case 2:
            cout << "Ingrese nombre del nuevo archivo: ";
            cin >> nuevo_archivo;
            lamb.mostrar_usuarios(nuevo_archivo, nombre_nuevo_usuario);
            break;
        default:
            break;
        }


        system("PAUSE");

    } while (op != 0);

    cout << "Ingrese el nombre del archivo que quiere filtrar: ";
    cin >> file_name;
    lamb.read(personas, file_name);

    do {
        menu2();
        cin >> op;

        switch (op)
        {
        case 0:
            exit(1);
        case 1:
            lamb.salen(personas, igual_a);
            break;
        case 2:
            lamb.salen(personas, inicia_con);
            //   lamb.salen()
            break;

        case 3:
            lamb.salen(personas, finaliza_con);
            //   lamb.salen()
            break;
        case 4:
            lamb.salen(personas, contenido_y_no_contenido);
            //   lamb.salen()
            break;
        case 5:
            lamb.coment(personas, file_name);
            //   lamb.salen()
            break;

        case 10:
            if(op==10)
            return main();
        default:
            break;
        }
    } while (op != 0);

}