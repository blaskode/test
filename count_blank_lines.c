
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char ** argv){
  FILE * f = fopen(argv[1], "r");
  int i = 0;
  int blank_lines = 0;
  int c = getc(f);
  while(c != EOF){
    if (c == '\n'){
      i++;
    } else {
      i = 0;
    }
    if (i > 1){
      blank_lines++;
    }
    c = getc(f);
  }
  printf("Blank Lines: %d\n", blank_lines);
  return EXIT_SUCCESS;
}