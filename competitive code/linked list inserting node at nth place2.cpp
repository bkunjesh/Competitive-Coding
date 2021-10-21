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
	printf("LIST is: ");
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
main()
{
	int n,x,i,p;
	head=NULL;
	printf("enter no. of enteries: \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nenter data : \n");
		scanf("%d",&x);
		again:
		printf("enter position :\n");
		scanf("%d",&p);
		if(p>i+1||p<0)
		{
			printf("error\n");
			goto again;
		}
		insert(x,p);
		print();
		
	}
}
