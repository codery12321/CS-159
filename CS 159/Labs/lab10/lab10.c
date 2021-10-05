#include <stdio.h>
#include <math.h>
#define SET 20

//Function Declarations
int getDataLength(int []);
int countEven(int [], int);
void sortEven(int [], int);
void sortSmall(int [], int, int);
void outputSorted(int [], int);
void outputSum(int [], int);

int main()
{
  //Local Declarations
  int len; // the length (size) of the array
  int dataSet[SET] = {-1}; // the array to be operated
  int countE; // the number of even numvers

  //Statements
  len = getDataLength(dataSet);
  countE = countEven(dataSet, len);
  sortEven(dataSet, countE);
  sortSmall(dataSet, countE, len);
  outputSorted(dataSet, len);
  outputSum(dataSet, len);

  return 0;
}

// get input & return the size of the array
int getDataLength(int dataSet[])
{
  int len; //length of array
  int i;
  len = 0;

  printf("Enter up to %d integer values -> ", SET);

  for(i = 0; i < 20; i++)
  {
    scanf("%d", &dataSet[len]);
    len++;
    if(dataSet[i] == -1)
    {
      i = 20;
      len--;
    }
  }

  return (len);
}

//count how many
int countEven(int dataSet[], int len)
{
  int countE;
  int i;

  countE = 0;
  for (i = 0; i < len; i++)
  {
    if (dataSet[i] % 2 == 0 && dataSet[i] != -1)
    {
      countE++;
    }
  }

  return (countE);
}

//sort the even numbers to the left of the array (right will be all odd numbers)
void sortEven(int dataSet[], int bound)
{
  //int bound;
  int i; // for pointer
  int j; // for pointer
  int k; // array index
  int temp; // temporary variable

  for(i = 0; i < bound; i++)
  {
    for(j = i; j < bound; j++)
    {
      if(dataSet[j] % 2 == 1)
      {
        k = bound;
        while(dataSet[k] % 2 == 1)
        {
          k++;
        }
        temp = dataSet[i];
        dataSet[i] = dataSet[k];
        dataSet[k] = temp;
      }
    }
  }

}

//sort the even part and the odd part of the array both from smallest to largest
void sortSmall(int dataSet[], int countE, int len)
{
  int i;
  int j;
  int temp;

  for (i = 0; i < countE - 1; i++)
  {
    for(j = 0; j < countE - 1; j++)
      {
      //if the current element is larger the next element, swap them
        if (dataSet[j] > dataSet[j + 1])
        {
          temp = dataSet[j + 1];
          dataSet[j + 1] = dataSet[j];
          dataSet[j] = temp;
        }
      }
  }

  for (i = countE; i < len - 1; i++)
  {
    for(j = countE; j < len - 1; j++)
      {
      //if the current element is larger the next element, swap them
        if (dataSet[j] > dataSet[j + 1])
        {
          temp = dataSet[j + 1];
          dataSet[j + 1] = dataSet[j];
          dataSet[j] = temp;
        }
      }
  }
}

void outputSorted(int dataSet[], int len)
{
  int i; // for pointer

  printf("\nSorted array: ");
  for(i = 0; i < len; i++)
  {
    printf("%d ", dataSet[i]);
  }
}

void outputSum(int dataSet[], int len)
{
  int i; // for pointer
  int sum; // the sum
  int index; // the index to be used

  printf("\nCalculated sum: ");
  sum = 0;
  for(i = 0; i < len; i++)
  {
    index = dataSet[i] % len;
    sum += dataSet[index];
  }
  printf("%d", sum);
}
