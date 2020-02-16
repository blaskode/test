

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* This does not work */
/*  */
int main(int argc, char ** argv){
	FILE * f;
	f = fopen(argv[1], "r");
	int * c, d; 
	c = &getc(f);
	while(*c != EOF){
		printf("%c", *c);
		c = &getc(f);
	}
	fclose(f);
}