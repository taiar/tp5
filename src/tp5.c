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
  int nCamadas; // número de camadas de cada hierarquia de memória
  Hierarquia memoria; // estrutura que contém a hierarquia de memória a ser simulada
  Simulacao simulacao; // estrutura que guarda os resultados da simulação

  int tFlag = scanf("%d", &nCamadas);
  while (tFlag > 0)
  {
    // Inicia hierarquia de memória
    hierarquiaInicia(nCamadas, &memoria);

    // Executa simulações
    simulacaoExecuta(&memoria, &simulacao);

    // Libera memória utilizada e zera contadores
    hierarquiaFree(&memoria);
    simulacaoFree(&simulacao);

    // Lê se existem mais teste
    tFlag = scanf("%d", &nCamadas);
  }
  return EXIT_SUCCESS;
}
