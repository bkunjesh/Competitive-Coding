//@CodesUp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define endl "\n"
#define rep(i,n) for(i=1;i<=n;i++)
#define rew(i,a,b) for(i=a;i<=b;i++)
#define mod 1000000007
const int inf = 1e18;
int N=200005;
int n, m;
char g[1001][1001];
void solve(int i, int j)
{
    g[i][j] = '#';
    if (j + 1 < m && g[i][j + 1] == '.')
    {
        solve(i , j + 1);
    }
    if(i+1<n&&g[i+1][j]=='.')
    {
        solve(i + 1, j);
    }
    if (j - 1 >=0 && g[i][j - 1] == '.')
    {
        solve(i, j - 1);
    }
    if (i - 1 >=0 && g[i - 1][j] == '.')
    {
        solve(i - 1, j);
    }
}
void solve()
{
    int i, j, k;
    cin >> n >> m;
    int cnt = 0;
    f(i, n) f(j, m) cin >> g[i][j];
    f(i,n)
    {
        f(j,m)
        {
            if(g[i][j]=='.')
            {
                solve(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << endl;

    return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();		
    }
return 0;
}