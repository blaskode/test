

#include <stdlib.h>
#include <stdio.h>

typedef struct Node * LIST;

struct Node{
	int num;
	LIST lnk;
};

void print_list(LIST list);
void free_list(LIST list);
LIST add_first_node(struct Node * head, int num_);

int main(void){
	struct Node * head = malloc(sizeof(struct Node));
	head->num = 5;
	head = add_first_node(head, 4);
	head = add_first_node(head, 3);
	print_list(head);
	free_list(head);
}


LIST add_first_node(struct Node * head, int num_){
	struct Node * new_head = malloc(sizeof(struct Node));
	new_head->num = num_;
	new_head->lnk = head;
	return new_head;
}

void print_list(LIST list){
	if (list->lnk == NULL){
		printf("%d \n", list->num);
		return;
	} else {
		printf("%d ", list->num);
		print_list(list->lnk);
	}
}

void free_list(LIST list){
	if (list->lnk == NULL){
		free(list);
		list = NULL;
		return;
	} else {
		free_list(list->lnk);
	}
}