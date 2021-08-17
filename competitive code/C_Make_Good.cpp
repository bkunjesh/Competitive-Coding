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
    int a[n];
    int sum=0,xr=0;
    f(i,n) cin>>a[i],sum+=a[i],xr^=a[i];
    // cout<<sum<<" "<<xr<<"   ";
    if(xr!=0&&sum==2*xr)
    {
        cout<<0<<endl<<endl;
        return;
    }
    if(sum%2==0)
    {
        cout<<2<<endl;
        cout<<xr<<" "<<sum+xr<<endl;
    }
    else
    {
        cout<<3<<endl;
        sum++;
        xr^=1;
        cout<<1<<" "<<xr<<" "<<sum+xr<<endl;
    }

    
    
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