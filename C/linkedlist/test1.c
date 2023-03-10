#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *head;
node* createnode(int data)
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	if(newnode == NULL)
	{
		printf("\nMemory is not available!!");
		return NULL;
	}
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}

void insert_at_beg(int data)
{
	node *newnode;
	newnode=createnode(data);
	newnode->next=head;
	head=newnode;
	printf("\n%d inserted at the head node.",head->data);
}

void insert_in_i(int loc,int data)
{
	if(head==NULL&&loc>1)
	{
		printf("\nInsertior at %d is not possible as there is no elements.",loc);
		return;
	}
	if(loc==1)
	{
		insert_at_beg(data);
		return;
	}
	node *newnode,*temp,*prev;
	int i=0;
	temp=head;
	while(temp->next!=NULL && i<loc-1)
	{
		i++;
		prev=temp;
		temp=temp->next;
	}	
	if(i<loc-1)
	{
		printf("\nInsertion not possible as there are %d elements!",i+1);
		return;
	}
	newnode=createnode(data);
	newnode->next=prev->next;
	prev->next=newnode;
	printf("\n%d inserted at %d",prev->next->data,loc);
	return;
}

void insert_at_end(int data)
{
	node *newnode,*temp;
	temp=head;
	if(temp==NULL)
	{
		insert_at_beg(data);
		return;
	}
	newnode=createnode(data);
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	printf("\n%d insert at the end.",temp->next->data);
}

void printlist()
{
	node *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("\nThe list is empty!!");
		return;
	}
	printf("\nThe list is:");
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		if(temp->next!=NULL)
			printf("-->");
		temp=temp->next;
	}
}

void delete_at_beg()
{
	node *temp;
	if(head==NULL)
	{
		printf("\nEmpty list!");
		return;
	}
	temp=head;
	head=head->next;
	printf("\n%d is deleted.",temp->data);
	free(temp);
	
}

void delete_at_end()
{
	node *temp,*prev;
	if(head==NULL)
	{
		printf("\nList is empty!");
		return;
	}
	temp=head;
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=temp->next;
	printf("\n%d is deleted",temp->data);
	free(temp);
	return;
	
}
void delete_data(int ddata)
{
	node *temp,*dnode,*prev;
	temp=head;
	if(head==NULL)
	{
		printf("\nThe list is empty!");
		return;
	}
	if(head->data==ddata)
	{
		delete_at_beg();
		return;
	}
	while(temp->next!=NULL && temp->data!=ddata)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp->data==ddata)
	{
		prev->next=temp->next;
		printf("\n%d is deleted",temp->data);
		free(temp);
		return;
	}
	else
	{
		printf("\n%d is not found.",ddata);
		return;
	}
}

void delete_loc(int loc)
{
	if(head==NULL)
	{
		printf("\nDeletion not possible as list empty.",loc);
		return;
	}
	if(loc==1)
	{
		delete_at_beg();
		return;
	}
	node *newnode,*temp,*prev;
	int i=0;
	temp=head;
	while(temp->next!=NULL && i<loc-1)
	{
		i++;
		prev=temp;
		temp=temp->next;
	}
	if(i+2<loc)
	{
		printf("\nDeletion not possible as there are %d elements",i+1);
		return;
	}
	if(i+2==loc)
	{
		delete_at_end();
		return;
	}
	prev->next=temp->next;
	printf("\n%d is deleted",temp->data);
	free(temp);
	return;
}


int main()
{
	int loc,ele;
	head=NULL;
	int choice,ch;
	do
	{
		//fflush(stdin);
		scanf("%c",&choice,printf("\nEnter 'I' for insertion\nEnter 'D' for deletion\nEnter 'P' for print list\nEnter choice:"));
		switch(choice)
		{
			case 'I':
				{
					fflush(stdin);
					scanf("%c",&choice,printf("\nEnter 'B' for insertion at begenning\nEnter 'E' for insertion at end.\nEnter'L' for insertion at specific location.\nEnter choice:"));
					switch(choice)
					{
						case 'B':
							{
								scanf("%d",&ele,printf("\nEnter the data to be inserted:"));
								insert_at_beg(ele);
								break;
							}
						case 'E':
							{
								scanf("%d",&ele,printf("\nEnter the data to be inserted:"));
								insert_at_end(ele);
								break;
							}
						case 'L':
							{
								scanf("%d",&ele,printf("\nEnter the data to be inserted:"));
								scanf("%d",&loc,printf("\nEnter the location where to be inserted:"));
								insert_in_i(loc,ele);
								break;
							}
						default:printf("\nWrong input!");
					}
					break;
				}
			case 'D':
				{
					fflush(stdin);
					scanf("%c",&choice,printf("\nEnter 'B' for deletion at begenning\nEnter 'E' for deletion at end.\nEnter 'L' for deletion at specific location.\nEnter 'D' for deletion a specific data.\nEnter choice:"));
					switch(choice)
					{
						case 'B':
							{
								delete_at_beg();
								break;
							}
						case 'E':
							{
								delete_at_end();
								break;
							}
						case 'L':
							{
								scanf("%d",&loc,printf("\nEnter the location where to be deleted:"));
								delete_loc(loc);
								break;
							}
						case 'D':
							{
								scanf("%d",&ele,printf("\nEnter the element to be deleted:"));
								delete_data(ele);
								break;
							}	
						default:printf("\nWrong input!");
					}
					break;
				}
			case 'P':
				{
					printlist();
					break;
				}
			default:printf("\nWrong input!");
		}
		fflush(stdin);
		scanf("%c",&ch,printf("\nEnter 'Y' for continue, others for exit:"));
		
	}while(ch=='y' || ch=='Y');
	return 0;
	
}
