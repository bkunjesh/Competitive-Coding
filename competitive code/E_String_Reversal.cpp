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

class FenwickTree
{
    private:
    ll n;
    vector<ll> bit;
    public:
    FenwickTree(ll n)
    {
        this->n=n+1;
        bit=vector<ll>(n+1,0);
    }

    ll sum(ll ind)
    {
        int ret=0;
          //getparent = (orignal_no)-(orignal_no&2's complement)
        for(ind++;ind>0;ind=ind-(ind&-ind))
        ret+=bit[ind];

        return ret;        
    }

    int sum(ll l,ll r)
    {
        return sum(r)-sum(l-1);
    }

    void add(ll ind,int val)
    {
        for(ind++;ind<n;ind=ind+(ind&-ind))
        bit[ind]+=val;
    }

};

int main()
{
    fast
    ll t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        cin>>n;
        string a,b;cin>>a;
        b=a;
        reverse(b.begin(),b.end());
        set<ll> c[26];
        f(i,n) 
        {
            c[a[i]-'a'].insert(i);
        }
        FenwickTree fw(n);
        ll ans=0;
        f(i,n)
        {
            ll pos=(*c[b[i]-'a'].begin());
            ans+=(pos-fw.sum(pos));
            fw.add(pos,1);
            c[b[i]-'a'].erase(pos);
        }
        cout<<ans<<endl;
    }
return 0;
}