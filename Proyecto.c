#include <stdio.h>

#define beb 8
#define pueb 100

int arr[beb][pueb];
int lit;

int sum[8];
int mayor = 0;
int bebida;

int alc[8];
int alcohol;

void matriz() //Llenado de las matrices con 0's
{
  int i, j;

  for(i = 0; i < 8; i++)
    {
      for(j = 0; j < 100; j++)
        {
          arr[i][j] = 0;
        }
    }
}

void llenado() //Inciso 1
{
  for(j = 0; j < 100; j++)
    {
      do
        {
          printf("ingrese el número de bebida del pueblo %d. \nSi ya no va a registrar más datos de bebidas, ingrese "-1".", j + 1);
          scanf("%d", &i);
          
          if(i != -1)
            {
              printf("Ingrese la cantidad de litros consumidos de la bebida %d.", i);
              scanf("%d", &lit);
              arr[i][j] = lit;
            }
        }
      while(i != -1)
    }
}

void mayor() //Inciso 2
{
  for(i = 0; i < 8; i++)
    {
      sum[i] = 0;
    }
  
  for(i = 0; i < 8; i++)
    {
      for(j = 0; j < 100; j++)
        {
          sum[i] = sum[i] + arr[i][j];
        }
    }
  
  for(i = 0; i < 8; i++)
    {
      if(mayor < sum[i])
        {
          mayor = sum[i];
          bebida = i;
        }
    }
  printf("La bebida más consumida fue la bebida %d, con %d litros consumidos al año.", bebida, mayor); 
}

void alcohol() //Inciso 3-a
{
  for(i = 0; i < 8; i++)
    {
      
    }
}

void borrachos() //Inciso 3-b
{
}
