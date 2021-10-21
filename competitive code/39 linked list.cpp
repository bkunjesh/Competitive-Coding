#include<stdio.h> 
#include<stdlib.h> 
#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
#define ll long long
//#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
struct node
{
	int data;
	node* next;
};
struct node* root=NULL;

node* getnewnode(int data)
{
	node* newnode=new node();
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}
node* insert(node* root,int data)
{
	if(root==NULL)
	root=getnewnode(data);
	else
	root->next=insert(root->next,data);
	return root;
}
node* reverse(node* root)
{
	if(root==NULL)
	return root;
	else if(root->next==NULL)
	return root;
	else
	{
		node* p;
	    p=root;
	    node *c= p->next;
	    p->next=NULL;	    
	    while(c!=NULL)
	    {
	    	node* n=c->next;
	    	c->next=p;
	    	p=c;
	    	c=n;
		}
		root=p;		
	}
	return root;
}
void display(node* root)
{
	if(root==NULL)
	{
		cout<<endl;
		return;
    }
	else
	{
		cout<<root->data;
		display(root->next);
	}
}
node* add_no(node* root,int carry)
{
	if(carry==0&&root==NULL)
	return root;
	else if(root==NULL&&carry!=0)
	{
		root=getnewnode(carry%10);
		carry=carry/10;
		root->next=add_no(root->next,carry);
	}
	else if(carry!=0)
	{
		int temp=root->data;
	    root->data=(carry+root->data)%10;
	    carry=(carry+temp)/10;
	    root->next=add_no(root->next,carry);
	}
	return root;	
}
node* delete_N_node_after_M_nodes(node* root,int m,int n)
{
	if(root==NULL)
	return root;
	else
	{
		node* temp1=root;
		node* temp2;
	    	
    	for(int i=1;i<m&&temp1!=NULL;i++)
	    temp1=temp1->next;
	    temp2=temp1;
		//cout<<temp2->data<<" ";	    
	    for(int i=m;i<m+n && temp2!=NULL;i++)
	    {
		    node* t=temp2;
			temp2=temp2->next;
			//cout<<temp2->data<<" "<<endl;
			if(i<m+n-1)
		    free(t);		    	
	    }
	    if(temp2==NULL)
	    temp1->next=NULL;
	    else
	    temp1->next=temp2->next;
	    temp1->next=delete_N_node_after_M_nodes(temp1->next,m,n);			
	}	
   return root;
}
node* rearrangeoddeven(node * root)
{
	node* even=root;
	if(root==NULL)
	return root;
	node* odd=even->next;
	node* temp=even->next;
	while(even->next!=NULL)
	{
		node* temp=even->next;
		even->next=temp->next;
		if(temp->next==NULL)
		break;
		temp->next=temp->next->next;
		even=even->next;
	}
	even->next=odd;
	return root;
}
bool loopdetection(node* root)
{
	node* Fast=root;
	node* slow=root;
	while(slow&&Fast&&Fast->next)
	{
		slow=slow->next;
		Fast=Fast->next->next;
		if(slow==Fast)
		return true;
	}
	return false;
}

int main()
{
	{		
     	root=insert(root,1);
    	insert(root,2);
    	insert(root,3);
	    insert(root,4);
	    //root->next->next->next=root->next->next;    //}
	    insert(root,5);
	    insert(root,6);
	    insert(root,7);
	    insert(root,8);
	    insert(root,8);
	    display(root);
	}
	
	//add 1 to no. represented as linked list
	{	
	    root=reverse(root);
	    display(root);
		//root=add_no(root,1);
	    root=reverse(root);
        display(root);
        insert(root,10);
	    display(root);
	}
	
	//delete N nodes affter M nodes of linked list
	{
		root=delete_N_node_after_M_nodes(root,1,1);
	    display(root);
	}
	
	//rearrange odd and even nodes
	{
		root=rearrangeoddeven(root);
		display(root);
	}
	
	/*//loop detection fast and slow pointer methode
	{
		if(loopdetection(root))
		cout<<"there is looooop!!!"<<endl;
		else
		cout<<"there is no loooop!!!"<<endl;
	}*/
	
	return 0;    
}
