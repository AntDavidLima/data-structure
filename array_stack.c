#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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


int main()
{
  int value;
  struct Stack stack;
  int capacity;
  printf("Stack capacity:\n");
  scanf("%i", &capacity);

  createStack(&stack, capacity);

  int option;

  printf("1 - empty\n2 - full\n3 - push\n4 - pop\n0 - quit\n");
  scanf("%i", &option);

  while (option != 0)
  {
    switch (option)
    {
    case 1:
      if (isEmpty(&stack))
      {
        printf("The stack is empty\n");
      }
      else
      {
        printf("The stack is not empty\n");
      }
      break;
    case 2:
      if (isFull(&stack))
      {
        printf("The stack is full\n");
      }
      else
      {
        printf("The stack is not full\n");
      }
      break;
    case 3:
      printf("Value to push: ");
      printf("\n");
      scanf("%i", &value);
      if (push(&stack, value))
      {
        printf("Pushed %i into the stack\n", value);
      }
      else
      {
        printf("Cant push, the stack is full\n");
      }
      break;
    case 4:
      value = pop(&stack);
      if (value != INT_MAX)
      {
        printf("Poped %i from the stack\n", value);
      }
      else
      {
        printf("Cant pop, the stack is empty\n");
      }
      break;
    default:
      printf("Invalid option\n");
      break;
    }
    printf("1 - empty\n2 - full\n3 - push\n4 - pop\n0 - quit\n");
    scanf("%i", &option);
  }
  

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
  if (isEmpty(p))
  {
    return INT_MAX;
  }
  p->top--;
  return p->elements[p->top + 1];
}