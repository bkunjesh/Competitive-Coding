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
    
    cin>>n>>k;
    vector<int> div;

    for(i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            div.push_back(i);
            if(n/i!=i) div.push_back(n/i);
        }
    }
    sort(div.begin(),div.end());
    if(div.size()>=k)
    {
        cout<<div[k-1]<<endl;
    }
    else
    {
        cout<<-1<<endl;
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