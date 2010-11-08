/*
 * tp5.c
 *
 *  Created on: 08/11/2010
 *      Author: taiar
 */

#include <stdio.h>
#include <stdlib.h>

#include "io.h"

int main(int argc, char **argv)
{
  int r_flag, tst_counter = 0;
  int n_camadas;
  int i;
  char c_name[5];
  int c_size, c_vel;
  int cam0size;
  int n_req;
  int req_id, req_tempo;
  r_flag = scanf("%d", &n_camadas);
  while (r_flag > 0)
  {
    tst_counter += 1;
    printf("################## TESTE %d #############################\n", tst_counter);
    printf("Sao %d camadas.\n", n_camadas);

    for (i = 0; i < n_camadas; i += 1)
    {
      scanf("%d %d %s", &c_size, &c_vel, c_name);
      printf(
          "Camada numero %d:\n---\nTipo: %s\nCapacidade: %d\nVelocidade: %d\n\n",
          i + 1, c_name, c_size, c_vel);
    }

    scanf("%d", &cam0size);
    printf("A camada 0 tera capacidade de %d!\n", cam0size);
    printf("Tudo ok.... Agora às requisições!!!\n");
    scanf("%d", &n_req);
    for (i = 0; i < n_req; i += 1)
    {
      scanf("%d %d", &req_id, &req_tempo);
      printf("%d -> %d %d\n", i + 1, req_id, req_tempo);
    }

    printf("Fim de jogo...\n");
    r_flag = scanf("%d", &n_camadas);
  }

  return EXIT_SUCCESS;
}
