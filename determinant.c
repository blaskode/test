#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void read_matrix(FILE * f, int sz, int ** matrix);
//int determinant(int ** matrix, int n);
int determinant(int **, int);
void free_matrix(int ** matrix, int sz);

int main(int argc, char ** argv){
  if (argc != 3) {
    fprintf(stderr, "Wrong number of arguments.\n");
    exit(EXIT_FAILURE);
  }
  int n = atoi(argv[2]);
  if (n == 0) {
    fprintf(stderr, "first argument must be valid file name containing matrix.\n");
    fprintf(stderr, "second argument must be size of square matrix.\n");
    exit(EXIT_FAILURE);
  }

  int ** matrix = malloc(n * sizeof(int *));
  for(int i = 0; i < n; i++){
    matrix[i] = malloc(n * sizeof(int));
  }

  FILE * f = fopen(argv[1], "r");
  read_matrix(f, n, matrix);  
  int det = determinant(matrix, n);
  printf("Determinant: %d\n", det);
  fclose(f);
  free_matrix(matrix, n);
}

void free_matrix(int ** matrix, int sz){
  for(int i = 0; i < sz; i++){
    free(matrix[i]);
  }
  free(matrix);
}


void read_matrix(FILE * f, int sz, int ** matrix){
  int n;
  for(int i = 0; i < sz; i++){
    for(int j = 0; j< sz; j++){
      fscanf(f, "%d", &n);
      matrix[i][j] = n;
    }
  }
}

int determinant(int ** matrix, int n){
  int det = 0;
  if (n == 2){
    int a, b, c, d;
    a = matrix[0][0];
    b = matrix[1][1];
    c = matrix[0][1];
    d = matrix[1][0];
    det = a*b - c*d;
  } else if (n == 3){
    int a, b, c, d, e, f, g, h, i;
    a = matrix[0][0];
    b = matrix[0][1];
    c = matrix[0][2];
    d = matrix[1][0];
    e = matrix[1][1];
    f = matrix[1][2];
    g = matrix[2][0];
    h = matrix[2][1];
    i = matrix[2][2];
    det = a*(e*i - f*h) - b*(d*i - f*g) + c*(d*h - e*g);
  }
  return det;
}