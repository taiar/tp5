/*
 * tp5.c
 *
 *  Created on: 08/11/2010
 *      Author: taiar
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "camadas.h"
#include "simulacao.h"

int
main(int argc, char **argv)
{
  int nCamadas; // número de camadas de cada hierarquia de memória
  Hierarquia memoria; // estrutura que contém a hierarquia de memória a ser simulada
  Simulacao simulacao; // estrutura que guarda os resultados da simulação

  // Variáveis para medida de tempo de execução
  float tempo_execucao;
  float tempo_usuario;
  float tempo_sistema;
  struct timeval t_inicio;
  struct timeval t_fim;
  struct rusage uso_recursos;
  struct timeval t_usuario;
  struct timeval t_sistema;

  gettimeofday(&t_inicio, NULL);

  int tFlag = scanf("%d", &nCamadas);
  while (tFlag > 0)
  {
    // Inicia hierarquia de memória
    hierarquiaInicia(nCamadas, &memoria);

    // Executa e exibe resultado das simulações
    simulacaoExecuta(&memoria, &simulacao);
    simulacaoImprime(&simulacao, &memoria);

    // Libera memória utilizada e zera contadores
    hierarquiaFree(&memoria);
    simulacaoFree(&simulacao);

    // Lê se existem mais testes
    tFlag = scanf("%d", &nCamadas);
  }

  // Cálculo dos tempos de execução
  gettimeofday(&t_fim, NULL);
  getrusage(RUSAGE_SELF, &uso_recursos);

  t_usuario = uso_recursos.ru_utime;
  t_sistema = uso_recursos.ru_stime;

  tempo_usuario = (float) t_usuario.tv_sec + (float) t_usuario.tv_usec / 1000000;
  tempo_sistema = (float) t_sistema.tv_sec + (float) t_sistema.tv_usec / 1000000;

  tempo_execucao = (t_fim.tv_sec - t_inicio.tv_sec) * 1000000;
  tempo_execucao = (tempo_execucao + (t_fim.tv_usec - t_inicio.tv_usec)) / 1000000;

  printf("tempo de execucao: %f\n", tempo_execucao);
  printf("tempo de usuario: %f\n", tempo_usuario);
  printf("tempo de sistema: %f\n", tempo_sistema);

  return EXIT_SUCCESS;
}
