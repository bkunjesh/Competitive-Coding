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
    int i, j;
    
    cin>>n;
    vector<int> a(n);
    f(i,n) cin>>a[i];
    sort(a.begin(),a.end(),greater<int>());
    
    auto check=[&](int k)
    {
        int allowed[k];
        f(i,k) allowed[i]=a[i];
        for(int i=k,pile=0;i<n;i++,pile++)
        {
            if(allowed[pile%k]==0) return 0;
            allowed[pile%k]=min(allowed[pile%k]-1,a[i]);
        }
        return 1;
    };

    for(i=1;i<=n;i++)
    {
        if(check(i))
        {
            cout<<i<<endl;
            return;
        }
    }
    
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


