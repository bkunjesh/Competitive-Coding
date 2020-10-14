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
    ll t = 1, i, j;
    //cin >> t;
    while (t--)
    {
        ll k;
        cin>>n>>k;
        vector<ll> a(n);
        ll p,sum=INT_MIN,p_sum=0,n_sum=0;
        f(i,n) 
        {
            cin>>a[i];
            a[i]==1?p_sum++:n_sum++;
        }

        for(p=0;p<k;p++)
        {
            ll p_cnt=0,n_cnt=0;
            for(i=p;i<n;i=i+k)
            {
                a[i]==1?p_cnt++:n_cnt++;
            }
            sum=max(abs(abs(p_sum-p_cnt)-abs(n_cnt-n_sum)),sum);
        }
        cout<<sum<<endl;
    }
return 0;
}