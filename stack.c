/*
	This program reverses command-line input. It employs a 
	push-down stack implemented by a linked-list. It takes one
	argument. That argument cannot contain spaces unles the entire
	argument is enclosed in quotes.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct CharNode * link;
struct CharNode {
	char element;
	link next;
};

link initialize_node(char ele, link lnk);
void print_list(link head);
void delete_list(link head);
link push_node(link head, link new_node);
void push(link head, char ele);
link pop(link * head);

int main(int argc, char** argv){
	if(argc != 2){
		fprintf(stderr, "Wrong num of args.\n");
		exit(EXIT_FAILURE);
	}

	int arg_len = 0;
	for(int i = 0; argv[1][i] != '\0'; i++){
		arg_len++;
	}

	struct CharNode * head = initialize_node(argv[1][0], NULL);
	for(int i = 1; i < arg_len; i++){
		push(head, argv[1][i]);
	}

	print_list(head);
	link temp = pop(&head);
	while (temp != NULL){
		printf("%c", temp->element);
		free(temp);
		temp = pop(&head);
	}
	printf("\n");

	//delete_list(head);
	return EXIT_SUCCESS;
}

/* Now, we need a function to create a node */
link initialize_node(char ele, link lnk) {
	link temp_node = malloc(sizeof(struct CharNode));
	temp_node->element = ele;
	temp_node->next = lnk;
	return temp_node;
}

void print_list(link head){
	if (head != NULL) {
		printf("%c", head->element);
		print_list(head->next);
	} else {
		printf("\n");
		return;
	}
}

link push_node(link head, link new_node){
	if (head->next != NULL) {
		push_node(head->next, new_node);
		return NULL;	//this should never be reached
	} else {
		head->next = new_node;
		return new_node;
	}
}

void push(link head, char ele){
	struct CharNode * temp = initialize_node(ele, NULL);
	push_node(head, temp);
}

link pop(struct CharNode ** head){
	if (*head == NULL) return NULL;
	if((**head).next == NULL){
		link temp = *head;
		(*head) = NULL;
		return temp;
	} else {
		return pop(&(**head).next);
	}
}

void delete_list(link head) {
	/* There are method calls after the recursive call in */
	/* the first branch... */
	/* So, this is not tail-recursion. */
	//if (head == NULL) return NULL;
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

