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
        cin>>n;
        vector<ll> a(n);
        f(i,n) cin>>a[i];
        sort(a.begin(),a.end(),greater<ll>());
        j=n-1;
        ll sum=0,psum=0,nsum=0,flag=1,pind;
        for(i=0;i<n;i++)
        {
            sum+=a[i];

            if(a[i]>0) pind=i,psum+=a[i];
            else nsum+=a[i];
            // if(sum==0)
            // {
            //     // swap(a[i],a[j]);
            //     // sum+=a[i];
            //     // sum-=a[j];
            //     // j--;
            //     if(sum==0)
            //     {
            //         flag=0;
            //         break;
            //     }
            // }           
        }
        if(psum+nsum!=0)
        {
            cout<<"YES"<<endl;
            if(psum+nsum<=0)
            {
                sort(a.begin(),a.end());
            }
            f(i,n) cout<<a[i]<<" ";
            cout<<endl;
        }
        else cout<<"NO"<<endl;

    }
return 0;
}