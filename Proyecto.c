#include <stdio.h>

#define beb 8
#define pueb 100

int i, j;
int arr[beb][pueb];
int lit;

int sum[8];
int mayor = 0;
int bebida;

int alc[8];
int alcohol;
int litros;

int pub[100];
int alcoholismo = 0;
int volumen;

void matriz() //Llenado de las matrices con 0's
{

  for(i = 0; i < 8; i++)
    {
      for(j = 0; j < 100; j++)
        {
          arr[i][j] = 0;
        }
    }
  for(i = 0; i < 8; i++)
    {
      sum[i] = 0;
    }  
}

void llenado() //Inciso 1
{
  for(j = 0; j < 100; j++)
    {
      do
        {
          printf("ingrese el número de bebida del pueblo %d. \nSi ya no va a registrar más datos de bebidas, ingrese -1.\n", j + 1);
          scanf("%d", &i);
          
          if(i != -1)
            {
              printf("Ingrese la cantidad de litros consumidos de la bebida %d.\n", i);
              scanf("%d", &lit);

              if(lit < 0)
                {
                printf("No existen volúmenes negativos xd, intente otra vez.\n");
                }
              else if(lit >= 0)
                {
                arr[i][j] = lit;
                }
            }  
        }
      while(i != -1);
    }
}

void highest() //Inciso 2
{
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

void etanol() //Inciso 3-a
{
  for(i = 0; i < 8; i++)
    {
      if(i != 0 || i != 1 || i != 6)
        {
          if(litros < sum[i])
          {
            litros = sum[i];
            alcohol = i;
          }
        }
    }
  printf("La bebida alcohólica más consumida fue la bebida %d, con %d litros consumidos al año.", alcohol, litros);
}

void borrachos() //Inciso 3-b
{
  for(j = 0; j < 100; j++)
    {
      for(i = 0; i < 8; i++)
        {
          if(i != 0 || i != 1 || i != 6)
            {
              pub[j] = pub[j] + arr[i][j];
            }
        }
    }
  
  for(j = 0; j < 100; j++)
    {
      if(volumen < pub[i])
        {
          volumen = pub[i];
          alcoholismo = i;
        }
    }
  printf("El pueblo %d es el pueblo que consume más alcohol al año, con %d litros consumidos anualmente", alcoholismo, volumen);
}

int main()
{
  matriz();
  llenado();
  printf("\n\n");
  highest();
  printf("\n\n");
  etanol();
  printf("\n\n");
  borrachos();
  return 0;
}
