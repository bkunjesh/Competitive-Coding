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

void solve()
{
    string s; cin>>n>>s;
    s=s[n-1]+s+s[0];
    ll i,j,k;
    ll fcnt=0,bcnt=0,ocnt=0;
    for(i=1;i<=n;i++) 
    {
        if(s[i]=='>') fcnt++;
        else if(s[i]=='<') bcnt++;
        else ocnt++;
    }
    if(fcnt+ocnt==n||bcnt+ocnt==n)
    {
        cout<<n<<endl;
        return ;
    }
    ll ans=0;
    for(i=1;i<=n;i++)
    {
        if(s[i]=='-'||s[i-1]=='-') 
        {
            ans++;
        }
        
    }
    cout<<ans<<endl;

}
int main()
{
    fast
    ll t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        solve();        
    }
return 0;
}