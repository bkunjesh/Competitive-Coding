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
    
    int x,y;
    cin>>x>>y;
    int ok=1;
    vector<int> bx,by;
    if(y<x)
    {
        cout<<"NO"<<endl;
        return;
    }
    for(i=0;i<=30;i++)
    {
        if(x&(1<<i)) bx.push_back(i);
        if(y&(1<<i)) by.push_back(i);
    }
    if(by.size() <= bx.size())
    {
        for(i=0;i<by.size();i++)
        {
            if(bx[i]>by[i])
            {
                cout<<"NO"<<endl;
                return ;
            }
        }
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#

