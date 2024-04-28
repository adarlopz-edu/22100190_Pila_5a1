#include <iostream>
#include <string>

using namespace std;

class Persona {
public:
    string nombre;
    string apellido;
    int registro;
    int edad;

    //constructor
    Persona(string nombre, string apellido, int registro, int edad) : nombre(nombre), apellido(apellido), registro(registro), edad(edad) {}
};

class Nodo {
public:
    Persona* datos;
    Nodo* siguiente;

    //constructor
    Nodo() : datos(NULL), siguiente(NULL) {}
    Nodo(Persona* datos) : datos(datos), siguiente(NULL) {}
};

class Lista {
private:
    Nodo* inicio;
    int contador;

public:
    //constructor
    Lista() : inicio(NULL), contador(0) {}

    //Métodos
    void push(Persona* datos);
    Persona* pop();
    int contar();
    bool estaVacia();
    void limpiar();
    Nodo* getInicio() {
        return inicio;
    }
};

void Lista::push(Persona* datos) {
    //agrega un nodo al inicio de la lista
    Nodo* nuevo = new Nodo(datos);
    nuevo->siguiente = inicio;
    inicio = nuevo;
    contador++;
}

Persona* Lista::pop() {
    //elimina y devuelve el ultimo nodo agregado
    if (inicio != NULL) {
        Nodo* temp = inicio;
        inicio = inicio->siguiente;
        Persona* datos = temp->datos;
        delete temp;
        contador--;
        return datos;
    }
    return NULL;
}

bool Lista::estaVacia() {
    return inicio == NULL;
}

int Lista::contar() {
    return contador;
}

void Lista::limpiar() {
    while (inicio != NULL) {
        Nodo* temp = inicio;
        inicio = inicio->siguiente;
        delete temp->datos;
        delete temp;
        contador--;
    }
}

int main() {
    Lista pila;
    char opcion;

    pila.push(new Persona("Ana", "Garcia", 12345, 30));
    pila.push(new Persona("Carlos", "Martinez", 54321, 25));
    pila.push(new Persona("Elena", "Lopez", 98765, 40));

    //Menu
    while (true) {
        cout << endl << "Stack brad" << endl << endl;
        cout << "a. Agregar nodo" << endl;
        cout << "b. Obtener" << endl;
        cout << "c. Contar" << endl;
        cout << "d. Vacio" << endl;
        cout << "e. Limpiar" << endl;
        cout << endl << "Ingrese una opcion: ";
        cin >> opcion;

        if (opcion == 'a') {
            string nombre, apellido;
            int registro, edad;
            cout << "Ingrese el nombre: ";
            cin >> nombre;
            cout << "Ingrese el apellido: ";
            cin >> apellido;
            cout << "Ingrese el registro: ";
            cin >> registro;
            cout << "Ingrese la edad: ";
            cin >> edad;
            pila.push(new Persona(nombre, apellido, registro, edad));
        }
        if (opcion == 'b') {
            Persona* ultimoElemento = pila.pop();
            if (ultimoElemento != NULL) {
                cout << "Datos obtenidos: " << endl;
                cout << "Nombre: " << ultimoElemento->nombre << endl;
                cout << "Apellido: " << ultimoElemento->apellido << endl;
                cout << "Registro: " << ultimoElemento->registro << endl;
                cout << "Edad: " << ultimoElemento->edad << endl << endl;
            }
            else {
                cout << "La pila esta vacia" << endl << endl;
            }
        }
        if (opcion == 'c') {
            cout << "Cantidad de nodos en la pila: " << pila.contar() << endl << endl;
        }
        if (opcion == 'd') {
            if (pila.estaVacia()) {
                cout << "La pila esta vacia" << endl << endl;
            }
            else {
                cout << "La pila no esta vacia" << endl << endl;
            }
        }
        if (opcion == 'e') {
            pila.limpiar();
            cout << "Todos los elementos de la pila han sido eliminados" << endl << endl;
        }
    }
}
