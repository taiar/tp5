/*
 * simulacao.h
 *
 *  Created on: 08/11/2010
 *      Author: taiar
 */

#ifndef SIMULACAO_H_
#define SIMULACAO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "camadas.h"

/**
 * Estrutura que armazena dados referentes às simulações em memória.
 */
typedef struct
{
  int *tempos; // Lista que contém o último tempo em que o objeto foi acessado.
  int *frequencias; // Lista que contém quantas vezes o objeto foi acessado.
  int *hits; // Armazena o número de hits / camada.
  int *misses; // Armazena o número de misses / camada.
  int reqTotal; // Armazena o total de requests feitos no total.
  float tempoTotal; // Armazena o tempo de resposta total gasto nas camadas.
} Simulacao;

/**
 * Inicia estrutura de simulação.
 */
void simulacaoInicia(Simulacao *s, int, int, int);
/**
 * Executa simulação através dos requests enviados na entrada.
 */
void simulacaoExecuta(Hierarquia*, Simulacao*);

/**
 * Processa individualmente cada request da entrada.
 */
void simulacaoProcessaRequest(int, int, Simulacao*, Hierarquia*);

/**
 * Políticas de cache
 */
void simulacaoLRU(int, int, Simulacao*, Hierarquia*);
void simulacaoLFU(int, int, Simulacao*, Hierarquia*);
void simulacaoMRU(int, int, Simulacao*, Hierarquia*);
void simulacaoFIFO(int, int, Simulacao*, Hierarquia*);

/**
 * Carrega dado encontrado em uma camada em todas as superiores.
 */
void simulacaoCarregaDados(int, int, Simulacao*, Hierarquia*);

/**
 * Verifica se um dado se encontra em um determinado nível da memória.
 */
int memoriaBuscaAcesso(int, int, Hierarquia*);

/**
 * Imprime resultado das simulações.
 */
void simulacaoImprime(Simulacao*, Hierarquia*);

/**
 * Libera memória e zera contadores utilizados nas simulações.
 */
void simulacaoFree(Simulacao*);

/**
 * Exibe o que está na memória em um determinado nível.
 */
void dumpMemory(int, Hierarquia*);

#endif /* SIMULACAO_H_ */
