#include "def.h"
/**
 * @file
 * @brief
 * @author
 * @date
 * @param
 * @return
 */

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
	  //TODO Revisar que al mandar no este repetida la carrera, incluir FIFO
	  aux=pt->izq;
	  nuevo->izq=aux;
	  nuevo->der=pt;
	  pt->izq=nuevo;
	  aux->der=nuevo;
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

/*extern void imprimirInfoNodo(navegador datos)
{
  int cuenta;
  char nombre[40];
  char carrera[80];
  float promedio;

  printf("\nDatos del nodo actual:\n %i\n %s\n %s\n %f\n",datos.next->cuenta,datos.next->nombre,datos.next->carrea,datos.next->promedio);
  return;
}*/

