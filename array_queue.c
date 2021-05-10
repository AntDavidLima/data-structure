#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Queue
{
  int first;
  int last;
  int capacity;
  int *elements;
};

void createQueue(struct Queue *, int);

int main(int argc, char const *argv[])
{
  struct Queue queue;
  int capacity;

  printf("Queue capacity: ");
  printf("\n");
  scanf("%i", &capacity);

  createQueue(&queue, capacity + 1);

  printf("First: %i Last: %i Capacity: %i\n", queue.first, queue.last, queue.capacity);

  return 0;
}

void createQueue(struct Queue *p, int c)
{
  p->first = 0;
  p->last = 0;
  p->capacity = c;
  p->elements = (int *) malloc(c * sizeof(int));
}