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
        string s;cin>>n>>s; 
        ll cnt=0,diff=1,same=0;
        for(i=0;i<n-1;i++)
        {
            cnt++;
            if(i<n-1&&s[i]!=s[i+1])
            {
                diff++;
                cnt=0;
            }   
            else
            {
                same++;
                same=min(same,diff);
            }         
        } 
        cout<<(same+diff+1)/2<<endl; 
    }
return 0;
}