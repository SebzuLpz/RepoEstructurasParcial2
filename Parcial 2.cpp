/*Puse las funciones de la lista circular n comentario ya que no me funcionaban
por un constructor en el nodo y no me compilaba el codigo.
Lo de arboles no logre hacerlo, solo esta hecho lo de pilas y colas con prioridad*/

#include <iostream>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

struct Nodo {

    int valor;
    
    int prioridad;
    Nodo(int v, int p) : valor(v), prioridad(p) {}
    /* Nodo* siguiente;*/
    
};




bool operator<(const Nodo& a, const Nodo& b) {
    return a.prioridad > b.prioridad;
}

void agregarANQ(priority_queue<Nodo>& pq, int valor, int prioridad) {
    pq.push(Nodo(valor, prioridad));
    cout << "Nodo agregado: " << valor << " con prioridad " << prioridad << endl;
}

void agregarASP(stack<Nodo>& s, int valor, int prioridad) {
    s.push(Nodo(valor, prioridad));
    cout << "Nodo agregado: " << valor << " con prioridad " << prioridad << endl;
}

void eliminarDeNQ(priority_queue<Nodo>& pq) {
    if (pq.empty()) {
        cout << "Error: La cola de prioridad esta vacia." << endl;
        return;
    }
    cout << "Nodo eliminado: " << pq.top().valor << " con prioridad " << pq.top().prioridad << endl;
    pq.pop();
}

void eliminarDeSP(stack<Nodo>& s) {
    if (s.empty()) {
        cout << "Error: La pila esta vacia." << endl;
        return;
    }
    cout << "Nodo eliminado: " << s.top().valor << " con prioridad " << s.top().prioridad << endl;
    s.pop();
}

void mostrarNQ(priority_queue<Nodo>& pq) {
    if (pq.empty()) {
        cout << "Error: La cola de prioridad esta vacia." << endl;
        return;
}
    cout << "Cola de prioridad: ";
    while (!pq.empty()) {
        cout << "(" << pq.top().valor << ", " << pq.top().prioridad << ") ";
        pq.pop();
    }
    cout << endl;
}

void mostrarSP(stack<Nodo>& s) {
    if (s.empty()) {
        cout << "Error: La pila esta vacia." << endl;
        return;
    }
    cout << "Pila con prioridad: ";
    while (!s.empty()) {
        cout << "(" << s.top().valor << ", " << s.top().prioridad << ") ";
        s.pop();
    }
    cout << endl;
}
/*
void listacircular (){
    ListaEnlazadaCircular lista;
        cout << "Lista enlazada circular:\n" << endl;
    lista.imprimirLista();

    int minimo = lista.encontrarMinimo();
    int maximo = lista.encontrarMaximo();
    int suma = lista.calcularSuma();

    if (minimo != INT_MAX && maximo != INT_MIN) {
        cout << "El valor minimo es: " << minimo << endl;
        cout << "El valor maximo es: " << maximo << endl;
        cout << "La suma de todos los valores es: " << suma << endl;
    }
}


class ListaEnlazadaCircular {
private:
    Nodo* cabeza;
public:
    ListaEnlazadaCircular() {
        cabeza = nullptr;
    }
    ~ListaEnlazadaCircular() {
        if (cabeza != nullptr) {
            Nodo* actual = cabeza;
            Nodo* siguiente = cabeza->siguiente;
            while (siguiente != cabeza) {
                delete actual;
                actual = siguiente;
                siguiente = siguiente->siguiente;
            }
            delete actual;
        }
    }
    void agregarElemento() {
        Nodo* NodoNuevo = new Nodo;
        NodoNuevo->valor;
        if (cabeza == nullptr) {
            cabeza = NodoNuevo;
            cabeza->siguiente = cabeza;
        } else {
            Nodo* ultimo = cabeza;
            while (ultimo->siguiente != cabeza) {
                ultimo = ultimo->siguiente;
            }
            NodoNuevo->siguiente = cabeza;
            ultimo->siguiente = NodoNuevo;
        }
    }
    void imprimirLista() {
        if (cabeza != nullptr) {
            Nodo* actual = cabeza;
            do {
                cout << actual->valor << " ";
                actual = actual->siguiente;
            } while (actual != cabeza);
            cout << endl;
        }
    }

    int encontrarMaximo() {
        if (cabeza == nullptr) {
            cout << "La lista esta vacia." << endl;
            return INT_MIN;
        }
        Nodo* actual = cabeza;
        int maximo = INT_MIN;
        do {
            if (actual->valor > maximo) {
                maximo = actual->valor;
            }
            actual = actual->siguiente;
        } while (actual != cabeza);
        return maximo;
    }


    int encontrarMinimo() {
        if (cabeza == nullptr) {
            cout << "La lista esta vacia." << endl;
            return INT_MAX;
        }
        Nodo* actual = cabeza;
        int minimo = INT_MAX;
        do {
            if (actual->valor < minimo) {
                minimo = actual->valor;
            }
            actual = actual->siguiente;
        } while (actual != cabeza);
        return minimo;
    }

    int calcularSuma() {
        if (cabeza == nullptr) {
            cout << "La lista esta vacia." << endl;
            return 0;
        }
        Nodo* actual = cabeza;
        int suma = 0;
        do {
            suma += actual->valor;
            actual = actual->siguiente;
        } while (actual != cabeza);
        return suma;
    }
};

void arbol (){
    
};
*/


int main() {
    priority_queue<Nodo> colaDePrioridad;
    stack<Nodo> pilaConPrioridad;

    int opcion, valor, prioridad;

    while (true) {
        cout << "--- MENU ---\n";
        cout << "1. Agregar nodo a la cola de prioridad\n";
        cout << "2. Agregar nodo a la pila con prioridad\n";
        cout << "3. Eliminar nodo de la cola de prioridad\n";
        cout << "4. Eliminar nodo de la pila con prioridad\n";
        cout << "5. Mostrar cola de prioridad\n";
        cout << "6. Mostrar pila con prioridad\n";
        cout << "7. Ver Lista Circular (No funciona)\n";
        cout << "8. Ver Arbol (No pude hacerlo)\n";
        cout << "9. Salir\n";
        cout << "------------\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingresa el valor: ";
                cin >> valor;
                cout << "Ingresa la prioridad: ";
                cin >> prioridad;
                agregarANQ(colaDePrioridad, valor, prioridad);
                break;
            case 2:cout << "Ingresa el valor: ";
                cin >> valor;
                cout << "Ingresa la prioridad: ";
                cin >> prioridad;
                agregarASP(pilaConPrioridad, valor, prioridad);
                break;
            case 3:
                eliminarDeNQ(colaDePrioridad);
                break;
            case 4:
                eliminarDeSP(pilaConPrioridad);
                break;
            case 5:
                mostrarNQ(colaDePrioridad);
                break;
            case 6:
                mostrarSP(pilaConPrioridad);
                break;
            case 7:

                break;
            case 8:

                break;
            case 9:
                cout << "iHasta luego!\n";
                return 0;
            default:
                cout << "Opcion invalida\n";
        }
    }

    return 0;
}