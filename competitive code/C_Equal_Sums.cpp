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
        ll k,p;
        cin>>k;
        vector<vector<ll>> v(k);
        vector<tuple<ll,ll,ll>> tpv;
        for(i=0;i<k;i++)
        {
            cin>>n;
            for(j=0;j<n;j++) cin>>p,v[i].push_back(p);
        }
        for(i=0;i<k;i++)
        {
            ll sum=0;
            for(auto it:v[i]) sum+=it;
            j=1;
            for(auto it:v[i]) tpv.push_back(make_tuple(sum-it,j,i)),j++;
        }
        sort(tpv.begin(),tpv.end());
        for(i=0;i<tpv.size()-1;i++)
        {
            ll sum=get<0>(tpv[i]);
            ll ele=get<1>(tpv[i]);
            ll ind=get<2>(tpv[i]);
            ll sum1=get<0>(tpv[i+1]);
            ll ele1=get<1>(tpv[i+1]);
            ll ind1=get<2>(tpv[i+1]);

            if(sum1==sum&&ind!=ind1)
            {
                cout<<"YES"<<endl;
                cout<<ind+1<<" "<<ele<<endl;
                cout<<ind1+1<<" "<<ele1<<endl;
                break;
            }

        }
        if(i==tpv.size()-1) cout<<"NO"<<endl;


    }
return 0;
}