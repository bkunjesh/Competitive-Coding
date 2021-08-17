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
bool cmp(tuple<int,int,int> a,tuple<int,int,int> b)
{
    return get<2>(a) < get<2>(b);
}

void solve()
{
    int i, j, k;

    int m;
    cin >> n >> m >> k;
    vector<tuple<int, int, int>> a;
    int u, v, l;
    f(i, m) cin >> u >> v >> l, a.push_back({u, v, l});
    sort(a.begin(), a.end(),cmp);
    map<int, int> mp;
    f(i, k) cin >> j, mp[j] = 1;
    for (i = 0; i < m;i++)
    {
        auto tpl = a[i];
        int node1 = get<0>(tpl), node2 = get<1>(tpl);

        if(((mp[node1]|mp[node2])!=0)&&((mp[node1]&mp[node2])==0))
        {
            cout << get<2>(tpl) << endl;
            return;
        }
    }
    cout << -1 << endl;

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