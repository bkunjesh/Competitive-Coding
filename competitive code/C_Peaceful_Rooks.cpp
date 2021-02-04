//@CodesUp
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

int n;

void solve()
{
    int i, j, k,ans=0;

    int m;
    cin >> n >> m;
    int x[n + 1], y[n + 1], visited[n + 1];
    memset(visited, 0, sizeof(visited));

    f(i, m) 
    {
        
    }
    int rook = m;
    rep(i,n)
    {
        if(x[i]>0&&y[i]>0)
        {
            rook--;
            visited[i] = 1;
        }
        
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