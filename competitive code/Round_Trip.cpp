//@CodesUp
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define mod 1000000007
//const int inf = 1e18;
const int N = 100005;

int n;

vector<int> g[N], visited(N);

vector<vector<int>> ans;
vector<int> st;
bool flag = 1;
void dfs(int node, int parent)
{
    visited[node] = 1;
    st.push_back(node);
    //cout << node << " ";
    if(flag)
    for (auto child : g[node])
    {
        if (!visited[child])
        {
            dfs(child, node);
        }
        else if (visited[child] && child != parent)
        {
            flag = 0;
            vector<int> temp;
            temp.push_back(child);
            int pos = st.size() - 1;
            while (pos>=0&&st[pos] != child)
            {
                temp.push_back(st[pos]);
                pos--;
            }
            temp.push_back(child);
            ans.push_back(temp);
        }
    }
    st.pop_back();
}

void solve()
{
    int i, j, k, m;

    cin >> n >> m;
    f(i, m) cin >> j >> k, g[j].push_back(k), g[k].push_back(j);
    //cout << "1";
    for (i = 1; i <= n;i++)
    {
        if(!visited[i]&&flag)
            dfs(i, -1);
    }
        

    if (ans.size() == 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << ans[0].size() << endl;
    for (auto it : ans[0])
    {
        cout << it << " ";
    }

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}