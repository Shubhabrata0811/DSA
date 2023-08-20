#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int data;
	struct node* next;
}node;

//Create a node
node* createnode(int data){
	node* newnode = (node*)malloc(sizeof(node));
	if(newnode==NULL){
		printf("Memory unavailable!\n");
		return NULL;
	}else{
		newnode->data = data;
		newnode->next = NULL;
		return newnode;
	}

}

//Number of nodes in the list

int no_of_nodes(node* head){
	int count = 0;
	while(head!=NULL){
		count++;
		head = head->next;
	}
	return count;
}

//Print the list
void printlist(node* head){
	if(head==NULL){
		printf("\nList is empty!");
	}else{
		printf("\nThe list is:");
		while(head!=NULL){
			printf("%d",head->data);
			head = head->next;
			if(head!=NULL){
				printf("->");
			}
		}
	}
}

//Inserts

//Insert at end
void insert_at_end(node** pointer_head){
	int data;
	scanf("%d",&data,printf("\nEnter the data to be inserted:"));
	node* newnode = createnode(data);
	if(newnode==NULL)
		return;

	if(*pointer_head==NULL){
		*pointer_head = newnode;
	}else{
		node* head = (*pointer_head);
		while(head->next!=NULL){
			head = head->next;
		}
		head->next = newnode;
	}
	printf("\n%d inserted at the end of the list!",newnode->data);
}

//Insert at beginning
void insert_at_beg(node** pointer_head){
	int data;
	scanf("%d",&data,printf("\nEnter the data to be inserted:"));
	node* newnode = createnode(data);
	if(newnode==NULL)
		return;
	newnode->next = (*pointer_head);
	*pointer_head = newnode;
	printf("\n%d inserted at the beginning of the list!",(*pointer_head)->data);

}

//Insert at n-th position if available
void insert_at_n(node** pointer_head, int pos){
	if(pos>no_of_nodes(*pointer_head)+1){
		printf("\nInsertion at %d is not possible!",pos);
		return;
	}
	if(pos==1){
		insert_at_beg(pointer_head);
		return;
	}
	int data;
	scanf("%d",&data,printf("\nEnter the data to be inserted:"));
	node* newnode = createnode(data);
	node temp = *pointer_head;
	int count=1;
	while(count<pos-1){
		temp = temp->next;
		count++;
	}
	newnode->next = temp->next;
	temp->next = newnode;
	printf("\%d inserted at %d.",data,pos);
}

//Insert aftrer x if available



//Insert before x if available


void main(){
	node* head=NULL;
	printlist(head);
	insert_at_beg(&head);
	printlist(head);
	insert_at_end(&head);
	printlist(head);
	insert_at_beg(&head);
	printlist(head);
	insert_at_end(&head);
	printlist(head);
	printf("\nNumber of elements in the list = %d",no_of_nodes(head));
}
