#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
#define endl "\n"
#define rep(i,n) for(i=1;i<=n;i++)
#define rew(i,a,b) for(ll i=a;i<=b;i++)
#define mod 1000000007
const ll inf = 1e18;

ll n;

int main()
{
    fast
    ll t = 1, i, j,k;
    //cin >> t;
    while (t--)
    {
        cin>>n;
        vector<ll> a(n);
        f(i,n) cin>>a[i];
        vector<ll> zero;
        ll cnt=0;
        f(i,n)
        {
            if(a[i]==1&&cnt!=0)
            {
                zero.push_back(cnt);
                cnt=0;
            }
            else if(a[i]==0)
            {
                cnt++;
            }
        }
        if(a[n-1]==0) zero.push_back(cnt);
        sort(zero.begin(),zero.end(),greater<ll>());
        if(zero.empty())
        {
            cout<<"Bob"<<endl;
            return 0;
        }
        if(zero[0]%2==0)
        {
            cout<<"Bob"<<endl;
            return 0;
        }
        if(zero[0]%2==1)
        {
            if(zero.size()>1&&zero[0]/2<zero[1])
            {
                cout<<"Bob"<<endl;
            }
            else
            {
                cout<<"Alice"<<endl;
            }            
        }
    }
return 0;
}