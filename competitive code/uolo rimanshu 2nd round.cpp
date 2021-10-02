#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int data)
{
    node *temp = new node();

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

node *constructTreeUtil(vector<int> pre, int *preIndex, int key,
                        int min, int max, int size)
{
    if (*preIndex >= size)
        return NULL;

    node *root = NULL;

    if (key > min && key < max)
    {
        root = newNode(key);
        *preIndex = *preIndex + 1;

        if (*preIndex < size)
        {
            root->left = constructTreeUtil(pre, preIndex,
                                           pre[*preIndex],
                                           min, key, size);
        }
        if (*preIndex < size)
        {
            root->right = constructTreeUtil(pre, preIndex,
                                            pre[*preIndex],
                                            key, max, size);
        }
    }

    return root;
}

node *constructTree(vector<int> pre, int size)
{
    int preIndex = 0;
    return constructTreeUtil(pre, &preIndex, pre[0], INT_MIN, INT_MAX, size);
}

node *lca(node *root, int n1, int n2)
{
    while (root != NULL)
    {
        if (root->data > n1 && root->data > n2)
            root = root->left;

        else if (root->data < n1 && root->data < n2)
            root = root->right;

        else
            break;
    }
    return root;
}

// void printInorder(node *node)
// {
//     if (node == NULL)
//         return;
//     printInorder(node->left);
//     cout << node->data << " ";
//     printInorder(node->right);
// }

string BinarySearchTree(string strArr[], int n)
{
    string s = strArr[0];
    int x = stoi(strArr[1]);
    int y = stoi(strArr[2]);
    int z = 0;
    vector<int> preorder;
    for (int i = 1; s[i] != ']'; i++)
    {
        if (s[i] != ',')
        {
            int temp = s[i] - '0';
            z = z * 10 + temp;
        }
        else
        {
            i++;
            preorder.push_back(z);
            z = 0;
        }
    }
    preorder.push_back(z);
    // for (int i = 0; i < preorder.size(); i++)
    // {
    //     cout << preorder[i] << " ";
    // }
    // cout << "\n";
    // cout << x << " " << y << "\n";

    node *root = constructTree(preorder, preorder.size());

    int val = lca(root, x, y)->data;

    string ans = to_string(val);
    cout << ans << endl;
    return ans;

    // printInorder(root);
}

int main()
{

    string strArr[] = {"[10, 5, 1, 7, 40, 50]", "5", "10"};
    BinarySearchTree(strArr, 3);
}