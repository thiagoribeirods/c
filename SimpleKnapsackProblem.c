#include <stdio.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
//Mochila
int capacity = 9;
//objetos
int objectWeight[5] = {0, 0, 0, 0, 0};
int objectValue[5] = {0,0,0,0,0};
//valor máximo
int value = 0;
int sumWeights = 0;
//tabela
int table[5][10];
void msg()
{
  printf("\t\t\t Problema da Mochila\n");
}
//ordena pelo peso
void orderByWeight(int * objectsWeight, int * objectsValues)
{
  int aux = 0;
  for(int i = 0; i < 5; i++)
  {
    for(int j = i+1; j < 5; j++)
    {
      if(objectsWeight[i] > objectsWeight[j])
      {
        aux = objectsWeight[i];
        objectsWeight[i] = objectsWeight[j];
        objectsWeight[j] = aux;
        aux = 0;
        aux = objectsValues[i];
        objectsValues[i] = objectsValues[j];
        objectsValues[j] = aux;  
      }
    }
  }
}
int buildBag(int capacity, int sumWeights, int * objectWeight, int * objectValue)
{
  sumWeights = 0;
  int parcialValue = 0;
  for(int i = 0; i < 5; i++)
  {
    for(int j = 0; j < 10; j++)
    {
      if(objectWeight[i] <= j) //valor = max(valor excluindo novo peso, valor inclundo novo peso)
      {
        if(i == 0)
        {
          parcialValue = MAX(0, objectValue[i] + 0);
          table[i][j] = parcialValue;
        }
        else
        {
          parcialValue = MAX(table[i-1][j], objectValue[i] + table[i-1][j-objectWeight[i]]);
          table[i][j] = parcialValue;
        }
      }
      else //copie o valor da célula acima
      {
        if(j == 0)
        {
          table[i][j] = 0;
        }
        else
        {
          table[i][j] = table[i-1][j];
        }
      }      
    }
  }
  return 0;
}
int main(void) {
  msg();
  objectWeight[0] = 1; //a peso
  objectValue[0] = 1; //a valor
  objectWeight[1] = 3; //b peso
  objectValue[1] = 4; //b valor
  objectWeight[2] = 4; //c peso
  objectValue[2] = 5; //c valor
  objectWeight[3] = 5; //d peso
  objectValue[3] = 7; //d valor
  objectWeight[4] = 2; //e peso
  objectValue[4] = 4; //e valor
  orderByWeight(objectWeight, objectValue);
  buildBag(9, 0, objectWeight, objectValue);
  for(int i = 0; i < 5; i++)
  {
    printf("|  ");
    for(int j = 0; j < 10; j++)
    {
      if(table[i][j] < 10)
        printf("%i   ", table[i][j]);
      else
        printf("%i  ", table[i][j]);
      printf("|  ");
    }
    printf("\n");
  }
  printf("\n\tConclusão");
  printf("\nO máximo valor possível é -> ");
  return 0;
}
