#include<bits/stdc++.h>
using namespace std;


class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

class BST
{

public:
	Node * root = NULL;

	Node* insert(Node * ptr , int value)
	{
		if (ptr == NULL)
		{
			return new Node (value);
		}

		if (value > ptr->data)
		{
			ptr->right = insert(ptr->right, value);
		}
		else {
			ptr->left = insert(ptr->left, value);
		}
		return ptr;
	}

	void inorder(Node * a)
	{
		if (a == NULL) return ;

		inorder(a->left);
		cout << a->data << " ";
		inorder(a->right);
	}
	void inorderite(Node* ptr)
	{
		stack<Node*> s;
		Node* cur = ptr;
		//s.push(cur);
		while (cur != NULL || s.empty() == false)
		{
			while (cur != NULL)
			{
				s.push(cur);
				cur = cur->left;
			}
			cur = s.top();
			cout << cur->data << " ";
			s.pop();
			cur = (cur->right);
		}
	}
	void preorder(Node * a)
	{
		if (a == NULL) return ;
		cout << a->data << " ";
		preorder(a->left);
		preorder(a->right);
	}
	void preorderitr(Node* ptr)
	{
		stack<Node*> s;
		Node* cur = ptr;
		if (cur == NULL) return ;
		s.push(cur);
		while (!s.empty())
		{
			cur = s.top();
			s.pop();
			cout << cur->data << " ";
			if (cur->right != NULL)
				s.push(cur->right);
			if (cur->left != NULL)
				s.push(cur->left);
		}
	}
	void postorder(Node * a)
	{
		if (a == NULL) return ;
		postorder(a->left);
		postorder(a->right);
		cout << a->data << " ";
	}
	void postorderite(Node* ptr)
	{
		stack<Node*> s1, s2;
		Node* cur = ptr;
		s1.push(cur);
		while (!s1.empty())
		{
			cur = s1.top();
			s1.pop();
			s2.push(cur);

			if (cur->right != NULL)
				s1.push(cur->right);
			if (cur->left != NULL)
				s1.push(cur->left);
		}
		while (!s2.empty())
		{
			cout << s2.top()->data << " ";
			s2.pop();
		}
	}
	void leftview(Node* ptr, int level = 1)
	{
		static int  maxlevel = 0;
		if (ptr == NULL) return;
		if (level > maxlevel)
		{
			cout << ptr->data << " ";
			maxlevel = level;
		}
		//cout << level << " " << maxlevel << endl;
		//level++;
		leftview(ptr->left, level + 1);
		//level++;
		leftview(ptr->right, level + 1);
	}

	Node* minvalnode(Node* ptr)
	{
		while (ptr && ptr->left != NULL) ptr = ptr->left;
		return ptr;
	}

	Node* deletenode(Node* ptr, int val)
	{
		if (ptr->data < val)
		{
			ptr->right = deletenode(ptr->right, val);
		}
		else if (ptr->data > val)
		{
			ptr->left = deletenode(ptr->left, val);
		}
		else
		{
			//if only one child
			if (ptr->left == NULL)
			{
				Node* temp = ptr->right;
				free(ptr);
				return temp;
			}
			else if (ptr->right == NULL)
			{
				Node* temp = ptr->left;
				free(ptr);
				return temp;
			}
			//two child
			Node* temp = minvalnode(ptr->right);
			ptr->data = temp->data;
			ptr->right = deletenode(ptr->right, temp->data);

		}
		return ptr;
	}
	void topview(Node* ptr)
	{
		map<int, int> m;
		queue<pair<Node*, int>> q;
		int hd = 0;
		q.push({ptr, hd});
		while (!q.empty())
		{
			pair<Node*, int> p = q.front();
			ptr = p.first;
			hd = p.second;

			q.pop();
			if (m.count(hd) == 0) m[hd] = ptr->data;

			if (ptr->left != NULL)
			{
				q.push({ptr->left, hd - 1});
			}
			if (ptr->right != NULL)
			{
				q.push({ptr->right, hd + 1});
			}
		}
		for (auto it : m)
		{
			cout << it.second << " ";
		}
	}
	void bottomview(Node* ptr)
	{
		map<int, int> m;
		queue<pair<Node*, int>> q;
		int hd = 0;
		q.push({ptr, hd});
		while (!q.empty())
		{
			pair<Node*, int> p = q.front();
			ptr = p.first;
			hd = p.second;

			q.pop();

			m[hd] = ptr->data;

			if (ptr->left != NULL)
			{
				q.push({ptr->left, hd - 1});
			}
			if (ptr->right != NULL)
			{
				q.push({ptr->right, hd + 1});
			}
		}
		for (auto it : m)
		{
			cout << it.second << " ";
		}
	}
	void spiraltraversal(Node* ptr)
	{
		bool l = 0;
		stack<Node*> s1, s2;
		s1.push(ptr);
		while (!s1.empty() || !s2.empty())
		{
			while (!s1.empty())
			{
				ptr = s1.top();
				cout << ptr->data << " ";
				s1.pop();
				if (ptr->right) s2.push(ptr->right);
				if (ptr->left) s2.push(ptr->left);
			}
			while (!s2.empty())
			{
				ptr = s2.top();
				cout << ptr->data << " ";
				s2.pop();
				if (ptr->left) s1.push(ptr->left);
				if (ptr->right) s1.push(ptr->right);

			}
		}

	}
	int height(Node* ptr)
	{
		if (ptr == NULL) return 0;
		return max(height(ptr->left), height(ptr->right)) + 1;

	}
	int diameter(Node* ptr)
	{
		static int ans = 0;
		if (ptr == NULL) return 0;

		ans = max(ans, (height(ptr->left) + height(ptr->right) + 1));
		return ans;

	}
	Node* LCA(Node* root, int n1, int n2)
	{
		//we have assumed that the keys n1 and n2 are present in Binary Tree
		//otherwise to handle above case
		//have to pass another two flag variable
		//to check wheater n1 or n2 is there or not
		//if not then ideally it should return null
		if (root == NULL) return NULL;

		if (root->data == n1)
			//flag1=1
			return root;
		if (root->data == n2)
			//flag2=1
			return root;

		Node* left = LCA(root->left, n1, n2);
		Node* right = LCA(root->right, n1, n2);

		// If both of the above calls return Non-NULL, then one key
		// is present in once subtree and other is present in other,
		// So this node is the LCA
		if (left && right) return root;
		// Otherwise check if left subtree or right subtree is LCA
		return left != NULL ? left : right;

	}
	bool identicaltrees(Node* root1, Node* root2)
	{
		if (root1 == NULL && root2 == NULL)
			return 1;
		if (root1 != NULL && root2 != NULL)
		{
			return (
			           (root1->data == root2->data) &&
			           identicaltrees(root1->left, root2->left) &&
			           identicaltrees(root1->right, root2->right)
			       );
		}
		return 0;
	}
	int maxsumpath(Node* ptr)
	{
		static int res = INT_MIN;
		if (ptr == NULL) return 0;

		int l = maxsumpath(ptr->left);
		int r = maxsumpath(ptr->right);

		int single_path = max(max(l + ptr->data, r + ptr->data), ptr->data);

		int overall_max = max(single_path, l + r + ptr->data);

		res = max(res, overall_max);

		if (ptr == root) return res;

		return single_path;
	}
	bool is_symmetry(Node* a, Node* b)
	{
		if (a == NULL && b == NULL) return 1;
		if (a && b && a->data == b->data)
			return is_symmetry(a->left, b->right) && is_symmetry(a->right, b->left);
		return 0;
	}
	void flatten(Node* ptr)
	{
		if (ptr == NULL || ptr->left == NULL || ptr->right == NULL) return ;

		if (ptr->left != NULL)
		{
			flatten(ptr->left);

			Node* temp = ptr->right;
			ptr->right = ptr->left;
			ptr->left = NULL;

			Node* t = ptr->right;
			while (t->right != NULL) t = t->right;

			t->right = temp;
		}
		flatten(ptr->right);

	}
	bool bst_search(Node* ptr, int val)
	{
		if (ptr == NULL) return 0;
		if (ptr->data == val) return 1;
		if (val < ptr->data) return bst_search(ptr->left, val);
		else  return bst_search(ptr->right, val);

	}
	bool is_bst(Node* ptr, int min, int max)
	{
		if (ptr == NULL)
		{
			return 1;
		}
		if (ptr->data < min || ptr->data > max) return false;

		return is_bst(ptr->left, min, ptr->data) && is_bst(ptr->right, ptr->data, max);
	}
	void presuc(Node *a , Node * &pre, Node * & suc, int key)
	{

		if (a == NULL) return ;

		if (a->data == key)
		{
			if (a->left != NULL)
			{
				Node * tmp = a->left;

				while (tmp->right != NULL)
				{
					tmp = tmp->right;
				}

				pre = tmp;
			}
			if (a->right != NULL)
			{
				Node * tmp = a->right;
				while (tmp->left != NULL)
				{
					tmp = tmp->left;
				}
				suc = tmp;
			}
			return ;
		}
		if (a->data > key)
		{
			suc = a;
			presuc(a->left, pre, suc, key);
		}
		else {
			pre = a;
			presuc(a->right, pre, suc, key);

		}
	}
	int floor(Node* ptr, int key)
	{
		if (ptr == NULL) return INT_MAX;
		if (ptr->data == key) return key;

		if (ptr->data > key) return floor(ptr->left, key);
		int floorvalue;
		floorvalue = floor(ptr->right, key);

		return (floorvalue <= key) ? floorvalue : ptr->data;

	}
};


int main()
{

	BST b, b1, b2;

	b.root = b.insert(b.root, 20);
	b.root = b.insert(b.root, 8);
	b.root = b.insert(b.root, 22);
	b.root = b.insert(b.root, 5);
	b.root = b.insert(b.root, 3);
	b.root = b.insert(b.root, 4);
	b.root = b.insert(b.root, 25);
	b.root = b.insert(b.root, 10);
	b.root = b.insert(b.root, 14);
	b.inorder(b.root);
	cout << endl;
	b.preorder(b.root);
	cout << endl;
	//b.root = b.deletenode(b.root, 3);
	b.postorder(b.root);
	cout << endl;
	b.leftview(b.root);
	cout << endl;
	b.inorderite(b.root);
	cout << endl;
	b.preorderitr(b.root);
	cout << endl;
	b.postorderite(b.root);
	cout << endl;
	b.topview(b.root);
	cout << endl;
	b.bottomview(b.root);
	cout << endl;
	b.spiraltraversal(b.root);
	cout << endl;
	cout << b.height(b.root) << endl;
	cout << b.diameter(b.root) << endl;
	cout << b.LCA(b.root, 10, 26)->data << endl;
	b1.root = b1.insert(b1.root, 20);
	//b1.root = b1.insert(b1.root, 10);
	b1.root->right = b1.insert(b1.root->right, 10);
	//b1.root = b1.insert(b1.root, 40);
	b1.root->left = b1.insert(b1.root->left, 40);
	b2.root = b2.insert(b2.root, 20);
	b2.root = b2.insert(b2.root, 40);
	b2.root = b2.insert(b2.root, 10);
	cout << b.identicaltrees(b.root, b2.root) << endl;
	cout << b1.identicaltrees(b1.root, b2.root) << endl;
	cout << b.maxsumpath(b.root) << endl;
	cout << b1.is_symmetry(b1.root, b2.root) << endl;
	b1.inorderite(b1.root);
	cout << endl;
	b1.flatten(b1.root);
	b1.inorderite(b1.root);
	cout << endl;
	cout << b.bst_search(b.root, 25) << endl;
	cout << b.is_bst(b.root, INT_MIN, INT_MAX) << endl;
	cout << b.floor(b.root, 11) << endl;
	return 0;

}
