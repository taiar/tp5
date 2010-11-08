/*
 * simulacao.h
 *
 *  Created on: 08/11/2010
 *      Author: taiar
 */

#ifndef SIMULACAO_H_
#define SIMULACAO_H_

#include <stdlib.h>

#include "camadas.h"

typedef struct
{
  int *tempos;
  int *frequencia;
} Simulacao;

simulacao(Camada*, Simulacao*);

#endif /* SIMULACAO_H_ */
