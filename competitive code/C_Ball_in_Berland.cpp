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
    int i, j;

    int na, nb, k;
    cin >> na >> nb >> k;
    vector<int> a(k), b(k);
    f(i, k) cin >> a[i];
    f(i, k) cin >> b[i];
    set<pair<int,int>> s;
    f(i, k) s.insert({a[i], b[i]});
    int m = s.size();
    unordered_map<int, int> ma, mb;
    i = 0;
    int ans = 0;
    for(auto it:s)
    {
        ans += (i - (ma[it.F] + mb[it.S]));
        ma[it.F]++;
        mb[it.S]++;
        i++;
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