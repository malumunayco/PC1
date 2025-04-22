#pragma once
//opciones.h
#pragma once
#ifndef OPCIONES_H
#define OPCIONES_H
struct Nodo {
	int valor;
	Nodo* siguiente; 
};
void menu();
void generarArreglo(Nodo*&cabeza);
void busquedaLineal(Nodo*cabeza);
void busquedaBinaria(Nodo*cabeza);
void busquedaComparacion(Nodo* cabeza);
#endif