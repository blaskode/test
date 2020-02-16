

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/* This does not work */
/* There's no way to check for blank lines! */
int main(int argc, char ** argv){
	FILE * f;
	f = fopen(argv[1], "r");
	int c, d; 
	c = getc(f);
	while(c != EOF){
		d = getc(f);
		if (d == EOF){
			break;
		}
		if (c == '\n'){
			printf("%d", d);
		}
		printf("%c", c);
		printf("%c", d);
		c = getc(f);
	}
	fclose(f);
}