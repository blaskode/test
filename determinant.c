#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){
  if (atoi(argv[1]) == 2){
    int ** matrix = malloc(2 * sizeof(int *));
    matrix[0] = malloc(2 * sizeof(int));
    matrix[1] = malloc(2 * sizeof(int));
    FILE * f = fopen(argv[2], "r");
    int c = fgetc(f);
    //c = atoi(c);
    int i, j;
    i = j = 0;
    while(c != EOF){
      if (c == 32) {
        c = fgetc(f);
        continue;
      }
      if (c == '\n'){
        c = c - 48;
        matrix[i][j] = c;
        i++;
        j = 0;
      } else {
        c = c - 48;
        matrix[i][j] = c;
        j++;
      }
      c = fgetc(f);
    }
    int a = matrix[0][0]; 
    int b = matrix[1][1]; 
    int e = matrix[1][0];
    int d = matrix[0][1];
    int det = a * b - e * d;
    printf("Determinant: %d\n", det);

    for(int i = 0; i < 2; i++){
      free(matrix[i]);
    }
    free(matrix);

  } else {
    printf("Wrong size of matrix.\n");
  }

}