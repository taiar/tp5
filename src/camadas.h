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

void camadaInicia(char*, int, int, Camada*);
void hierarquiaConstroi(int, Camada*);
void hierarquiaImprime(int, Camada*);

#define CAMADAS_H_

#endif /* CAMADAS_H_ */
