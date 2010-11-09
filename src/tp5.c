/*
 * tp5.c
 *
 *  Created on: 08/11/2010
 *      Author: taiar
 */

#include <stdio.h>
#include <stdlib.h>

#include "camadas.h"
#include "simulacao.h"

int
main(int argc, char **argv)
{
  int nCamadas;
  Camada *hierarquia;
  Simulacao simulacao;
  int tFlag = scanf("%d", &nCamadas);
  while (tFlag > 0)
  {
    hierarquia = hierarquiaConstroi(nCamadas);
    //hierarquiaImprime(nCamadas, hierarquia);
    simulacaoExecuta(hierarquia, &simulacao);
    hierarquiaFree(hierarquia);
    free(hierarquia);
    tFlag = scanf("%d", &nCamadas);
  }
  return EXIT_SUCCESS;
}
