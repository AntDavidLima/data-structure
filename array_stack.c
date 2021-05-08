#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack
{
  int top;
  int capacity;
  int *elements;
};

void createStack(struct Stack *, int);
bool isEmpty(struct Stack *);
bool isFull(struct Stack *);
bool push(struct Stack *, int);
int pop(struct Stack *);


int main(int argc, char const *argv[])
{
  struct Stack stack;
  int capacity;
  printf("Stack capacity:\n");
  scanf("%i", &capacity);

  createStack(&stack, capacity);

  if(push(&stack, 50))
  {
    printf("Pushed\n");
  }
  else
  {
    printf("Error\n");
  }

  int value = pop(&stack);
  printf("%i\n", value);

  return 0;
}

bool isEmpty(struct Stack *p)
{
  if (p->top < 0)
  {
    return true;
  }
  return false;
}

bool isFull(struct Stack *p)
{
  if (p->top >= p->capacity - 1)
  {
    return true;
  }
  return false;
}

void createStack(struct Stack *p, int capacity)
{
  p->capacity = capacity;
  p->top = -1;
  p->elements = (int *) malloc(capacity * sizeof(int));
}

bool push(struct Stack *p, int x)
{
  if (isFull(p))
  {
    return false;
  }
  p->top++;
  p->elements[p->top] = x;
  return true;
}

int pop(struct Stack *p)
{
  if(isEmpty(p))
  {
    abort();
  }
  p->top--;
  return p->elements[p->top + 1];
}