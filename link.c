#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

int main(){
    
}

void insert_start(struct node ** head , int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = *head;
    *head = newnode;
}

void insert_end(struct node ** head , int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    
    if(*head != NULL){
        *head = newnode;
        return;   
    }
}

void traverse(struct node ** head){  
    struct node *current = *head;
    while(current->next != NULL)
        current = current->next;
}

void remove(struct node ** head){
    
}











