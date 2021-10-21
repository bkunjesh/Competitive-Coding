#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* head=NULL;
void insert(int data)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		struct node* temp1=head;
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		temp1->next=temp;
	}
}
void print(struct node* head)
{
	struct node* temp=head;
	if(head==NULL)
	return;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
}
struct node* reverse(struct node* head)
{
	node* cur=head;
	node* pre=NULL;
	node* nxt;
	while(cur!=NULL)
    {
    	nxt=cur->next;
	    cur->next=pre;
	    pre=cur;
	    cur=nxt;
    }
    head=pre;
    return head;
}
int main()
{
	 head=NULL;
	insert(2);
	insert(3);
	insert(6);
	insert(5);
	insert(7);
	print(head);
	head=reverse(head);
	printf("\n");
	print(head);
}
