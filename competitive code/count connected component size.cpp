#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
int c;
int adde(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    return 0;
}
void dfs(vector<int> adj[], bool vis[], int s, int &c)
{

    vis[s] = true;
    c++;
    for (int v : adj[s])
    {
        if (!vis[v])
        {
            dfs(adj, vis, v, c);
        }
    }
}
void trans(vector<int> adj[], vector<int> t[], int v)
{
    for (int i = 0; i < v + 5; i++)
    {
        for (int x : adj[i])
            t[x].push_back(i);
    }
}
void fo(vector<int> adj[], stack<int> &s, bool vis[], int v)
{
    vis[v] = true;
    for (int x : adj[v])
    {
        if (!vis[x])
            fo(adj, s, vis, x);
    }
    s.push(v);
}
void count(vector<int> adj[], int v)
{
    stack<int> st;
    bool vis[v + 5];
    for (int i = 0; i < v + 5; i++)
    {
        vis[i] = false;
    }
    for (int i = 0; i <= v; i++)
    {
        if (!vis[i])
            fo(adj, st, vis, i);
    }
    vector<int> t[v + 5];
    trans(adj, t, v);

    for (int i = 0; i < v + 5; i++)
    {
        vis[i] = false;
    }
    int ans = 0;
    int c = 0;
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        if (vis[u] == false)
        {
            c = 0;
            dfs(t, vis, u, c);
            ans = max(ans, c);
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int v, e;
        cin >> v >> e;

        vector<int> adj[v + 5];
        for (int j = 0; j < e; j++)
        {
            int u, k;
            cin >> u >> k;
            int f = adde(adj, u, k);
        }
        count(adj, v);
    }
    return 0;
}