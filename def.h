/**
 * @flie
 * @brief
 * @author
 * @date
 */

#include <stdio.h>
#include <sdlib.h>
#include <string.h>

struct datos{
	int cta;
	char nom[40];
	char car[80];
	float prom;
};
typedef struct datos info;

struct lista{
	info alumno;
	struct lista *next;
};
typedef struct lista nodito;

struct elemento{
	info alumno;
	struct elemento *izq, *der;
};
typedef struct elemento nodo;
