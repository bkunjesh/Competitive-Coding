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
    
    int a,b;
    cin>>k>>n>>a>>b;

    auto check=[&](int x)
    {
        int rem_k=k-x*a;
        int rem_n=n-x;
        int turnPossible=(rem_k-1)/b;
        if(turnPossible>=rem_n) return 1;
        else return 0;
        
    };
    int l=0,h=min(n,(k-1)/a),ans=-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else h=mid-1;
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