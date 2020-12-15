//@CodesUp
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
int N=200005;

int n;
int dist(pair<int,int> a,pair<int,int> b)
{
    return abs(b.F - a.F) + abs(b.S - a.S);
}
void solve()
{
    int i, j, k,p,q;

    cin >> n >> k;
    vector<pair<int, int>> a;
    f(i, n) cin >> p >> q, a.push_back({p, q});
    for (i = 0; i < n;i++)
    {
        int cnt = 0;
        for (j = 0; j < n;j++)
        {
            if(dist(a[i],a[j])<=k)
                cnt++;
        }
        if(cnt==n)
        {
            cout << 1 << endl;
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
    cin >> t;
    while (t--)
    {
        solve();		
    }
return 0;
}