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

int main(void){
	struct CharNode * node1 = initialize_node('a', NULL);
	struct CharNode * head = initialize_node('D', node1);
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

void delete_list(link head) {
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