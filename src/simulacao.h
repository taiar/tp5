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
  int nRequests;
  int tempoAtual;
  /*
   * TODO: arrumar uma forma de contabilizar hit e miss das camadas
   * */
} Simulacao;

void simulacaoExecuta(Hierarquia*, Simulacao*);
void simulacaoProcessaRequest(int, int, Simulacao*);

#endif /* SIMULACAO_H_ */
