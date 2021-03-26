/**
 * @file
 * @brief
 * @author
 * @date
 */

#include "def.h"
extern nodo *crearListaDoble(nodo *pt, info dat;);
extern void imprimirLista(nodo *pt);
extern void imprimirFIFO(nodito *pt);

int main(int argc, char *argv[]){
	info dat;
	nodo *inicio;
	FILE *fp;
	int i = 0, j;

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
	imprimirLista(inicio);
	imprimirFIFO(inicio->fifo);

	return 0;
}
