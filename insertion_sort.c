#include <stdio.h>

void insertionSort(int [], int);

int main()
{
  int size;
  printf("Array size: ");
  scanf("%i", &size);

  int array[size];

  printf("Unsorted array:\n");
  for (int i = 0; i < size; i++)
  {
    array[i] = rand() % 100;
    printf("%i ", array[i]);
  }

  printf("\n");

  printf("Sorted array:\n");
  insertionSort(array, size);

  for (int i = 0; i < size; i++)
  {
    printf("%i ", array[i]);
  }

  printf("\n");

  return 0;
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