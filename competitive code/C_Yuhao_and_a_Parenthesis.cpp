#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i,k) for(i=0;i<k;i++)
#define rep(i,n) for(i=1;i<=n;i++)
#define rew(i,a,b) for(ll i=a;i<=b;i++)
#define endl "\n"
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
        cin>>n;
        string s;
        map<ll,ll> m;
        ll ans=0;
        for(i=0;i<n;i++)
        {
            cin>>s;
            ll cnt=0,min_neg=0;
            ll flag=0;
            for(auto it:s) 
            {   
                if(cnt==0&&it==')') flag=1;
                if(it=='(') cnt++;
                else cnt--;
                min_neg=min(min_neg,cnt);
            }
            if(cnt<=0&&min_neg<cnt) continue;
            if(flag&&cnt>=0) continue;
            if(s[0]==')'&&s[s.size()-1]=='(') continue;
            //cout<<s<<" "<<cnt;

            if(m[(-cnt)]>0) ans++,m[(-cnt)]--;//,cout<<" Y";
            else m[(cnt)]++;
            cout<<endl;
        }
        cout<<ans<<endl;

	}
	return 0;
}

