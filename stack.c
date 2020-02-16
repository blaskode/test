#include <stdlib.h>
#include <stdio.h>

typedef struct CharNode * link;
struct CharNode {
	char element;
	link next;
};

link initialize_node(char ele, link lnk);
void print_list(link head);
void delete_list(link head);
link push(link head, link new_node);

int main(void){
	struct CharNode * node1 = initialize_node('a', NULL);
	struct CharNode * head = initialize_node('D', node1);
	struct CharNode * tail = initialize_node('m', NULL);
	push(head, tail);
	print_list(head);
	delete_list(head);
	return EXIT_SUCCESS;
}

/* Now, we need a function to create a node */
link initialize_node(char ele, link lnk) {
	link temp_node = malloc(sizeof(struct CharNode));
	temp_node->element = ele;
	temp_node->next = lnk;
	return temp_node;
}

void print_list(link head) {
	if (head != NULL) {
		printf("%c", head->element);
		print_list(head->next);
	} else {
		printf("\n");
		return;
	}
}

link push(link head, link new_node) {
	if (head->next != NULL) {
		push(head->next, new_node);
		return NULL;	//this should never be reached
	} else {
		head->next = new_node;
		return new_node;
	}
}

void delete_list(link head) {
	/* There are method calls after the recursive call in */
	/* the first branch... */
	/* So, this is not tail-recursion. */
	if (head->next != NULL) {
		delete_list(head->next);
		free(head);
		head = NULL;
		return;
	} else {
		free(head);
		head = NULL;
		return;
	}
}