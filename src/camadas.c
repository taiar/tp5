/*
 * camadas.c
 *
 *  Created on: 08/11/2010
 *      Author: taiar
 */

#include "camadas.h"

void
iniciaCamada(char *pol, int cap, int vel, Camada *cam)
{
  int i;
  strcpy(cam->politica, pol);
  cam->capacidade = cap;
  cam->velocidade = vel;
  cam->memoria = (int*) malloc(sizeof(int) * cam->capacidade);
  for (i = 0; i < cam->capacidade; i += 1)
    cam->memoria[i] = -1;
}

Camada*
hierarquiaConstroi(int n)
{
  char cTipo[5];
  int i, cCapacidade, cVelocidade;
  // Lê e inicializa vetor de camadas
  Camada *p = (Camada*) malloc(sizeof(Camada) * (n + 1));
  for (i = 1; i < (n + 1); i += 1)
  {
    scanf("%d %d %s", &cCapacidade, &cVelocidade, cTipo);
    iniciaCamada(cTipo, cCapacidade, cVelocidade, &(p[i]));
  }
  // Lê e inicializa camada 0
  scanf("%d", &cCapacidade);
  iniciaCamada("none", cCapacidade, 10000, &(p[0]));

  return p;
}

void
hierarquiaInicia(int n, Hierarquia *h)
{
  h->nCamadas = n + 1; // incrementa em uma unidade para armazenar a camada zero.
  h->camadas = hierarquiaConstroi(n);
}

void
hierarquiaImprime(Hierarquia *h)
{
  //printf("endereco na memoria: %p\n", (void*)&h->camadas);
  int i;
  printf("+-------+-------+-------+-------+\n");
  printf("| IDS\t| POL\t| CAP\t| VEL\t|\n");
  printf("+-------+-------+-------+-------+\n");
  for (i = 0; i < h->nCamadas; i += 1)
    printf("| %d\t| %s\t| %d\t| %d\t|\n", i, h->camadas[i].politica, h->camadas[i].capacidade, h->camadas[i].velocidade);
  printf("+-------+-------+-------+-------+\n");
}

void
hierarquiaFree(Hierarquia *h)
{
  int i;
  for (i = 0; i < h->nCamadas; i += 1)
    free(h->camadas[i].memoria);
  free(h->camadas);
  h->nCamadas = 0;
}

