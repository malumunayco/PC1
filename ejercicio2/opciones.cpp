//opciones.cpp
#include <iostream>
#include <vector>
#include<algorithm>
#include <chrono> 
#include "opciones.h"
using namespace std;
using namespace chrono; 
void menu() {
	cout << "=== MENU PRINCIPAL ===" << endl;
	cout << "1. Generar arreglo aleatorio" << endl;
	cout << "2. Buscar numero con busqueda lineal" << endl;
	cout << "3. Buscar numero con busqueda binaria" << endl;
	cout << "4. Buscar numero con comparacion doble" << endl;
	cout << "0. Salir" << endl;
	cout << "Seleccione una opcion: ";
}
void generarArreglo(Nodo*& cabeza) {
	int tamano;
	cout << "\nIngrese el tamano de la lista: ";
	cin >> tamano;

	srand(time(NULL)); 
	for (int i = 0; i < tamano; i++) {
		int valor = rand() % 10000 + 1;

		Nodo* nuevo = new Nodo();
		nuevo->valor = valor;
		nuevo->siguiente = cabeza;
		cabeza = nuevo;
	}

	cout << "Arreglo generado con " << tamano << " elementos aleatorios.\n";
	cout << "\nElementos de la lista: \n";
	Nodo* actual = cabeza;
	while (actual != nullptr) {
		cout << actual->valor;
		if (actual->siguiente != nullptr) {
			cout << " -> ";
		}
		actual = actual->siguiente;
	}
	cout << " -> NULL \n";

}

void busquedaLineal(Nodo*cabeza) {
	int valor;
	cout << "\nIngrese el valor a buscar: ";
	cin >> valor;

	auto inicio = high_resolution_clock::now();  

	Nodo* actual = cabeza;
	int posicion = 1;
	bool encontrado = false;

	while (actual != nullptr) {
		if (actual->valor == valor) {
			cout << "Elemento " << valor << " encontrado en la posicion " << posicion << ".\n";
			encontrado = true;
			break;
		}
		actual = actual->siguiente;
		posicion++;
	}

	if (!encontrado) {
		cout << "Elemento " << valor << " no encontrado en la lista.\n";
	}

	auto fin = high_resolution_clock::now(); 
	duration<double> duracion = fin - inicio;  
	cout << "Tiempo de ejecucion (O(n)): " << duracion.count() << " segundos.\n";
}
void busquedaBinaria(Nodo*cabeza) {
	int valor;
	cout << "\nIngrese el valor a buscar: ";
	cin >> valor;

	auto inicio = high_resolution_clock::now();  

	Nodo* actual = cabeza;
	vector<int> lista;
	while (actual != nullptr) {
		lista.push_back(actual->valor);
		actual = actual->siguiente;
	}

	sort(lista.begin(), lista.end());

	bool encontrado = binary_search(lista.begin(), lista.end(), valor);

	if (encontrado) {
		cout << "Elemento " << valor << " encontrado.\n";
	}
	else {
		cout << "Elemento " << valor << " no encontrado.\n";
	}

	auto fin = high_resolution_clock::now();  
	duration<double> duracion = fin - inicio; 
	cout << "Tiempo de ejecucion (O(log n)): " << duracion.count() << " segundos.\n";
}
void busquedaComparacion(Nodo* cabeza) {
	int valor;
	cout << "\nIngrese el valor a buscar: ";
	cin >> valor;

	auto inicio = high_resolution_clock::now();  

	Nodo* actual1 = cabeza;
	Nodo* actual2;
	bool encontrado = false;

	while (actual1 != nullptr) {
		actual2 = actual1->siguiente;
		while (actual2 != nullptr) {
			if (actual1->valor == valor || actual2->valor == valor) {
				cout << "Elemento " << valor << " encontrado.\n";
				encontrado = true;
				break;
			}
			actual2 = actual2->siguiente;
		}
		if (encontrado) break;
		actual1 = actual1->siguiente;
	}

	if (!encontrado) {
		cout << "Elemento " << valor << " no encontrado.\n";
	}

	auto fin = high_resolution_clock::now(); 
	duration<double> duracion = fin - inicio;  
	cout << "Tiempo de ejecucion (O(n²)): " << duracion.count() << " segundos.\n";
}