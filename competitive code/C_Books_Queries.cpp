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
    //cin >> t;
    while (t--)
    {
        ll q,query;
        cin>>q;
        query=q;
        ll a[2*q+1];
        ll left=q,right=q;
        map<ll,ll> m;
        while(query--)
        {
            char ch;
            ll id;
            cin>>ch>>id;
            if(query==q-1)
            {
                if(ch=='L') left++;
                else right--;
            }
            if(ch=='L')
            {
                left--;
                a[left]=id;
                m[id]=left;                
            }
            else if(ch=='R')
            {
                right++;
                a[right]=id;
                m[id]=right;

            }
            else
            {
                cout<<min(m[id]-left,right-m[id])<<endl;
                
            }
            
        }
    }
return 0;
}