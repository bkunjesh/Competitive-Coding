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
const int N = 200005;

int n;
int getcury(int a,int b)
{
    int ans = 0;
    for (int i = 0; i <= 30;i++)
    {
        if(((a)&(1<<i))&&(((b)&(1<<i))==0))
        {
            ans = ans ^ (1 << i);
        }
    }
    return ans;
}

void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    vector<int> ans;
    ans.push_back(0);
    int last = a[0];
    for (i = 1; i < n; i++)
    {
        // int cury = last ^ a[i];
        int cury = getcury(last,a[i]);
        ans.push_back(cury);
        last = cury ^ a[i];
    }
    for (auto it : ans)
        cout << it << " ";
    cout << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
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