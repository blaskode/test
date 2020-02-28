#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv){
  int num = 0;
  char str[80] = {0};
  sprintf(str, "outfile%d.txt", num);

  FILE * f_in = fopen(argv[1], "r");
  FILE * f_out = fopen(str, "w");
  
  int c = fgetc(f_in);
  int nl_count = 0;

  while(c != EOF){
    if (c == 10) {
      nl_count ++;
    } else {
      fputc(c, f_out);
      nl_count = 0;
    }
    if (nl_count > 1){
      num++;
      fclose(f_out);
      sprintf(str, "outfile%d.txt", num);
      f_out = fopen(str, "w");
    }
    c = fgetc(f_in);
  }

  fclose(f_out);
  fclose(f_in);

  return EXIT_SUCCESS;
}

