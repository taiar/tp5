/*
 * camadas.h
 *
 *  Created on: 08/11/2010
 *      Author: taiar
 */

#ifndef CAMADAS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
  char politica[5];
  int capacidade;
  int velocidade;
  int *memoria;
} Camada;

typedef struct
{
  Camada *camadas;
  int nCamadas;
} Hierarquia;

void camadaInicia(char*, int, int, Camada*);
Camada* hierarquiaConstroi(int);
void hierarquiaInicia(int, Hierarquia*);
void hierarquiaImprime(Hierarquia*);
void hierarquiaFree(Hierarquia*);

#define CAMADAS_H_

#endif /* CAMADAS_H_ */
