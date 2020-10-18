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

int main()
{
    fast
    ll t = 1,test, i, j, k;
    cin >> t;
    rep(test,t)
    {
        ll ans=0;
        string s,s1="KICK",s2="START";
        cin>>s;
        n=s.size();
        vector<ll> a;
        for(i=0;i<=n-4;i++)
        {
            if(s[i]=='K'&&s[i+1]=='I'&&s[i+2]=='C'&&s[i+3]=='K')
            {
                a.push_back(0);
            }
            if(i<=n-5&&s[i]=='S'&&s[i+1]=='T'&&s[i+2]=='A'&&s[i+3]=='R'&&s[i+4]=='T')
            {
                a.push_back(1);
            }

        }
        // for(auto i:a)
        // {
        //     cout<<i<<" ";
        // }
        for(i=a.size()-2;i>=0;i--)
        {
            if(a[i]==1)
            {
                a[i]+=a[i+1];
                
            }
            else
            {
                a[i]=a[i+1];
                ans+=a[i];
            }

        }
        cout<<"Case #"<<test<<": "<<ans<<endl;

        
    }
return 0;
}