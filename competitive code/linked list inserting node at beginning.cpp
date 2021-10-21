#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};
struct node* head;
void insert(int x)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=x;
	temp->next=head;
	head=temp;
}

int main()
{
	int i,n,x; 
	head=NULL;
	printf("how many no.?\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter a no.\n");
		scanf("%d",&x);
		insert(x);
		
	}
	printf("\nlist is\n");
	struct node* temp=head;
	
	for(i=0;i<n;i++)
	{
		printf("%d",temp->data);
		temp=temp->next;		
	}
}

