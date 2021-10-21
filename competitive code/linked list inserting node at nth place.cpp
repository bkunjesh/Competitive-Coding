#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* head;
void insert(int data,int n)
{
	node* temp1=(node*)malloc(sizeof(struct node));
	temp1->data=data;
	temp1->next=NULL;
	if(n==1)
	{
		temp1->next=head;
		head=temp1;
		return;
	}
	node* temp2=head;
	for(int i=0;i<n-2;i++)
	{
		temp2=temp2->next;
	}
	temp1->next=temp2->next;
	temp2->next=temp1;
}
void print()
{
	node* temp=head;
	printf("list is: ");
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
main()
{
	head=NULL;
	
	insert(2,1);//2
	insert(3,1);//32
	insert(4,2);//342
	insert(119,4);//3425
	print();
	
}
