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
bool fullQueue(struct Queue *);
bool enqueue(struct Queue *, int);

int main(int argc, char const *argv[])
{
  struct Queue queue;
  int capacity;
  int value;

  printf("Queue capacity: ");
  printf("\n");
  scanf("%i", &capacity);

  createQueue(&queue, capacity + 1);

  printf("Value to enqueue: ");
  printf("\n");
  scanf("%i", &value);

  enqueue(&queue, value);

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

bool fullQueue(struct Queue *p)
{
  if((p->last == p->capacity && p->first == 0) || p->last + 1 == p->first)
  {
    return true;
  }
  return false;
}

bool enqueue(struct Queue *p, int x)
{
  if(fullQueue(&p))
  {
    return false;
  }
  p->elements[p->last] = x;
  if(p->last == p->capacity)
  {
    p->last = 0;
  }
  else
  {
    p->last++;
  }
  return true;
}