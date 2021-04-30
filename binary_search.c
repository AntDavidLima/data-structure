#include <stdio.h>

int binarySearch(int [], int, int);

void insertionSort(int [], int);

int main(int argc, char const *argv[])
{
  int size;
  printf("Array size: ");
  scanf("%i", &size);

  int array[size];

  for (int i = 0; i < size; i++)
  {
    array[i] = rand() % 100;
  }

  printf("Array:\n");
  insertionSort(array, size);
  for (int i = 0; i < size; i++)
  {
    printf("%i ", array[i]);
  }
  printf("\n");

  int toFind;
  printf("Value to be searched:\n");
  scanf("%i", &toFind);

  int position = binarySearch(array, size, toFind);

  printf("Value found on position: %i\n", position);

  return 0;
}

// A - Array where the value will be searched
// n - Size of the array A
// x - Value to be searched
int binarySearch(int A[], int n, int x)
{
  int a = 0;
  int b = n;
  while (a < b)
  {
    int meio = (a + b) / 2;
    if (A[meio] == x)
    {
      return meio;
    }
    if (A[meio] < x)
    {
      a = meio + 1;
    }
    else
    {
      b = meio - 1;
    }
  }
  return -1;
}

// A - Array to be sorted
// n - Length of A
void insertionSort(int A[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int current = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > current)
    {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = current;
  }
}