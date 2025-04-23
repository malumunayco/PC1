//main.cpp
/*Nombre : Maria Luisa Munayco Apolaya
           codigo: U20231C995*/
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
	Nodo* lista = nullptr;
	do {
		system("cls"); // Limpia la pantalla
		menu();
		cin >> opcion;
		cin.ignore(); // Limpia el buffer del ENTER
		switch (opcion) {
		case 1:
			generarArreglo(lista);cin.get();
			break;
		case 2:
			busquedaLineal(lista);cin.get();
			break;
		case 3:
			busquedaBinaria(lista);cin.get();
			break;
		case 4:
			busquedaComparacion(lista);cin.get();
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
