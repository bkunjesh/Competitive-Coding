//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define S second
#define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N=200005;


void seive()
{
    int prime[100001];
    for (int i = 1; i <= 100000; i++)
        prime[i] = 1;
    prime[1] = 0;
    for (int i = 2; i * i <= 100000; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 100000; j = j + i)
            {
                prime[j] = 0;
            }
        }
    }
}

vector<vector<int>> graph;

map<int, int> current_val;
vector<int> current_size_of_subtree, larger_children, res;

void size_of_subtree(int current_node, int current_parent)
{
    current_size_of_subtree[current_node] = 1;
    for (auto child : graph[current_node])
    {
        if (child == current_parent)
            continue;
        size_of_subtree(child, current_node);
        current_size_of_subtree[current_node] += current_size_of_subtree[child];
    }
}

void add(int v, int p, int x, vector<int> &col);
void depth_first_search(int current_node, int current_parent, bool keep, vector<int> &col);

vector<int> Solution::solve(int A, vector<vector<int>> &B, vector<int> &C)
{
    int n = A;
    current_size_of_subtree.clear();
    larger_children.clear();
    res.clear();
    current_val.clear();
    current_size_of_subtree.resize(n + 1), larger_children.resize(n + 1), res.resize(n + 1);
    graph.resize(n + 1);

    for (int i = 0; i < n; i++)
        graph[i].clear();

    for (int i = 0; i < n - 1; i++)
    {
        int u = B[i][0], v = B[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    size_of_subtree(0, -1);
    depth_first_search(0, -1, 1, C);
    for (int i = 0; i < n; i++)
        final_res[i] = res[i];
    return final_res;
}
void add(int v, int p, int x, vector<int> &col)
{
    current_val[col[v]] += x;
    for (auto u : graph[v])
        if (u != p && !larger_children[u])
            add(u, v, x, col);
}

void depth_first_search(int current_node, int current_parent, bool keep, vector<int> &col)
{

    int mx = -1, larger_childrenChild = -1;
    for (auto x : graph[current_node])
    {
        if (x != current_parent)
        {
            if (current_size_of_subtree[x] > mx)
                mx = current_size_of_subtree[x], larger_childrenChild = x;
        }
    }
    for (auto x : graph[current_node])
    {
        if (x != current_parent && x != larger_childrenChild)
        {
            depth_first_search(x, current_node, 0, col); // run a depth_first_search on small childs and clear them from current_val
        }
    }

    if (larger_childrenChild != -1)
        depth_first_search(larger_childrenChild, current_node, 1, col), larger_children[larger_childrenChild] = 1; // larger_childrenChild marked as larger_children and not cleared from current_val

    add(current_node, current_parent, 1, col);
    //now current_val[c] is the number of vertices in subtree of vertex v that has color c. You can final_reswer the queries easily.

    int curr = 0;
    while (current_val[curr] != 0)
        curr++;
    res[current_node] = curr;

    if (larger_childrenChild != -1)
        larger_children[larger_childrenChild] = 0;
    if (keep == 0)
        add(current_node, current_parent, -1, col);
}