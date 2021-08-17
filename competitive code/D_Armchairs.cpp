//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
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
const int inf = 1e18;
const int N = 200005;

vector<int> a,o, z;

int n,m;
int dp[5001][5001];
int solve(int i, int j)
{
    if(i==n)
        return 0;
    if((n-i)>(m-j))
        return inf;
    int &res = dp[i][j];
    if (res != -1)
        return res;
    res = inf;
    res = min(solve(i, j + 1), solve(i + 1, j + 1) + abs(o[i] - z[j]));
    return res;
}
void solve()
{
    int i, j, k;

    cin >> n;
    f(i, n) cin >> j, a.push_back(j),(j == 0) ? z.push_back(i) : o.push_back(i);
    n = o.size(), m = z.size();
    memset(dp, -1, sizeof(dp));
    cout<< solve(0, 0);

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