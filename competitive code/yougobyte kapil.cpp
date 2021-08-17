//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to return LCM of two numbers
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

bool ispermutation(vector<int> a)
{
    set<int> s;
    int i = 1;
    for (i = 1; i <= n; i++)
    {
        s.insert(a[i]);
    }
    if (s.size() == n)
    {
        return 1;
    }
    else
        return 0;
}
void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n + 1), visited(n + 3, 0);

    for (i = 1; i <= n; i++)
        cin >> a[i];

    if (!ispermutation(a))
    {
        cout << -1 << endl;
        return;
    }

    int maxlen = 0, ans = 0;

    for (i = 1; i <= n; i++)
    {
        if (visited[i] || i == a[i])
            continue;

        int len = 1;
        int node = a[i];
        visited[i] = 1;

        while (node != i)
        {
            visited[node] = 1;
            len++;
            node = a[node];
        }
        // maxlen = max(maxlen, len);
        if (ans == 0)
            ans = len;
        else
            ans = lcm(ans, len);
    }
    cout << ans << endl;

    return;
}

signed main()
{
    int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

class LRUCache
{
    class Node
    {
    public:
        int key;
        int value;
        Node *next;
        Node *prev;
        Node(int key, int value)
        {
            this->key = key;
            this->value = value;
            next = NULL;
            prev = NULL;
        }
    };

public:
    int capacity;
    int count;

    unordered_map<int, Node *> temp;
    Node *head;

    Node *tail;

    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {

        capacity = cap;
        count = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
        head->prev = tail->next = NULL;
        // code here
    }
    void addtohead(Node *t)
    {
        t->next = head->next;
        head->next->prev = t;
        t->prev = head;
        head->next = t;
    }
    void deletenode(Node *t)
    {
        t->prev->next = t->next;
        t->next->prev = t->prev;
        delete t;
    }
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if (temp.count(key) > 0)

        {
            Node *t = temp[key];
            int result = t->value;
            addtohead(t);
            deletenode(t);
            return result;
        }
        else
            return -1;

        // your code here
    }

    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if (temp.count(key) > 0)
        {
            Node *t = temp[key];
            t->value = value;
            addtohead(t);
            deletenode(t);
        }
        else
        {
            if (count < capacity)
            {
                Node *t = new Node(key, value);

                temp[key] = t;
                addtohead(t);
                count++;
            }
            else
            {
                deletenode(tail->prev);
                Node *t = new Node(key, value);
                temp[key] = t;
                addtohead(t);
            }
        }
        // your code here
    }