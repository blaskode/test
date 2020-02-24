#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
  int ** matrix = malloc(2 * sizeof(int *));
  matrix[0] = malloc(2 * sizeof(int));
  matrix[1] = malloc(2 * sizeof(int));

  for(int i = 0; i < 2; i++){
    free(matrix[i]);
  }
  free(matrix);
}