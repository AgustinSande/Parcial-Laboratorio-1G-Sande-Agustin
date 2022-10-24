/*
 ============================================================================
 Name        : Parcial.c
 Author      : Agustin Sande
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 4
typedef struct {
	int id;
	char nombre[20];
	char tipo;
	float efectividad;


}eVacuna;
int aplicarAumento(int precio);
int reemplazarCaracteres(char cadena1[], char caracter1, char caracter2, int tam);
int ordenarTipoEfectividad(eVacuna vacuna[], int tam);
int main(void) {
	setbuf(stdout, NULL);
	eVacuna vacuna[TAM] = {{1, "Hepatitis ", 'A', 30},
			{2, "Gripe", 'B', 50},
			{3, "Coronavirus", 'B', 10},
			{4, "Neumonia", 'A', 15}
			};
	int valor = 1000;
	int resultado;

	char cadena1[]= {"anana"};
	resultado=aplicarAumento(valor);
	printf("%d\n", resultado);

	reemplazarCaracteres(cadena1, 'a','x', 6);
	printf("%s\n", cadena1);
	for(int i = 0; i < TAM; i++){
		printf("%d %s %c %f\n\n", vacuna[i].id, vacuna[i].nombre, vacuna[i].tipo, vacuna[i].efectividad);

	}

	ordenarTipoEfectividad(vacuna, TAM);
	for(int i = 0; i < TAM; i++){
			printf("%d %s %c %f\n\n", vacuna[i].id, vacuna[i].nombre, vacuna[i].tipo, vacuna[i].efectividad);

		}
}

int aplicarAumento(int precio){
	int precioAumentado;

	precioAumentado = precio * 1.05 ;
	return precioAumentado;

}
int reemplazarCaracteres(char cadena1[], char caracter1, char caracter2, int tam){

	int todoOk = 0;
	if(cadena1 != NULL && tam > 0){
		for(int i = 0; i < tam; i++){
			if(cadena1[i] == caracter1){
				cadena1[i] = caracter2;

			}

		}


		todoOk = 1;
	}
	return todoOk;

}

int ordenarTipoEfectividad(eVacuna vacuna[], int tam){
	int todoOk = 0;
	eVacuna auxVacuna;
	if( vacuna != NULL && tam > 0){

		for(int i = 0; i < tam - 1; i++){
			for(int j = i + 1; j < tam ; j++){

				if( (vacuna[i].tipo == vacuna[j].tipo && vacuna[i].efectividad > vacuna[j].efectividad) || (vacuna[i].tipo < vacuna[j].tipo) ) {

					auxVacuna = vacuna[i];
					vacuna[i] = vacuna[j];
					vacuna[j] = auxVacuna;


				}


			}


		}

		todoOk = 1;
	}

	return todoOk;
}
