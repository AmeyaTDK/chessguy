#include <stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node* create_node();

void append_node(struct node *head, int data);
//printf("---%s---\n", __func__);

// returns head pointer
struct node* prepend_node(struct node *head, int data);

// returns head pointer
struct node* delete_node(struct node *head, int data);

// pointer to node that contains data
struct node* find_node(struct node* head, int data);

// [1]->[2]->[3]. insert_node(head, 6, 1);
// [1]->[6]->[2]->[3]
// returns head pointer
struct node* insert_node(struct node* head, int data, int pos);

// [1]->[2]
void print_list(struct node* head);

int main()
{
	struct node *head;
	head->data = 0;
	head->next = NULL;

	print_list(head);
	append_node(head, 1); // not working
	print_list(head);
	append_node(head, 2); // working
	print_list(head);
	append_node(head, 3); // working
	print_list(head);
	head = prepend_node(head, 8); // not working
	print_list(head);
	struct node* n = find_node(head, 2); // working
	if (n->data != 2) {
		printf("Incorrect node found!\n");
		return 1;
	}
	else 
		printf("correct node found!\n");
	head = delete_node(head, 3); // working
	print_list(head);
	head = delete_node(head, 8); // not working
	print_list(head);
	head = insert_node(head, 9, 0); // not working
	print_list(head);
	head = insert_node(head, 7, 3); // not working
	print_list(head);
	head = insert_node(head, 6, 5);
	print_list(head);
	printf("\n");
}

struct node* create_node(){

	struct node *newnode = (struct node *)malloc(sizeof(struct node));
//	newnode->data = 0;
//	newnode->next = NULL;

	return newnode;
}

void append_node(struct node *head, int data){
	
	printf("\n--%s--\n",__func__);
	
	struct node *current = head;
	while(current->next != NULL){
		current = current->next;
	}
	struct node *newnode = create_node();
	newnode->data = data;
	newnode->next = NULL;
	
	current->next = newnode;
}

struct node* prepend_node(struct node *head, int data){
	
	printf("\n--%s--\n",__func__);
	
	struct node *newnode = create_node();
	newnode->data = data;
	newnode->next = head;
	
	head = newnode;
	return head;	

}

struct node* delete_node(struct node *head, int data){

	printf("\n--%s--\n",__func__);

	struct node *current = head;
	if(current->data == data)
		head = current->next;
	
	else{
		while((current->next)->data != data)
			current = current->next;
		
			struct node *p = (current->next);
			(current->next) = (current->next)->next ;
			free(p);
	}
	return head;
}

struct node* find_node(struct node* head, int data){
	
	printf("\n--%s--\n",__func__);

	struct node *current = head;
	struct node *p;
	if(current->next == NULL){
		p = current->next;
		return p;
	}
	while((current->next)->data != data){
		current = current->next;
	}
	p = current->next;		
	
	return p;
}

struct node* insert_node(struct node* head, int data, int pos){    

	printf("\n--%s--\n",__func__);

	struct node *current = head;
	int i=0;
	if(pos == 0){
		struct node *newnode = create_node();
		newnode->data = data;	
		newnode->next = current;
		head = newnode;
		return head;
	} 
	while(i != pos-1){
		current = current->next;	
		i++;	
	}
	struct node *newnode = create_node();
	struct node *p = current->next; 
	current->next = newnode; 
	newnode->data = data;
	newnode->next = p;
	return head; 
}	

void print_list(struct node* head){
	

	struct node *current;
	current = head;
	if(current->next == NULL){
		printf("[%d]->",current->data);
		return;
	}
	while(current->next != NULL){
		printf("[%d]->",current->data);
		current = current->next;
	}
	printf("[%d]->",current->data);   
}
	


	















