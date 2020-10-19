//@bkunjesh
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define endl "\n"
#define rep(i,n) for(i=1;i<=n;i++)
#define rew(i,a,b) for(ll i=a;i<=b;i++)
#define mod 1000000007
const ll inf = 1e18;

ll n;

void solve()
{
    ll i, j, k;

    cin>>n;
    vector<ll> a(n+1);
    rep(i,n) cin>>a[i];
    vector<pair<ll,ll>> v2,v3,ans;
    
    ll row=n;
    for(i=n;i>0;i--)
    {
        if(a[i]==1)
        {
            v2.push_back({row,i});
            ans.push_back({row,i});
            row--;
        }
        else if(a[i]==2)
        {
            if(v2.size()==0)
            {
                cout<<-1<<endl;
                return;
            }

            pair<ll,ll> co=v2.back();
            v2.pop_back();
            ans.push_back({co.F,i});
            v3.push_back({co.F,i});
            
        }
        else if(a[i]==3)
        {
            if(v2.size()==0&&v3.size()==0)
            {
                cout<<-1<<endl;
                return;
            }
            if(v3.size()>0)
            {
                pair<ll,ll> co=v3.back();
                v3.pop_back();
                ans.push_back({row,i});
                ans.push_back({row,co.S});
                v3.push_back({row,i});
                row--;
                continue;
            }

            pair<ll,ll> co=v2.back();
            v2.pop_back();
            ans.push_back({row,i});
            ans.push_back({row,co.S});
            v3.push_back({row,i});
            row--;
        }
        
        if(i>1&&row<1)
        {
            cout<<-1<<endl;
            return ;
        }

    }
    cout<<ans.size()<<endl;
    for(auto it: ans) cout<<it.F<<" "<<it.S<<endl;

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