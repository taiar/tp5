/*
 * simulacao.c
 *
 *  Created on: 08/11/2010
 *      Author: taiar
 */

#include "simulacao.h"

void simulacaoInicia(Simulacao *s, int totalItens, int totalCamadas,
    int totalReq)
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

void simulacaoExecuta(Hierarquia *h, Simulacao *s)
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

void simulacaoProcessaRequest(int id, int tempo, Simulacao *s, Hierarquia *h)
{
  int i, findFlag = 0;
  for (i = h->nCamadas - 1; i > 0; i -= 1)
  {
    s->tempoTotal += h->camadas[i].velocidade;
    if (memoriaBuscaAcesso(id, i, h))
    {
      s->hits[i] += 1; // conta hit na camada
      findFlag = i;
      break;
    }
    else s->misses[i] += 1; // conta miss na camada
  }

  // não encontrou o dado em nenhuma das caches, precisa acessar o nivel 0
  if (findFlag == 0) s->tempoTotal += h->camadas[0].velocidade;

  // carrega os dados na devida camada
  simulacaoCarregaDados(id, findFlag, s, h);

  // grava tempo em o dado foi acessado e sua frequencia de acesso
  s->frequencias[id] += 1;
  s->tempos[id] = tempo;
}

void simulacaoCarregaDados(int id, int camada, Simulacao *s, Hierarquia *h)
{
  int i;
  for (i = camada + 1; i < h->nCamadas; i += 1)
  {
    if (strcmp(h->camadas[i].politica, "lru") == 0) simulacaoLRU(id, i, s, h);
    else if (strcmp(h->camadas[i].politica, "lfu") == 0) simulacaoLFU(id, i, s, h);
    else if (strcmp(h->camadas[i].politica, "mru") == 0) simulacaoMRU(id, i, s, h);
    else if (strcmp(h->camadas[i].politica, "fifo") == 0) simulacaoFIFO(id, i, s, h);
    else
    {
      printf(
          "Tentando acessar camada 0 ou política da camada não reconhecida\n");
      exit(EXIT_FAILURE);
    }
  }
}

/*****************************
 * POLITICAS
 *****************************/
void simulacaoLRU(int id, int camada, Simulacao *s, Hierarquia *h)
{
  int i, guardaPos = 0;
  if (h->camadas[camada].ocupacao < h->camadas[camada].capacidade)
  {
    for (i = 0; i < h->camadas[camada].capacidade; i += 1)
    {
      if (h->camadas[camada].memoria[i] < 0)
      {
        h->camadas[camada].memoria[i] = id;
        h->camadas[camada].ocupacao += 1;
        break;
      }
    }
  }
  else
  {
    for(i = 0; i < h->camadas[camada].capacidade; i += 1)
    {
      if(s->tempos[i] < s->tempos[guardaPos]) // selecionando dado com menor frequencia de acesso
        guardaPos = i;
      else if(s->tempos[i] == s->tempos[guardaPos]) // empate resolvido pelo menor id do dado
        if(i < guardaPos)
          guardaPos = i;
    }
    h->camadas[camada].memoria[guardaPos] = id;
  }
}

void simulacaoLFU(int id, int camada, Simulacao *s, Hierarquia *h)
{
}

void simulacaoMRU(int id, int camada, Simulacao *s, Hierarquia *h)
{
  int i, guardaPos = 0;
  if (h->camadas[camada].ocupacao < h->camadas[camada].capacidade)
  {
    for (i = 0; i < h->camadas[camada].capacidade; i += 1)
    {
      if (h->camadas[camada].memoria[i] < 0)
      {
        h->camadas[camada].memoria[i] = id;
        h->camadas[camada].ocupacao += 1;
        break;
      }
    }
  }
  else
  {
    for(i = 0; i < h->camadas[camada].capacidade; i += 1)
    {
      if(s->tempos[i] > s->tempos[guardaPos]) // selecionando dado com maior frequencia de acesso
        guardaPos = i;
      else if(s->tempos[i] == s->tempos[guardaPos]) // empate resolvido pelo menor id do dado
        if(i < guardaPos)
          guardaPos = i;
    }
    h->camadas[camada].memoria[guardaPos] = id;
  }
}

void simulacaoFIFO(int id, int camada, Simulacao *s, Hierarquia *h)
{
  int i;
  if (h->camadas[camada].ocupacao < h->camadas[camada].capacidade)
  {
    for (i = 0; i < h->camadas[camada].capacidade; i += 1)
    {
      if (h->camadas[camada].memoria[i] < 0)
      {
        h->camadas[camada].memoria[i] = id;
        h->camadas[camada].ocupacao += 1;
        break;
      }
    }
  }
  else
  {
    for (i = 0; i < h->camadas[camada].capacidade - 1; i += 1)
      h->camadas[camada].memoria[i] = h->camadas[camada].memoria[i + 1];
    h->camadas[camada].memoria[h->camadas[camada].capacidade - 1] = id;
  }
}

int memoriaBuscaAcesso(int id, int camada, Hierarquia *h)
{
  int i;
  //printf("Buscando %d:\n", id);
  //dumpMemory(camada, h);
  for (i = 0; i < h->camadas[camada].capacidade; i += 1)
    if (id == h->camadas[camada].memoria[i])
    {
      printf("achei aqui\n");
      return 1;
    }
    else return 0;
  return 0;
}

void simulacaoImprime(Simulacao *s, Hierarquia *h)
{
  //TODO: calculo de miss / hit errados
  int i;
  for (i = 1; i < h->nCamadas; i += 1)
  {
    printf("Camada %d => Cache Hit Ratio = %f; Cache Miss Ratio = %f\n", i,
        (float) (s->hits[i] / (s->hits[i] + s->misses[i])),
        (float) (s->misses[i] / (s->hits[i] + s->misses[i])));
    //printf("Camada %d => Cache Hit Ratio = %d; Cache Miss Ratio = %d\n", i, s->hits[i], s->misses[i]  );
  }
  printf("------\n");
  printf("Tempo de resposta médio por requisição = %f T\n", (s->tempoTotal
      / (float) s->reqTotal));
}

void simulacaoFree(Simulacao *s)
{
  free(s->frequencias);
  free(s->tempos);
  free(s->hits);
  free(s->misses);
}

void dumpMemory(int camada, Hierarquia *h)
{
  int i;
  for (i = 0; i < h->camadas[camada].capacidade; i += 1)
    printf("%d ", h->camadas[camada].memoria[i]);
  printf("\n\n\n");
}
