#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

#define MAX 256
#define MAX_WORD_LEN 1000

class Node
{
	public:
	 char data;
	 unordered_map<char, Node*> children;
	 bool terminal;
	 int freq;
	 
	 //constructor
	 Node(char c)
	 {
	 	data=c;
	 	terminal=false;
	 	freq=0;
	 }
};

class Trie
{	
	public:
     Node *root;

	 Trie()
	 {
	 	root=new Node('\0');
	 }
	 
	 void insert(string str)
	 {
	 	Node *temp=root;
	 	for(int i=0; i<str.length(); i++)
	 	{
	 		char ch=str[i];
	 		if(temp->children.count(ch))
	 		{
	 			temp->freq++;
	 			temp=temp->children[ch];
	 		}	 		
	 		else
	 		{
	 			Node *n=new Node(ch);
	 			n->freq++;
	 			temp->children[ch]=n;
	 			temp=n;
	 		}
	 	}
	 	
	 	temp->terminal=true;
	 }
};

void shortestUniquePrefixUtil(Node *root, char prefix[], int ind, Node *head)
{
	//base condition(s)
	if(root==nullptr)
	   return;
	   
	if(root->freq==1)
	{
        prefix[ind]='\0';
		cout<<prefix<<" ";
		return;
	}
	
	for(auto it=root->children.begin(); it!=root->children.end(); it++)
	{
		
			prefix[ind]=it->first;
			shortestUniquePrefixUtil(root->children[it->first], prefix, ind+1, head);
		
	}
}

void shortestUniquePrefix(string arr[], int n)
{
	Trie t;
	for(int i=0; i<n; i++)
	   t.insert(arr[i]);
	   
	char prefix[MAX_WORD_LEN];
	shortestUniquePrefixUtil(t.root, prefix, 0, t.root);
}

int main()
{
	string arr[]={"zebra", "dog", "duck", "dove"};
	int n = sizeof(arr)/sizeof(arr[0]);
	shortestUniquePrefix(arr, n);
}