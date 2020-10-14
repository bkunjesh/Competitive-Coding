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
bool isvowel(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return 1;
    return 0;
}

int main()
{
    fast
    ll t = 1, i, j,k;
    //cin >> t;
    while (t--)
    {
        string s;
        cin>>n>>k>>s;
        queue<ll> q;
        ll presum[n+1]={0};
        presum[0]=isvowel(s[0])?1:0;
        ll ans=presum[0],ind;
        rep(i,n-1)
        {
            if(isvowel(s[i])) presum[i]=isvowel(s[i-1])?presum[i-1]+1:1;
            else presum[i]=isvowel(s[i-1])?presum[i-1]:0; 
            ans=max(ans,presum[i]);
        }
        f(i,n)
        {
            if(k==0) break;
            if(!isvowel(s[i]))
            {
                if(k==0) continue;
                if(q.size()==k) q.pop();
                q.push(i);         
            }  
            if(!q.empty()) ind=q.front();
            else ind=0;
            //cout<<i<<" "<<ind<<endl;
            ans=max(i-ind+presum[ind]+1,ans);          
        }
        cout<<ans<<endl;

        
    }
return 0;
}