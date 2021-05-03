#define TRUE 1
#define FALSE 0

#include <stdio.h>

int isEmpty(int);
int isFull(int, int);

int main(int argc, char const *argv[])
{
  int capacity;
  printf("Stack capacity:\n");
  scanf("%i", &capacity);

  int stack[capacity];
  int top = 0;

  return 0;
}

int isEmpty(int top)
{
  if (top < 0)
  {
    return TRUE;
  }
  return FALSE;
}

int isFull(int top, int capacity)
{
  if (top >= capacity - 1)
  {
    return TRUE;
  }
  return FALSE;
}