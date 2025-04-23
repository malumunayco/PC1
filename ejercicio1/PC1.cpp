// PC1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

//Almeida Mora, Rodrigo Fernando - u20211g708

#include <iostream>
#include <cstdlib> // Para system("cls")
#include "opciones.h"
using namespace std;
void pausarPantalla() {
	cout << "\nPresione ENTER para continuar...";
	cin.get();
}
int main() {
	int opcion;

	int longitud;
	int* arreglo = nullptr;

	do {
		system("cls"); // Limpia la pantalla
		menu();
		cin >> opcion;
		cin.ignore(); // Limpia el buffer del ENTER
		switch (opcion) {
		case 1:
			if (arreglo != nullptr) {
				cout << "Ya se ha generado un arreglo previamente.\n";
			}
			else {
				arreglo = GenerarArreglo(longitud);
			}
			cin.ignore();
			break;
		case 2:
			if (arreglo == nullptr) {
				cout << "Primero debe generar un arreglo.\n";
				break;
			}
			int objetivo;
			cout << "Ingrese el numero a buscar: ";
			cin >> objetivo;
			BuscarElemento(arreglo, longitud, objetivo);
			cin.ignore();
			break;
		case 3:
			if (arreglo == nullptr) {
				cout << "Primero debe generar un arreglo.\n";
				break;
			}
			SumarPrimerElemento(arreglo);
			cin.ignore();
			break;
		case 4:
			if (arreglo == nullptr) {
				cout << "Primero debe generar un arreglo.\n";
				break;
			}
			BuscarDuplicados(arreglo, longitud);
			cin.ignore();
			break;
		case 5:
			if (arreglo != nullptr) {
				delete[] arreglo; // Liberar memoria del arreglo previo
			}
			arreglo = GenerarArreglo(longitud);
			cin.get();
			break;
		case 0:
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opcion invalida." << endl;
		}
		if (opcion != 0) {
			pausarPantalla();
		}
	} while (opcion != 0);
	return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
