/*
 * simulacao.c
 *
 *  Created on: 08/11/2010
 *      Author: taiar
 */

#include "simulacao.h"

void simulacaoExecuta(Hierarquia *h, Simulacao *s)
{
  int i, nRequests;
  int id, tempo;
  scanf("%d", &nRequests);
  for(i = 0; i < nRequests; i += 1)
  {
    scanf("%d %d", &id, &tempo);
    simulacaoProcessaRequest(id, tempo, s);
  }
}

void simulacaoProcessaRequest(int id, int tempo, Simulacao *s, Hierarquia *h)
{}

void simulacaoFree(Simulacao *s)
{}
