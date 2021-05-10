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
bool emptyQueue(struct Queue *);

int main(int argc, char const *argv[])
{
  struct Queue queue;
  int capacity;

  printf("Queue capacity: ");
  printf("\n");
  scanf("%i", &capacity);

  createQueue(&queue, capacity + 1);

  if(emptyQueue(&queue))
  {
    printf("Empty\n");
  }
  else
  {
    printf("Not Empty\n");
  }

  return 0;
}

void createQueue(struct Queue *p, int c)
{
  p->first = 0;
  p->last = 0;
  p->capacity = c;
  p->elements = (int *) malloc(c * sizeof(int));
}

bool emptyQueue(struct Queue *p)
{
  if(p->first == p-> last)
  {
    return true;
  }
  return false;
}