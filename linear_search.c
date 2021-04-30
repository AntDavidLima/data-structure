#include <stdio.h>

void linearSearch(int [], int, int);

int main(int argc, char const *argv[]) {
  int size;
  printf("Array size: ");
  scanf("%i", &size);

  int array[size];

  printf("Array:\n");
  for (int i = 0; i < size; i++) {
    array[i] = rand() % 100;
    printf("%i ", array[i]);
  }
  printf("\n");

  int toFind;
  printf("Value to be searched:\n");
  scanf("%i", &toFind);

  linearSearch(array, size, toFind);
  
  return 0;
}

// A - Array where the value will be searched
// n - Size of the array A
// x - Value to be searched
void linearSearch(int A[], int n, int x)
{
  int i = 0;
  while (i < n && A[i] != x)
  {
    i++;
  }
  if (i == n)
  {
    printf("value not found\n");
  }
  else
  {
    printf("value found in position: %i\n", i);
  }
  
}