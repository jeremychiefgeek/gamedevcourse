#include <stdio.h>
#include <stdlib.h>

#define ACCEPTED_ARGUE_COUNT 4 
#define DIVISION '/'
#define ADDITION '+'
#define SUBTRACTION '-'
#define MULTIPLICATION '*'

void division(int a, int b);
void subtraction(int a, int b);
void addition(int a, int b);
void multiplication(int a, int b);

int main(int argc, char *argv[])
{
  if(argc != ACCEPTED_ARGUE_COUNT) {
    printf("ERROR: This program expects 3 arguments: e.g. calc 4 + 5\n");
    return -1;
  }

  int a, b;
  a = atoi(argv[1]);
  b = atoi(argv[3]);
  char operator = argv[2][0];
  switch(operator)
  {
    case ADDITION:
      addition(a, b);
      break;
    case SUBTRACTION:
      subtraction(a, b);
      break;
    case MULTIPLICATION:
      multiplication(a, b);
      break;
    case DIVISION:
      division(a, b);
      break;
    default:
      printf("Invalid Operator: Error performing the calculator command\n");
      break;
  }
  return 0;
}

void division(int a, int b) 
{
  if(b == 0) 
  {
    printf("You cannot divide by zero.\n");
    return;
  }
  int result = a / b;

  printf("Output: %i\n", result);
}

void multiplication(int a, int b) 
{
  int result = a * b;
  printf("Output: %i\n", result);
}

void addition(int a, int b) 
{
  int sum = a + b;
  printf("Output: %i\n", sum);
}

void subtraction(int a, int b) 
{
  int sum = a - b;
  printf("Output: %i\n", sum);
}
