#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

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
int dequeue(struct Queue *);

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

  printf("Value to enqueue: ");
  printf("\n");
  scanf("%i", &value);

  enqueue(&queue, value);

  printf("%i\n", dequeue(&queue));
  printf("%i\n", dequeue(&queue));
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

int dequeue(struct Queue *p)
{
  if(emptyQueue(&p))
  {
    return INT_MAX;
  }
  int value = p->elements[p->first];
  if(p->first == p->capacity){
    p->first = 0;
  }
  else
  {
    p->first++;
  }
  return value;
}