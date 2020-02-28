#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_alphabet(int a[]);
void print_all(FILE * f);
void load_alpha(int * alphabet, FILE * f);

int main(int argc, char ** argv){
  int num = 0;
  char str[80] = {0};
  sprintf(str, "outfile%d.txt", num);

  int alphabet[26] = {0};

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
      
      printf("Help!");
      rewind(f_out);
      load_alpha(alphabet, f_out);
      print_alphabet(alphabet);
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

void load_alpha(int * alphabet, FILE * f){
  int c = tolower(fgetc(f));
  while(c != EOF){
    alphabet[c - 97]++;
    c = tolower(fgetc(f));
  }
}

void print_alphabet(int a[]){
  printf("Where's the orchestra?");
  for(int i = 0; i < 26; i++){
    if (a[i] != 0){
    printf("%c : %d\n", i + 97, (int)(a[i]));
    }
  }
}

void print_all(FILE * f){
  int c = fgetc(f);
  while(c != EOF){
    printf("%c", c);
    c = fgetc(f);
  }
}
