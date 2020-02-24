#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void read_matrix(FILE * f, int sz, int ** matrix);
int determinant(int ** matrix);
void free_matrix(int ** matrix, int sz);

int main(int argc, char ** argv){
  int ** matrix = malloc(2 * sizeof(int *));
  matrix[0] = malloc(2 * sizeof(int));
  matrix[1] = malloc(2 * sizeof(int));
  FILE * f = fopen(argv[1], "r");
  read_matrix(f, 2, matrix);  
  int det = determinant(matrix);
  printf("Determinant: %d\n", det);
  fclose(f);
  free_matrix(matrix, 2);
}

void free_matrix(int ** matrix, int sz){
  for(int i = 0; i < sz; i++){
    free(matrix[i]);
  }
  free(matrix);
}

void read_matrix(FILE * f, int sz, int ** matrix){
  int e = getc(f);
  int i, j;
  i = j = 0;
  while (e != EOF){
    if (e == 32){ //space
      e = getc(f);
    } else if (e == 10){ //newline
      e = getc(f);
      i++;
      j = 0;
    } else { //data we can use
      e = e - 49;
      matrix[i][j] = e;
      e = getc(f);
      j++;
    }
  }
}

int determinant(int ** matrix){
  int a, b, c, d;
  a = matrix[0][0];
  b = matrix[1][1];
  c = matrix[0][1];
  d = matrix[1][0];
  int det = a*b - c*d;
  return det;
}