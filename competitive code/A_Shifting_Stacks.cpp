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
    vector<int> a(n);
    f(i,n) cin>>a[i];
    if(n==1)
    {
        cout<<"YES"<<endl;
        return;
    }
    a[1]+=a[0];
    a[0]=0;
    rep(i,n-1)
    {
        // cout<<a[i-1]<<" "<<a[i]<<endl;
        if(a[i]<=a[i-1])
        {
            cout<<"NO"<<endl;
            return;
        }
        if(i==n-1) continue;
        if(a[i]-i>=0)
        {
            a[i+1]+=(a[i]-i);
            a[i]=i;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    if(a[n-2]>=a[n-1])
        {
            cout<<"NO"<<endl;
            return;
        }
    cout<<"YES"<<endl;
    
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