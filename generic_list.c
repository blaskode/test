#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define TRUE 1;
#define FALSE 0;
#define DefCell(EltType, CellType, ListType)\
	typedef struct CellType *ListType;\
		struct CellType {\
		EltType element;\
		ListType next;\
}\

int isInOrder(struct CELL cell, int bool){
	if(cell.next == NULL){
		return bool;
	} else if (c.element > c.next.element){
		return FALSE;
	} else {
		isInOrder(c, TRUE);
	}
}

int isFirst(char a, char b){
	if ( (int) tolower(a) < (int) tolower(b) ) {
		return TRUE;
	} else {
		return FALSE;
	}
}

int main(void){
	/* Create CELLs */
	DefCell(char, CELL, LIST);
	struct CELL a;
	a.element = 'a';
	struct CELL b;
	b.element = 'b';
	struct CELL c;
	c.element = 'c';

	/* link CELLs */
	a.next = &b;
	b.next = &c;
	c.next = NULL;
}




