//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
const int inf = 1e18;
const int N=200005;

int n;

void solve()
{
    int i, j, k,l,r;
    
    int q;
    cin>>n>>k>>q;
    vector<int> a(N,0),cnt(N,0);
    f(i,n) cin>>l>>r,a[l]++,a[r+1]--;
    for(i=1;i<N;i++) 
    {
        a[i]+=a[i-1];
        cnt[i]=cnt[i-1];
        if(a[i]>=k) cnt[i]++;
    }
    while(q--)
    {
        cin>>l>>r;
        cout<<cnt[r]-cnt[l-1]<<endl;
    }


    
    return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();		
    }
return 0;
}
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif