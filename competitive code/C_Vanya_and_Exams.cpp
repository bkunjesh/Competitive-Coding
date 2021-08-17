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
    int i, j, k,sum=0;
    
    int r,avg;
    cin>>n>>r>>avg;
    vector<pair<int,int>> a;
    f(i,n) cin>>j>>k,a.push_back({k,j}),sum+=avg-j;
    int ans=0;
    sort(a.begin(),a.end());
    // cout<<sum<<endl;
    for(auto it:a)
    {
        if(sum>0)
        {
            int canBeInc=r-it.S;
            if(sum-canBeInc>0)
            {
                ans+=(canBeInc)*(it.F);
                sum-=canBeInc;
            }
            else 
            {
                ans+=sum*it.F;
                sum-=sum;
            }
        }
    }
    cout<<ans<<endl;
    
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