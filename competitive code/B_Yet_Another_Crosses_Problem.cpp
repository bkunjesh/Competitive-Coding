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
    int i, j, k, m;

    cin >> n >> m;
    char a[n][m];
    f(i, n) f(j, m) cin >> a[i][j];

    int ans1 = max(n, m), ans2 = max(n, m);
    f(i,n)
    {
        int cnt = 0,cnt2=0;
        f(j, m) 
        {
            if (a[i][j] == '*') cnt++;
            if(a[j][i]=='*')
                cnt2++;
        }
        ans1 = min({ans1,m-cnt});
    }
    f(i,m)
    {
        int cnt = 0;
        f(j, n) 
        {
            
            if(a[j][i]=='*')
                cnt++;
        }
        ans2 = min({ans2,n-cnt});
    }
    cout << ans1+ans2 << endl;

    return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        solve();		
    }
return 0;
}