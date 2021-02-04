//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
const int inf = 1e18;
const int N=200005;

int n;

void solve()
{
    int i, j, k;
    
    int m;
    cin >> n >> m;
    int a[n + 1][m + 1];
    set<pair<int,int>> ans;
    rep(i, n) rep(j, m) cin >> a[i][j];
    rep(i,n)
    rep(j,m)
    {
        if(a[i][j]==1)
        {
            if(i>1&&j>1&&a[i-1][j]==1&&a[i][j-1]==1&&a[i-1][j-1])
            {
                ans.insert({i - 1, j - 1});
            }
            else if(i>1&&j<m&&a[i-1][j]==1&&a[i][j+1]==1&&a[i-1][j+1]==1)
            {
                ans.insert({i - 1, j});
            }
            else if(i<n&&j>1&&a[i][j-1]==1&&a[i+1][j-1]==1&&a[i+1][j]==1)
            {
                ans.insert({i, j-1});
            }
            else if(i<n&&j<m&&a[i][j+1]==1&&a[i+1][j+1]==1&&a[i+1][j]==1)
            {
                ans.insert({i , j});
            }
            else
            {
                cout << -1 << endl;
                return;
            }
            
        }
    }
    cout << ans.size() << endl;
    for(auto it:ans)
        cout << it.F << " " << it.S << endl;

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