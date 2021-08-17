// C++ program to find maximum sum in Binary Tree
// such that no two nodes are adjacent.
#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* left, *right;
	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

pair<int,int> maxSumHelper(Node* root)
{
    if(!root)
    {
        return make_pair(0, 0);
    }
    auto p1 = maxSumHelper(root->left);
    auto p2 = maxSumHelper(root->right);
    pair<int, int> cur;
    cur.first = p1.second + p2.second + root->data;
    cur.second = max(p1.first, p1.second) + max(p2.first, p2.second);
    return cur;
}

int maxSum(Node *root)
{
	pair<int, int> res = maxSumHelper(root);
	return max(res.first, res.second);
}

// Driver code
int main()
{
	Node *root= new Node(10);
	root->left= new Node(1);
	root->left->left= new Node(2);
	root->left->left->left= new Node(1);
	root->left->right= new Node(3);
	root->left->right->left= new Node(4);
	root->left->right->right= new Node(5);
	cout << maxSum(root);
	return 0;
}
