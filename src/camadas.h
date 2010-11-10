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

/**
 * Estrutura que contém dados de uma camada de memória.
 */
typedef struct
{
  char politica[5];
  int capacidade;
  int velocidade;
  int ocupacao;
  int *memoria;
} Camada;

/**
 * Estrutura que contém dados de uma hierarquia de memória.
 */
typedef struct
{
  Camada *camadas;
  int nCamadas;
} Hierarquia;

/**
 * Inicia uma camada de memória setando suas propriedades.
 */
void camadaInicia(char*, int, int, Camada*);

/**
 * Constrói uma hierarquia de camadas de memória.
 */
Camada* hierarquiaConstroi(int);

/**
 * Formaliza a construção da hierarquia de memória.
 */
void hierarquiaInicia(int, Hierarquia*);

/**
 * Imprime as camadas de uma hierarquia (para testes).
 */
void hierarquiaImprime(Hierarquia*);

/**
 * Libera memória utilizada pela estrutura que simula a hierarquia.
 */
void hierarquiaFree(Hierarquia*);

#define CAMADAS_H_

#endif /* CAMADAS_H_ */
