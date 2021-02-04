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
    int i, j, k;

    int q;
    cin >> n >> q;
    map<int, int> kindergarten,rating;
    rep(i, n) 
    {
        cin >> j >> k;
        rating[i] = j, kindergarten[i] = k;
    }

    rep(i,q)
    {
        cin >> j >> k;
        kindergarten[j] = k;
    }
    int kcnt[N];
    memset(kcnt, -1, sizeof(kcnt));
    for(auto it:kindergarten)
    {
        int kd = it.S;
        int infant = it.F;
        int rat = rating[infant];

        kcnt[kd] = max(kcnt[kd], rat);
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