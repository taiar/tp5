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
  Hierarquia memoria;
  Simulacao simulacao;
  int tFlag = scanf("%d", &nCamadas);
  while (tFlag > 0)
  {
    hierarquiaInicia(nCamadas, &memoria);
    hierarquiaImprime(&memoria);
    simulacaoExecuta(&memoria, &simulacao);
    hierarquiaFree(&memoria);
    tFlag = scanf("%d", &nCamadas);
  }
  return EXIT_SUCCESS;
}
