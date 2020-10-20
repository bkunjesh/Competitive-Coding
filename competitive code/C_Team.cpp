//@bkunjesh
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
//#define endl "\n"
#define rep(i,n) for(i=1;i<=n;i++)
#define rew(i,a,b) for(ll i=a;i<=b;i++)
#define mod 1000000007
const ll inf = 1e18;

ll n;

void solve()
{
    ll i, j,k,m;

    cin>>n>>m;
    if(n*2+2<m||m+1<n)
    {
        cout<<-1<<endl;
        return ;
    }
    string ans="";
    if(n>=m)
    {
        ll flag=0;
        if(n>m) flag=1;
        while(m)
        {
            cout<<"01";
            m--;
        }
        if(flag) cout<<"0";
        cout<<endl;
    }
    else
    {
        while(n&&n<m)
        {
            cout<<"110";
            m-=2;
            n--;
        }
        while(n>0)
        {
            cout<<"10";
            n--;
            m--;
        }
        while(m>=2)
        {
            cout<<"11";
            m-=2;
        }
        if(m) cout<<"1",m--;
        cout<<endl;

    }
    cout<<ans<<endl;
    





    return;
}

int main()
{
    fast
    ll t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();		
    }
return 0;
}