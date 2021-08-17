//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N = 4000005;

int n;
vector<int> g[100005], visited(100005, 0), incoming[N];
int getno(string s)
{
    int ans = 0;
    for (auto &c : s)
    {
        ans = ans * 10 + c - '0';
    }
    return ans;
}
void input(int &node, vector<int> &v)
{
    string str, word;
    // cin >> str;
    getline(cin, str);
    str += ',';
    stringstream s(str);
    int i = 0;
    while (s >> word)
    {
        string temp = word.substr(0, word.size() - 1);

        if (i == 0)
        {
            node = getno(temp);
        }
        else
            v.push_back(getno(temp));
        i++;
        // cout << temp << "-";
    }
    // cout << endl;
}
void solve()
{
    int i, j, k;

    vector<int> blank;
    // cin >> n;
    input(n, blank);
    // n = 4;

    for (i = 0; i < n; i++)
    {
        int node = 0, m;
        vector<int> v;
        input(node, v);
        m = v.size();
        // cout << node << " " << m << endl;
        // int node, m;
        // cin >> node >> m;
        for (j = 0; j < m; j++)
        {
            int child = v[j];
            // cin >> child;
            g[node].push_back(child);
            incoming[child].push_back(node);
            // cout << node << " " << child << endl;
        }
    }
    vector<pair<int, int>> ans;
    for (i = 0; i <= n; i++)
    {
        // cout << incoming[i].size() << " ";
        // for(auto x:incoming[i]) cout<<x<<" ";
        // cout<<endl;
        if (incoming[i].size() == 1)
        {
            ans.push_back({min(i, incoming[i][0]), max(i, incoming[i][0])});
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto it : ans)
    {
        cout << it.F << "-" << it.S << endl;
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif