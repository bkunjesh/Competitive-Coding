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
        cin>>n;
        if(n%4==0)
        {
            cout<<"1 A"<<endl;
        }
        else if(n%4==1)
        {
            cout<<"0 A"<<endl;
        }
        else if(n%4==2)
        {
            cout<<"1 B"<<endl;
        }
        else 
        {
            cout<<"2 A"<<endl;
        }
    }
return 0;
}