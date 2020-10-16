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
    ll t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        string s;cin>>s;
        //000..
        //1111..
        //000...1111
        //11...000  
        n=s.size();
        if(n==1) 
        {
            cout<<0<<endl;
            continue;
        }

        ll zcnt=0,ocnt=0;

        for(auto it:s) it=='0'?zcnt++:ocnt++;
        ll ans=min(zcnt,ocnt);

        vector<ll> zpre(n+1,0),opre(n+1,0),zsuf(n+1,0),osuf(n+1,0);



        if(s[0]=='0') zpre[0]=1;
        else opre[0]=1;
        rew(i,1,n-1)
        {
            if(s[i]=='0')
            {
                zpre[i]=zpre[i-1]+1;
                opre[i]=opre[i-1];
            }
            else
            {
                opre[i]=opre[i-1]+1;
                zpre[i]=zpre[i-1];
            }            
        }



        if(s[n-1]=='0') zsuf[n-1]=1;
        else osuf[n-1]=1;
        for(i=n-2;i>=0;i--)
        {
            if(s[i]=='0')
            {
                zsuf[i]=zsuf[i+1]+1;
                osuf[i]=osuf[i+1];
            }
            else
            {
                osuf[i]=osuf[i+1]+1;
                zsuf[i]=zsuf[i+1];
            }            
        }

        for(i=1;i<n;i++)
        {
            {
                ll tempans=min(zpre[i-1]+osuf[i+1],opre[i-1]+zsuf[i+1]);
                ans=min(ans,tempans);
            }         
        }

        cout<<ans<<endl;
    }
return 0;
}