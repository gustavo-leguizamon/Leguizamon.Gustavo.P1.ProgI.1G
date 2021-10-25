#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	char nombre[20];
	char tipo;
	float efectividad;
} eVacuna;

float aplicarAumento(float precio);
int ordenarVacunas(eVacuna vacunas[], int len);
int reemplazarCaracteres(char cadena[], char primerCaracter, char segundoCaracter);

int main(void) {
	setbuf(stdout, NULL);

	/*
	printf("Precio: %.2f", 100);
	printf("Precio con 5 de aumento: %.2f", aplicarAumento(100));
	*/
	float precio = 100.0;
	printf("Precio: %.2f\n", precio);
	printf("Precio con 5 porciento de aumento: %.2f", aplicarAumento(precio));

	return EXIT_SUCCESS;
}


float aplicarAumento(float precio){
	return precio * 1.05;
}

int reemplazarCaracteres(char cadena[], char primerCaracter, char segundoCaracter){
	int reemplazos = 0;
	int index = 0;

	if (cadena != NULL){
		while (cadena[index] != '\0'){
			if (cadena[index] == primerCaracter){
				cadena[index] = segundoCaracter;
				reemplazos++;
			}
			index++;
		}
	}

	return reemplazos;
}

int ordenarVacunas(eVacuna vacunas[], int len){
	int exito = 0;
	eVacuna auxVacuna;

	if (vacunas != NULL && len > 0){
		for (int i = 0; i < len - 1; i++){
			for (int j = i + 1; j < len; j++){
				if ((vacunas[i].tipo > vacunas[j].tipo) ||
					(vacunas[i].tipo == vacunas[j].tipo && vacunas[i].efectividad > vacunas[j].efectividad)){
					auxVacuna = vacunas[i];
					vacunas[i] = vacunas[j];
					vacunas[j] = auxVacuna;
				}
			}
		}

		exito = 1;
	}

	return exito;
}

