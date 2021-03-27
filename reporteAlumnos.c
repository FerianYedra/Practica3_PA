/**
 * @file
 * @brief
 * @author
 * @date
 */

#include "def.h"
extern nodo *crearListaDoble(nodo *pt, info dat;);
extern void imprimirFIFO(nodito *pt);
extern void fetchInfo(nodo *pt);

int main(int argc, char *argv[]){
	info dat;
	nodo *inicio;
	FILE *fp;
	int i = 0, j;
	navegador nav;
	char opcion;

	inicio = NULL;
	fp = fopen(argv[1], "r");
	if(fp == NULL){
		printf("Error: Archivo no dispoible\n");
		exit(1);
	}
	fclose(fp);
	for(j = 0;j <= 26; j++){
		fp = fopen(argv[1], "r");
		while(fscanf(fp, "%i %[^\t] %[^\t] %f\n", &dat.cta, dat.nom, dat.car, &dat.prom)==4){
			if(dat.nom[0] == 65+j){
				inicio = crearListaDoble(inicio, dat);
				i++;
			}
		}
		fclose(fp);
	}
	printf("Se leyeron %i alumnos\n", i);
	imprimirFIFO(inicio->fifo);
	fetchInfo(inicio);
	//Implementar Navegador
	printf("prom: %f\n", inicio->prom);
	nav.pos = inicio;
	nav.list = nav.pos->fifo;
	while(opcion != 's'){
		fetchInfo(inicio);
		printf("+++++++Menu++++++\n");
		printf("Estas en: %s\n", nav.pos->carrera);
		printf("Tiene: %i alumnos\n", nav.pos->alumnos);
		printf("Promedio general: %f\n", nav.pos->prom);
		printf("El mejor alumno es: %s\n", nav.pos->mejor);
		printf("Seleccionar opción: ");
		scanf(" %c", &opcion);
		switch(opcion){
			case 's':
				printf("Saliendo...\n");
				break;
			default:
				printf("Opcion invalida\n");
				break;
		}
	}

	return 0;
}
