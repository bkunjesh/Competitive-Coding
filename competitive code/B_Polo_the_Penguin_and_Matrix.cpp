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

int n,m,d;
map<int,int> store;

int a[101][101];

int getans(int x)
{
    int val=0;
    if(store.count(x)) return store[x];

    f(i,n)
    {
        f(j,m)
        {
            if(abs(x-a[i][j])%d==0)
            {
                val+=abs(x-a[i][j])/d;
            }
            else
            {
                return store[x]=INT_MAX;
            }
        }
    }
    return store[x]=val;
}

void solve()
{
    int i, j, k;
    
    
    cin>>n>>m>>d;
    f(i,n) f(j,m) cin>>a[i][j];

    int ans=INT_MAX;

    f(i,n) 
    {
        f(j,m)
        {
            ans=min(ans,getans(a[i][j]));
        }
    }
    if(ans==INT_MAX)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<ans<<endl;
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