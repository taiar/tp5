#include "io.h"

void entradaInit(Entrada *entrada)
{
  entrada->iFlag = 0;
  entrada->oFlag = 0;

  entrada->i = NULL;
  entrada->o = NULL;

  entrada->entrada = NULL;
  entrada->saida = NULL;
}

int entradaLe(int argc, char** argv, Entrada *entrada)
{
  entradaInit(entrada);
  int c;
  while ((c = getopt(argc, argv, "i:o:")) != -1)
  {
    switch (c)
    {
      case 'i':
        entrada->iFlag = 1;
        entrada->i = optarg;
        break;
      case 'o':
        entrada->oFlag = 1;
        entrada->o = optarg;
        break;
    }
  }
  if (entrada->iFlag != 1 || entrada->oFlag != 1)
  {
    printf("Parâmetros não foram passados corretamente na linha de comando:\n");
    printf("%s -i <arquivo de entrada> -o <arquivo de saída>\n", argv[0]);
    return 0;
  }

  entrada->entrada = fopen(entrada->i, "r");
  if (!entrada->entrada)
  {
    printf("O arquivo de entrada não está correto.\n");
    return 0;
  }

  entrada->saida = fopen(entrada->o, "w");
  if(!entrada->saida)
  {
    printf("Não foi possível criar o arquivo de saída.\n");
    return 0;
  }
  return 1;
}

void entradaFree(Entrada *entrada)
{
  fclose(entrada->entrada);
  fclose(entrada->saida);
}
