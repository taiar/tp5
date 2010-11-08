/*
 * camadas.c
 *
 *  Created on: 08/11/2010
 *      Author: taiar
 */

#include "camadas.h"

void iniciaCamada(char *pol, int cap, int vel, Camada *cam)
{
  int i;
  strcpy(cam->politica, pol);
  cam->capacidade = cap;
  cam->velocidade = vel;
  cam->memoria = (int*) malloc(sizeof(int) * cam->capacidade);
  for (i = 0; i < cam->capacidade; i += 1)
    cam->memoria[i] = -1;
}

void hierarquiaConstroi(int n, Camada *c)
{
  char cTipo[5];
  int i, cCapacidade, cVelocidade;
  // Lê e inicializa vetor de camadas
  c = (Camada*) malloc(sizeof(Camada) * (n + 1));
  for (i = 1; i < (n + 1); i += 1)
  {
    scanf("%d %d %s", &cCapacidade, &cVelocidade, cTipo);
    iniciaCamada(cTipo, cCapacidade, cVelocidade, &c[i]);
  }
  // Lê e inicializa camada 0
  scanf("%d", &cCapacidade);
  iniciaCamada("none", cCapacidade, 10000, &c[0]);
  printf("Fim das leituras das camadas\n");
}

void hierarquiaImprime(int n, Camada *c)
{
  int i;
  printf("| ID\t | POLITICA\t| CAPACIDADE\t| VELOCIDADE\t|\n");
  for (i = 0; i < n; i += 1)
  {
    printf("| %d\t| %s\t| %d\t| %d\t|\n", i, c[i].politica, c[i].capacidade,
        c[i].velocidade);
  }
}
