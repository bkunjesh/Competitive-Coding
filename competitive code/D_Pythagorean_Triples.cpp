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

    auto check=[&](int x)
    {
        int val=(x*x+1)/2;
        // cout<<val<<endl;
        if(val<=n) return 1;
        else return 0;
    };

    int l=1,h=1e9,ans=0;

    while(l<h)
    {
        int mid=(l+(h-l)/2);
        if(mid%2==0) mid++;
        // cout<<l<<" "<<h<<" "<<mid<<endl;
        if(check(mid))
        {
            ans=mid;
            l=mid;
        }
        else 
        {
            h=mid-1;
        }
        if(h-l<2) break;
    }

    cout<<ans/2<<endl;
    // cout<<endl;
    
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