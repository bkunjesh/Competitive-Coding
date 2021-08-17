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
    cin>>n>>m>>k;
    int a[n+2],add[n+2];
    memset(a,0,sizeof(a));
    memset(add,0,sizeof(add));
    rep(i,n) cin>>a[i];
    int l[m+1],r[m+1],d[m+1];
    rep(i,m) cin>>l[i]>>r[i]>>d[i];

    int queryCount[m+2];
    memset(queryCount,0,sizeof(queryCount));

    int x,y;
    while(k--) cin>>x>>y,queryCount[x]++,queryCount[y+1]--;
    rep(i,m+1) queryCount[i]+=queryCount[i-1];

    rep(i,m)
    {
        add[l[i]]=add[l[i]]+queryCount[i]*d[i];
        add[r[i]+1]=add[r[i]+1]-queryCount[i]*d[i];
    }
    rep(i,n) add[i]+=add[i-1];
    
    rep(i,n) cout<<a[i]+add[i]<<" ";
    cout<<endl;
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
