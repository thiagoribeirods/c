#include <stdio.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
//Mochila
int capacity = 9;
//objetos
int objectWeight[6] = {0, 0, 0, 0, 0};
int objectValue[6] = {0,0,0,0,0};
//valor máximo
int value = 0;
int sumWeights = 0;
//tabela
int table[6][10];
void msg()
{
  printf("\t\t\t Problema da Mochila\n");
}

//ordena pelo peso
void orderByWeight(int * objectsWeight, int * objectsValues)
{
  int aux = 0;
  for(int i = 0; i < 6; i++)
  {
    for(int j = i+1; j < 6; j++)
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

int buildBag(int sumWeights, int capacity, int * objectWeight, int * objectValue, int parcialValue, int object)
{
  if(object > 5)
  {
    return 1;
  }

  if(sumWeights == 0)
  {
    table[object][sumWeights] = 0;
    return buildBag(sumWeights + 1, capacity, objectWeight, objectValue, parcialValue, object);
  }
  else if(sumWeights < capacity)
  {

    if(objectWeight[object] <= sumWeights)
    {
      parcialValue = MAX(table[object - 1][sumWeights], objectValue[object] + table[object - 1][sumWeights - objectWeight[object]]);
      table[object][sumWeights] = parcialValue;
    } 
    else
    {
      table[object][sumWeights] = table[object - 1] [sumWeights];
    }
    return buildBag(sumWeights + 1, capacity, objectWeight, objectValue, parcialValue, object);
    }
  else
  {
    return buildBag(0, capacity, objectWeight, objectValue, parcialValue, object + 1);
  }
}

int main(void) {
  msg();
  objectWeight[1] = 1; //a peso
  objectValue[1] = 1; //a valor

  objectWeight[2] = 3; //b peso
  objectValue[2] = 4; //b valor

  objectWeight[3] = 4; //c peso
  objectValue[3] = 5; //c valor

  objectWeight[4] = 5; //d peso
  objectValue[4] = 7; //d valor

  objectWeight[5] = 2; //e peso
  objectValue[5] = 4; //e valor

  orderByWeight(objectWeight, objectValue);
  buildBag(0, 9 + 1, objectWeight, objectValue, 0, 1);

  for(int i = 0; i < 6; i++)
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
