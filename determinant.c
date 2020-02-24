#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char ** argv){
  int ** matrix = malloc(2 * sizeof(int *));
  matrix[0] = malloc(2 * sizeof(int));
  matrix[1] = malloc(2 * sizeof(int));

  FILE * f = fopen(argv[1], "r");
  
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
      printf("%d ", e);
      printf("%d %d ", i, j);
      e = getc(f);
      j++;
    }
  }

  fclose(f);

  for(int i = 0; i < 2; i++){
    free(matrix[i]);
  }
  free(matrix);
}