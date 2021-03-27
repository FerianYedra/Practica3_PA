#include "def.h"
/**
 * @file
 * @brief
 * @author
 * @date
 * @param
 * @return
 */
extern nodito *anexarFIFO(nodito *pt, info dat){
	nodito *aux, *mover;
	printf("Anexando FIFO\n");
	mover = pt;
	aux = (nodito *)malloc(sizeof(nodito));
	if(aux == NULL){
		printf("Error: no hay memoria disponible\n");
		exit(1);
	}
	aux->cuenta = dat.cta;
	strcpy(aux->nombre, dat.nom);
	strcpy(aux->carrera, dat.car);
	aux->promedio = dat.prom;
	aux->next = NULL;
	if(pt == NULL){
		pt = aux;
	}else{
		while(mover->next != NULL){
			mover = mover->next;
		}
		mover->next = aux;
	}

	return pt;
}

extern int revisarMaterias(nodo *pt, info dat){
	nodo *aux = pt;
	int i = 0;
	
	do{
		if(strcmp(dat.car, pt->carrera) == 0){
			printf("Carrera %s  repetida, anexando FIFO de %s\n", dat.car, pt->carrera);//Print de prueba
			pt->fifo = anexarFIFO(pt->fifo, dat);
			i = 1;
		}
		pt = pt->der;
	}while(pt->der != aux);
	pt = aux;

	return i;
}

extern nodo *crearListaDoble(nodo *pt, info dat)
{
  nodo *nuevo, *aux = pt;

  nuevo=(nodo *)malloc(sizeof(nodo));
  nuevo->fifo = NULL;
  if(nuevo == NULL)
   {
	   printf("\nNo hay memoria disponible");
	   exit(1);
   }
  strcpy(nuevo->carrera, dat.car);
  if(pt == NULL)
  {
	  pt=nuevo;
	  nuevo->der=pt;
	  nuevo->izq=pt;
	  nuevo->fifo = anexarFIFO(nuevo->fifo, dat);
  }else{
	  if(revisarMaterias(pt, dat) == 1){
		free(nuevo);
	  }else{
	  	aux=pt->izq;
          	nuevo->izq=aux;
          	nuevo->der=pt;
          	pt->izq=nuevo;
          	aux->der=nuevo;
		nuevo->fifo = anexarFIFO(nuevo->fifo, dat);
	  }
    }

  return pt;
}

extern void imprimirFIFO(nodito *pt){
	nodito *aux = pt;
	printf("Imprimiendo carrera\n");
	while(aux != NULL){
		printf("\n----------------\n %i\n %s\n %s\n %f\n",aux->cuenta,aux->nombre,aux->carrera,aux->promedio);
		aux = aux->next;
	}
	printf("Fin de la lista\n");

	return;
}

void fetchInfo(nodo *pt){
	nodo *inicio = pt;
	float sum = 0.0;
	float promPasado = pt->fifo->promedio;
	
	nodo *aux = pt;
	while(aux->fifo != NULL){
		printf("Fetching...\n");
		pt->alumnos++;
		printf("Alumno sumado\n");
		sum += pt->fifo->promedio;
		printf("promedio añadido\n");
		if(pt->fifo->promedio >= promPasado){
			strcpy(pt->mejor, pt->fifo->nombre);
			printf("mejor nombre cambiado\n");
		}
		promPasado = pt->fifo->promedio;
		aux->fifo = aux->fifo->next;
	}
	pt->prom = sum/pt->alumnos;
	pt = inicio;
	printf("Saliendo de fetch\n");
	
	return;
}
