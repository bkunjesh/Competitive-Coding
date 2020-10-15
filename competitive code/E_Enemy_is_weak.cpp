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
const ll MAXN=1e5+5;
class FenwickTree
{
    //(one based indexing)
    // Refrence:- https://www.youtube.com/watch?v=CWDQJGaN1gY , cpalgorithms.

    private:
    ll n;
    vector<ll> bit;
    public:
    FenwickTree(ll n)
    {
        this->n=n+1; 
        bit=vector<ll>(n+1,0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    /*--who is parent--*/
    /*
         find parent of 6(110)
         sol- flip right most set bit of 6(110) 
              that is (100)=>4
              so 4 is parent of 6...

        //FOR QUERIE//
         getparent = (orignal_no)-(orignal_no & 2's complement)
        //FOR UPDATE//
         getnext = (orignal_no)+(orignal_no&2's complement)
    */


    ll sum(ll ind)
    {
        int ret=0;
        //getparent = (orignal_no)-(orignal_no & 2's complement)
        for(ind++;ind>0;ind=ind-(ind&-ind))
        ret+=bit[ind];

        return ret;        
    }

    ll sum(ll l,ll r)
    {
        return sum(r)-sum(l-1);
    }

    void add(ll ind,int val)
    {
        //getnext = (orignal_no)+(orignal_no&2's complement)
        for(ind++;ind<n;ind=ind+(ind&-ind))
        bit[ind]+=val;
    }

};


ll n;

int main()
{
    fast
    ll t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        cin>>n;
        vector<pair<ll,ll>> a;
        a.push_back({0,0});
        rep(i,n)
        {
            cin>>j;
            a.push_back({j,i});
        }
        FenwickTree biti(n+1),bitk(n+1);
        sort(a.begin()+1,a.end());

        rep(i,n) bitk.add(a[i].S,1);
        ll ans=0;
        rep(i,n)
        {
            bitk.add(a[i].S,-1);
            ll ans1=bitk.sum(a[i].S);
            
            ll ans2=biti.sum(a[i].S,n);
            biti.add(a[i].S,1);
            ans=ans+ans1*ans2;
        }
        cout<<ans<<endl;

    }
return 0;
}