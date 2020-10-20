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
    ll i, j, k;

    cin>>n;
    ll k1,k2;
    queue<ll> q1,q2;
    cin>>k1;
    f(i,k1) cin>>j,q1.push(j);
    cin>>k2;
    f(i,k2) cin>>j,q2.push(j);

    ll move=0;
    while(move<105)
    {
        ll one=q1.front(),two=q2.front();
        q1.pop(),q2.pop();
        if(one>two)
        {
            q1.push(two);
            q1.push(one);
        }
        else
        {
            q2.push(one);
            q2.push(two);
        }
        move++;
        if(q1.empty())
        {
            cout<<move<<" "<<2<<endl;
            return ;
        }
        else if(q2.empty())
        {
            cout<<move<<" "<<1<<endl;
            return ;
        }
    }
    cout<<-1<<endl;
    return;
}

int main()
{
    fast
    ll t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();		
    }
return 0;
}