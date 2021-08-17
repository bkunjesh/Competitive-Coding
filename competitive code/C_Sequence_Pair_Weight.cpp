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
    
    cin>>n;
    map<int, vector<int>> g;

    int a[n + 1];
    rep(i, n) cin >> a[i], g[a[i]].push_back(i);

    int ans = 0;

    for(auto it:g)
    {
        auto &vec = it.S;
        int m=vec.size();
        
        int x = vec[0];
        for (i = 1; i < m;i++)
        {
            ans += (x * (n-vec[i]+1));
            x += vec[i];
        }
    }
    cout << ans << endl;

    return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    cin >> t;
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