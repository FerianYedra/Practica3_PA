#include "def.h"
/**
 * @file
 * @brief
 * @author
 * @date
 * @param
 * @return
 */

extern nodo *crearListaDoble(nodo *pt, char nombreArch[])
{
  FILE *fp;
  int cuenta;
  char nombre[40];
  char carrera[80];
  float promedio;

  nodo *nuevo, *aux;
  fp = fopen(nombreArch,"r");
  if(fp == NULL)
  {
   printf("\nArchivo no disponible.");
   exit(1);
  }
  while(fscanf(fp," %i\t %[^\t] %[^\t] %f\n",&cuenta,nombre,carrera,&promedio)==4)
  {
   nuevo=(nodo *)malloc(sizeof(nodo));
   if(nuevo == NULL)
   {
    printf("\nNo hay memoria disponible");
    exit(1);
   }
  nuevo->cuenta=cuenta;
  strcpy(nuevo->nombre,nombre);
  strcpy(nuevo->carrera,carrera);
  nuevo->promedio=promedio;
  if(pt==NULL)
  {
   pt=nuevo;
   nuevo->der=pt;
   nuevo->izq=pt;
  }
  else
    {
     aux=pt->izq;
     nuevo->izq=aux;
     nuevo->der=pt;
     pt->izq=nuevo;
     aux->der=nuevo;
    }
  }
  fclose(fp);
  return pt;
}


extern void imprimirLista(nodo *pt)
{
  nodo *imprimir;
  if(pt != NULL)
  {
   imprimir =pt;
   do
   {
    printf("\n----------------\n %i\n %s\n %s\n %f\n",imprimir->cuenta,imprimir->nombre,imprimir->carrera,imprimir->promedio);
    imprimir=imprimir-der;
   }while(imprimir != pt);
    printf("\n");
  }
  else
   {
    printf("\nLa lista doble está vacía.");
   }
  return;
}

extern void imprimirInfoNodo(navegador datos)
{
  int cuenta;
  char nombre[40];
  char carrera[80];
  float promedio;

  printf("\nDatos del nodo actual:\n %i\n %s\n %s\n %f\n",datos.next->cuenta,datos.next->nombre,datos.next->carrea,datos.next->promedio);
  return;
}

