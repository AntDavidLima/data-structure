#include <limits.h>
#include <stdio.h>

void mergeSort(int [], int, int);

int main(int argc, char const *argv[])
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
  mergeSort(array, 0, size - 1);

  for (int i = 0; i < size; i++)
  {
    printf("%i ", array[i]);
  }

  printf("\n");
  return 0;
}

void merge(int A[], int p, int q, int r)
{
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1 + 1];
  int R[n2 + 1];

  for (int i = 0; i < n1; i++)
  {
    L[i] = A[p + i];
  }

  for (int i = 0; i < n2; i++)
  {
    R[i] = A[q + i + 1];
  }
  
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  
  int i = 0;
  int j = 0;

  for (int k = p; k < r + 1; k++)
  {
    if (L[i] <= R[j])
    {
      A[k] = L[i];
      i++;
    }
    else
    {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int A[], int p, int r)
{
  if (p < r)
  {
    int q = (p + r) / 2;
    mergeSort(A, p, q);
    mergeSort(A, q + 1, r);
    merge(A, p, q, r);
  }
}