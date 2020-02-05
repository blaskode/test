#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void print_file_contents(FILE * f);
int count_lines(FILE * f);
void print_alphabet_count(int alphabet[]);
int * count_letters(FILE * f);

int main(int argc, char ** argv){
	FILE * f = fopen(argv[1], "r");
	int * alphabet = count_letters(f);
	print_alphabet_count(alphabet);
	free(alphabet);
	fclose(f);
}

void print_file_contents(FILE * f){
	int c = getc(f);
	while(c != EOF){
		printf("%c", c);
		c = getc(f);
	}
}

int count_lines(FILE * f){
	int c = getc(f);
	int i = 0;
	while(c != EOF){
		if (c == 10) i++;
	c = getc(f);
	}
	return i;
}

void print_alphabet_count(int alphabet[]){
		for(int i = 0; i<26; i++){
		printf("%c : %d \n", (i+97), alphabet[i]);
	}
}

int * count_letters(FILE * f){
	int * alphabet = calloc(26, sizeof(int));
	int c = tolower(getc(f));

	while(c != EOF){
		alphabet[c - 97]++;
		c = tolower(getc(f));
	}
	return alphabet;
}



