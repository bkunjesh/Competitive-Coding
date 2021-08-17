#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node()
    {
        left = NULL;
        right = NULL;
        data = 0;
    }
    node(int x)
    {
        left = NULL;
        right = NULL;
        data = x;
    }
};

void inorder(node *head)
{
    if (head == NULL)
        return;
    inorder(head->left);
    cout << head->data << " ";
    inorder(head->right);
}

void preorder(node *head)
{
    if (!head)
        return;
    cout << head->data << " ";
    preorder(head->left);
    preorder(head->right);
}
void postorder(node *head)
{
    if (head == NULL)
        return;
    postorder(head->left);
    postorder(head->right);
    cout << head->data << " ";
}

void inorderIt(node *head)
{
    stack<node *> st;
    node *cur = head;
    while (!st.empty() || cur != NULL)
    {
        if (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = st.top();
            st.pop();
            cout << cur->data << " ";
            cur = cur->right;
        }
    }
}

void preorderIt(node *head)
{

    stack<node *> st;
    node *cur = head;
    while (!st.empty() || cur != NULL)
    {
        if (cur != NULL)
        {
            cout << cur->data << " ";
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
    }
}

void preorderIt2(node *head)
{
    stack<node *> st;
    stack<node *> out;
    st.push(head);
    while (!st.empty())
    {
        node *cur = st.top();
        st.pop();
        cout << cur->data << " ";
        if (cur->right)
        {
            st.push(cur->right);
        }
        if (cur->left)
        {
            st.push(cur->left);
        }
    }
}
void postorderIt(node *head)
{
    stack<node *> st;
    stack<node *> out;
    st.push(head);
    while (!st.empty())
    {
        node *cur = st.top();
        st.pop();
        out.push(cur);
        if (cur->left)
        {
            st.push(cur->left);
        }
        if (cur->right)
        {
            st.push(cur->right);
        }
    }
    while (!out.empty())
    {
        cout << out.top()->data << " ";
        out.pop();
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(7);
    root->right = new node(6);
    root->right->right = new node(8);

    preorderIt2(root);
    cout << endl;
    preorderIt(root);

    return 0;
}