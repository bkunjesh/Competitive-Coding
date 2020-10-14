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
    cin >> t;
    for(ll test=1;test<=t;test++)
    {
        cin>>n>>k;
        vector<pair<ll,ll>> a;
        ll p;
        f(i,n) cin>>j>>p,a.push_back({j,p});
        ll n_robot=0;
        sort(a.begin(),a.end());

        ll start=a[0].first;
        ll end=start+k;
        n_robot++;
        for(i=0;i<n;)
        {            
            //cout<<end<<" ";
            while(a[i].first>=start&&a[i].first<=end&&a[i].second<=end&&i<n)
            {
                i++;
            }
            if(i>=n) break;
            
            if(a[i].first>=start&&a[i].first<=end&&a[i].second>end)
            {
                ll p=ceil((double)(a[i].second-end)/k);
                n_robot+=p;
                //start=end;
                end=end+p*k;
                //n_robot++;
            }
            else if(a[i].first>end)
            {
                start=a[i].first;
                end=start+k;
                n_robot++;
            }
        }

        /*ll start=0,end=0;
        for(i=0;i<n;)
        {
            if(a[i].first>=end)
            {
                start=a[i].first;
                end=start+k;
                n_robot++;
            }
            while(a[i].second<=end&&i<n)
            {
                i++;
            }
            if(i>n) break;
            if(a[i].first<end&&a[i].second>end)
            {
                end+=k;
                n_robot++;
            }
        }*/










        /*for(i=0;i<n;)
        {            
            //cout<<end<<" ";
            while(a[i].first>=start&&a[i].first<=end&&a[i].second<=end&&i<n)
            {
                i++;
            }
            if(i>=n) break;
            
            if(a[i].first>=start&&a[i].first<=end&&a[i].second>end)
            {
                //start=end;
                end=end+k;
                n_robot++;
            }
            else if(a[i].first>end)
            {
                start=a[i].first;
                end=start+k;
                n_robot++;
            }
        }*/
        
        cout<<"case #"<<test<<": "<<n_robot<<endl;
    }
return 0;
}