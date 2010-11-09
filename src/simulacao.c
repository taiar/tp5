/*
 * simulacao.c
 *
 *  Created on: 08/11/2010
 *      Author: taiar
 */

#include "simulacao.h"

void
simulacaoInicia(Simulacao *s, int totalItens, int totalCamadas, int totalReq)
{
  int i;

  s->reqTotal = totalReq;
  s->tempoTotal = 0;

  s->tempos = (int*) malloc(sizeof(int) * totalItens);
  s->frequencias = (int*) malloc(sizeof(int) * totalItens);
  s->hits = (int*) malloc(sizeof(int) * totalCamadas);
  s->misses = (int*) malloc(sizeof(int) * totalCamadas);

  for (i = 0; i < totalItens; i += 1)
  {
    s->tempos[i] = -1;
    s->frequencias[i] = -1;
  }

  for (i = 0; i < totalCamadas; i += 1)
  {
    s->hits[i] = 0;
    s->misses[i] = 0;
  }
}

void
simulacaoExecuta(Hierarquia *h, Simulacao *s)
{
  int i, nRequests;
  int id, tempo;

  scanf("%d", &nRequests);
  // a capacidade da camada 0 equivale aos objetos em memória
  simulacaoInicia(s, h->camadas[0].capacidade, h->nCamadas, nRequests);

  for (i = 0; i < nRequests; i += 1)
  {
    scanf("%d %d", &id, &tempo);
    simulacaoProcessaRequest(id, tempo, s, h);
  }
}

//int
void
simulacaoProcessaRequest(int id, int tempo, Simulacao *s, Hierarquia *h)
{
  int i, findFlag = 0;
  for (i = h->nCamadas - 1; i > 0; i -= 1)
  {
    s->tempoTotal += h->camadas[i].velocidade;
    if (memoriaBuscaAcesso(id, i, h))
    {
      s->hits[i] += 1; // conta hit na camada
      findFlag = 1;
      break;
    }
    else s->misses[i] += 1; // conta miss na camada
  }

  // não encontrou o dado em nenhuma das caches, precisa acessar o nivel 0
  if (!findFlag) s->tempoTotal += h->camadas[0].velocidade;

  /*
   * RECOLOCA OS DADOS DA CACHE
   */

  // grava tempo em o dado foi acessado e sua frequencia de acesso
  s->frequencias[id] += 1;
  s->tempos[id] = tempo;
}

int
memoriaBuscaAcesso(int id, int camada, Hierarquia *h)
{
  int i;
  for (i = 0; i < h->camadas[camada].capacidade; i += 1)
    if (id == h->camadas[camada].memoria[i]) return 1;
  return 0;
}

void
simulacaoImprime(Simulacao *s, Hierarquia *h)
{
  int i;
  for (i = 1; i < h->nCamadas; i += 1)
  {
    printf("Camada %d => Cache Hit Ratio = %f; Cache Miss Ratio = %f\n", i, (float) (s->hits[i] / (s->hits[i]
        + s->misses[i])), (float) (s->misses[i] / (s->hits[i] + s->misses[i])));
  }
  printf("------\n");
  printf("Tempo de resposta médio por requisição = %f T\n", (s->tempoTotal / (float) s->reqTotal));
}

void
simulacaoFree(Simulacao *s)
{
  free(s->frequencias);
  free(s->tempos);
  free(s->hits);
  free(s->misses);
}
