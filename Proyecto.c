#include <stdio.h>

#define beb 8
#define pueb 100

int i, j;
int arr[beb][pueb];
int lit = 0;

int sum[8];
int mayor = 0;
int bebida = 0;

int alc[8];
int alcohol = 0;
int litros = 0;

int pub[100];
int alcoholismo = 0;
int volumen = 0;

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
          printf("Ingrese el número de bebida del pueblo %d. \nSi ya no va a registrar más datos de bebidas, ingrese -1.\n", j + 1);
          scanf("%d", &i);

          if(i != -1)
                {
                  if(i >= 0 && i <=7 )
                    {
                      printf("Ingrese la cantidad de litros consumidos de la bebida %d.\n", i);
                      scanf("%d", &lit);
                      printf("\n");
  
                      if(lit < 0)
                        {
                          printf("No existen volúmenes negativos xd, intente otra vez.\n\n");
                        }
                      else if(lit >= 0)
                        {
                          arr[i][j] = lit;
                        }
                    }
                  else if(i > 7 || i < 0)
                  {
                    printf("Inválido, el número de bebida debe ser un valor entre 0 y 7.\n\n");
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
  printf("La bebida más consumida fue la bebida %d, con %d litros consumidos analmente.", bebida, mayor); 
}

void etanol() //Inciso 3-a
{
  for(i = 0; i < 8; i++)
    {
      if(i != 0 && i != 1 && i != 6)
        {
          if(litros < sum[i])
          {
            litros = sum[i];
            alcohol = i;
          }
        }
    }
  printf("La bebida alcohólica más consumida fue la bebida %d, con %d litros consumidos analmente.", alcohol, litros);
}

void borrachos() //Inciso 3-b
{
  for(j = 0; j < 100; j++)
    {
      for(i = 0; i < 8; i++)
        {
          if(i != 0 && i != 1 && i != 6)
            {
              pub[j] = pub[j] + arr[i][j];
            }
        }
    }
  
  for(j = 0; j < 100; j++)
    {
      if(volumen < pub[j])
        {
          volumen = pub[j];
          alcoholismo = j;
        }
    }
  printf("El pueblo %d es el pueblo que consume más bebidas alcohólicas al año, con %d litros consumidos analmente.", alcoholismo + 1, volumen);
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
  printf("\n:)");
  return 0;
}
