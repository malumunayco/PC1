#include <iostream>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>
#include <chrono> // Para medir el tiempo de ejecucion
using namespace std;
void menu() {
	cout << "=== MENU PRINCIPAL ===" << endl;
	cout << "1. Generar arreglo" << endl;
	cout << "2. Buscar un elemento del arreglo" << endl;
	cout << "3. Sumar el primer elemento" << endl;
	cout << "4. Buscar elementos repetidos en el arreglo" << endl;
	cout << "5. Refrescar el arreglo" << endl;
	cout << "0. Salir" << endl;
	cout << "Seleccione una opcion: ";
}

int* GenerarArreglo(int& longitud) {
	cout << "Ingrese la longitud del arreglo: ";
	cin >> longitud;

	// Validación para longitud válida
	if (longitud <= 0) {
		cout << "Longitud no valida. El arreglo debe tener al menos un elemento." << endl;
		longitud = 0;  // Esto hará que el programa no continúe con un arreglo vacío.
		return nullptr;
	}

	int* arreglo = new int[longitud];
	srand(time(0)); // Inicializar la semilla para números aleatorios
	cout << "Arreglo generado: ";
	for (int i = 0; i < longitud; i++) {
		arreglo[i] = rand() % 100; // Números aleatorios entre 0 y 99
		cout << arreglo[i] << " ";
	}
	cout << endl;
	return arreglo;
}

void BuscarElemento(int arreglo[], int longitud, int objetivo) {
	auto inicio = chrono::high_resolution_clock::now();

	bool encontrado = false;
	for (int i = 0; i < longitud; i++) {
		if (arreglo[i] == objetivo) {
			cout << "Elemento " << objetivo << " encontrado en la posicion " << i << endl;
			encontrado = true;
			break;
		}
	}
	if (!encontrado) {
		cout << "Elemento no encontrado." << endl;
	}

	auto fin = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duracion = fin - inicio;
	cout << "Tiempo de ejecucion: " << duracion.count() << " ms\n";

	cout << "Complejidad esperada: Busqueda lineal (O(n))" << endl;
}
void SumarPrimerElemento(int arreglo[]){
	auto inicio = chrono::high_resolution_clock::now();

	int numero = arreglo[0];
	int suma = 0;
	while (numero > 0) {
		suma += numero % 10;
		numero /= 10;
	}
	cout << "Suma de los digitos del primer elemento (" << arreglo[0] << "): " << suma << endl;

	auto fin = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duracion = fin - inicio;
	cout << "Tiempo de ejecucion: " << duracion.count() << " ms\n";

	cout << "Complejidad esperada: Acceso directo (O(1))" << endl;
}
void BuscarDuplicados(int arreglo[], int longitud) {
	auto inicio = chrono::high_resolution_clock::now();

	bool duplicado = false;
	for (int i = 0; i < longitud; i++) {
		for (int j = i + 1; j < longitud; j++) {
			if (arreglo[i] == arreglo[j]) {
				cout << "Elemento duplicado encontrado: " << arreglo[i] << endl;
				duplicado = true;
			}
		}
	}
	if (!duplicado) {
		cout << "No se encontraron duplicados." << endl;
	}

	auto fin = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duracion = fin - inicio;
	cout << "Tiempo de ejecucion: " << duracion.count() << " ms\n";

	cout << "Complejidad esperada: Busqueda de elementos duplicados con doble for (O(n^2))" << endl;
}