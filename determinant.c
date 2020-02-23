#include <stdlib.h>
#include <stdio.h>

int main(void){
  int ** matrix = malloc(3 * sizeof(int *));
  matrix[0] = malloc(3 * sizeof(int));
  matrix[0][0] = 1;
  printf("%d", matrix[0][0]);
}