#include <stdlib.h>
#include <stdio.h>


int main(int argc, char** argv){
  int ** matrix;
  int sz;
  sz = atoi(argv[1]);
  matrix = malloc(sz * sizeof(char *));
  int row = 0;
  int col = 0;

  FILE * f = fopen(argv[2], "r");
  int c = getc(f);
  matrix[row][col] = c;
  printf("%d", c);
  col++;
  while(c != EOF){
    matrix[row][col] = c;
    printf("%d", c);
    if (c == '\n'){
      row++;
      col = 0;
    } else {
      col++;
    }
  }
}