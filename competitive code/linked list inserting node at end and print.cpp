#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<bits/stdc++.h>
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
void reverse()
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
    
}
/*struct node* top=NULL;
struct node* push(int x)
{
		node* temp=(node*)malloc(sizeof(node));
		temp->data=x;
		temp->next=top;
		top=temp;		
}
struct node* pop()
{
	top=top->next;
}*/
/*void reversebystack()
{
	stack<node*>s;
	node* temp=head;
	if(temp!=NULL)
	{
	   s.push(temp);
	   temp=temp->next;
    }
    
    temp=s.top();
    head=temp;
    s.pop();
    while(!s.empty())
    {
    	temp->next=s.top();
    	s.pop();
    	temp=temp->next;
	}
	temp->next=NULL;
}*/
int main()
{
	 head=NULL;
	insert(2);
	insert(3);
	insert(6);
	insert(5);
	insert(7);
	print(head);
	reverse();
	printf("\n");
	print(head);
//	reversebystack();
  //  printf("\n");
//	print(head);
	
}
