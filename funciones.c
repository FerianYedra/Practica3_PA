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
	nodito *aux, *mover = pt;
	
	aux = (nodito *)malloc(sizeof(nodito));
	if(aux == NULL){
		printf("Error: No hay memoria disponible\n");
		exit(1);
	}
	aux->cuenta = dat.cta;
	strcpy(aux->nombre, dat.nom);
	strcpy(aux->carrera, dat.car);
	aux->promedio = dat.prom;
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
  if(nuevo == NULL)
   {
	   printf("\nNo hay memoria disponible");
	   exit(1);
   }
  nuevo->cuenta = dat.cta;
  strcpy(nuevo->nombre, dat.nom);
  strcpy(nuevo->carrera, dat.car);
  nuevo->promedio = dat.prom;
  if(pt == NULL)
  {
	  pt=nuevo;
	  nuevo->der=pt;
	  nuevo->izq=pt;
  }else{
	  if(revisarMaterias(pt, dat) == 1){
		free(nuevo);
	  }else{
	  	aux=pt->izq;
          	nuevo->izq=aux;
          	nuevo->der=pt;
          	pt->izq=nuevo;
          	aux->der=nuevo;
	  }
    }

  return pt;
}


extern void imprimirLista(nodo *pt)
{
  nodo *imprimir;
  
  if(pt != NULL)
  {
   	imprimir = pt;
   do
   {
    	printf("\n----------------\n %i\n %s\n %s\n %f\n",imprimir->cuenta,imprimir->nombre,imprimir->carrera,imprimir->promedio);
    	imprimir = imprimir->der;
   }while(imprimir != pt);
    	printf("\n");
  }
  else
   {
    	printf("\nLa lista doble está vacía.");
   }

  return;
}

extern void imprimirFIFO(nodito *pt){
	printf("Imprimiendo carrera\n");
	while(pt != NULL){
		printf("\n----------------\n %i\n %s\n %s\n %f\n",pt->cuenta,pt->nombre,pt->carrera,pt->promedio);
		pt = pt->next;
	}
	printf("Fin de la lista\n");

	return;
}
/*extern void imprimirInfoNodo(navegador datos)
{
  int cuenta;
  char nombre[40];
  char carrera[80];
  float promedio;

  printf("\nDatos del nodo actual:\n %i\n %s\n %s\n %f\n",datos.next->cuenta,datos.next->nombre,datos.next->carrea,datos.next->promedio);
  return;
}*/

