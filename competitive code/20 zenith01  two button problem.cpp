#include<iostream>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;


struct node
{
	int data;
	node* left;
	node* right;
};

node* getnewnode(int data)
{
	node* newnode=new node();
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	return newnode;
}
node* insert(node* root,int data)
{
	if(root==NULL)
	root=getnewnode(data);
	
	else if(data>root->data)
	root->right=insert(root->right,data);
	else
	root->left=insert(root->left,data);
	
	return root;	
}
int levelorder(node* root,int m)
{
	int cnt=0;

	queue <node*> q;
	q.push(root);
	node* current=q.front();
	while(current->data!=m)
	{
		current=q.front();		
		current->left=insert(current->left,(current->data)-1);
		current->right=insert(current->right,(current->data)*2);		
			q.push(current->left);
			q.push(current->right);
		
		cnt++;
		
		q.pop();
		current=q.front();
	}
	cout<<cnt<<endl;
	return log(cnt+1)/log(2);
}
int main()
{
	int n,m;
	cin>>n>>m;
	
	node* root=NULL;
	root=insert(root,n);
	
	cout<<levelorder(root,m);

	
}
