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

/**
 * Estrutura que armazena dados referentes às simulações em memória.
 */
typedef struct
{
  int *tempos;
  int *frequencia;
  int nRequests;
  int tempoAtual;
  // TODO: arrumar uma forma de contabilizar hit e miss das camadas
} Simulacao;

/**
 * Executa simulação através dos requests enviados na entrada.
 */
void simulacaoExecuta(Hierarquia*, Simulacao*);

/**
 * Processa individualmente cada request da entrada.
 */
void simulacaoProcessaRequest(int, int, Simulacao*, Hierarquia*);

/**
 * Libera memória e zera contadores utilizados nas simulações.
 */
void simulacaoFree(Simulacao*);

#endif /* SIMULACAO_H_ */
