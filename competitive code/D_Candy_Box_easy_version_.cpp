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
    
    cin>>n;
    int a[n+1];
    vector<int> b;
    memset(a,0,sizeof(a));
    f(i,n) cin>>j,a[j]++;
    rep(i,n) if(a[i]) b.push_back(a[i]);
    sort(b.begin(),b.end());
    n=b.size();
    j=b[0];
    int ans=b[n-1];
    for(i=n-2;i>=0;i--)
    {
        b[i]=min(b[i],b[i+1]-1);
        ans+=max(0ll,b[i]);
    }
    cout<<ans<<endl;

    
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