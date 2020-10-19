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
ll div(ll no)
{
    for(ll i=2;i*i<=no;i++)
    {
        if(no%i==0)
        {
            return i;
        }
    }
    return no;
}

int main()
{
    fast
    ll t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        cin>>n;
        vector<ll> a(n),res(n);
        f(i,n) cin>>a[i];
        map<ll,vector<ll>> m;
        map<ll,ll> ind;
        f(i,n)
        {
            ind[a[i]]=i;
            m[div(a[i])].push_back(i);
        }

        ll col=0;
        for(auto it:m)
        {
            if((it.S).size()>0)
            {
                col++;
                for(auto i:it.second)
                {
                    res[i]=col;                
                }
            }
        }
        cout<<col<<endl;
        f(i,n) cout<<res[i]<<" ";
        cout<<endl;


                
    }
return 0;
}