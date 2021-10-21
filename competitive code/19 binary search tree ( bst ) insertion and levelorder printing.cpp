#include<iostream>
#include<queue>

using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};
node* getnewnode(int data)
{
	node* newnode= new node();
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	
	return newnode;
}
node* insertion(struct node* root,int data)
{
	if(root==NULL)
	{
		root=getnewnode(data);
	}
	else if(data<=root->data)
	{
		root->left=insertion(root->left,data);
	}
	else
	{
		root->right=insertion(root->right,data);
	}
	
	return root;
		
}
void levelorder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	queue <node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* current=q.front();
		cout<<current->data<<" ";
		if(current->left!=NULL)
		{
			q.push(current->left);
		}
		if(current->right!=NULL)
		{
			q.push(current->right);
		}
		q.pop();
	}
}
bool search(node* root,int data)
{
	if(root==NULL)
	return false;
	else if(data==root->data)
	return true;
	else if(data>root->data)
	search(root->right,data);
	else if(data<root->data)
	search(root->left,data);
	
}
int findheight(node* root)
{
	if(root==NULL)
	return -1;
	
	return max(findheight(root->left),findheight(root->right))+1;
}

node* del(node* root,int data)
{
	if(root==NULL)
	return root;
	else if(data>root->data)
	root->right=del(root->right,data);
	else if(data<root->data)
	root->left=del(root->left,data);
	else
	{
		//case 1: no child
		if(root->left==NULL&&root->right==NULL)
		{
			delete root;
			root=NULL;
		}
		//case 2: 1 child
		else if(root->left==NULL)
		{
			struct node* temp=root;
			root=temp->right;
			delete temp;
		}
		else if(root->right==NULL)
		{
			struct node* temp=root;
			root=temp->left;
			delete temp;
		}
		//case 3: 2 child
		else
		{
			struct node* temp=(root->right);
			root->data=temp->data;
			root->right=del(root->right,temp->data);
		}
	}
	return root;
}

int main()
{
	node* root=NULL;
	root=insertion(root,5);
	root=insertion(root,2);
	root=insertion(root,7);
	root=insertion(root,1);
	root=insertion(root,10);
	root=insertion(root,0);
	root=insertion(root,8);
	root=insertion(root,6);
	
	cout<<"levelorder traversal:"<<endl;
	levelorder(root);
	
	root=del(root,0);
	
	cout<<endl<<"levelorder traversal after delete '0' :"<<endl;
	levelorder(root);
	
	cout<<endl<<"height of tree is:"<<findheight(root)<<endl;
	
	int n;
	cin>>n;
	if(search(root,n))
	cout<<"found";
	else
	cout<<"not found";
		
}
