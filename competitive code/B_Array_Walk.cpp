//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define S second
#define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N=200005;

int n;

void solve()
{
    int i, j, k,z;
    cin >> n >> k >> z;
    vector<int> a(n+2),pref(n+2,0);
    rep(i, n) cin >> a[i], pref[i] = pref[i - 1] + a[i];
    int pair_mxsum = 0;
    pair<int, int> p;
    vector<pair<int, int>> mxpair(n+2);

    rew(i,2,n)
    {
        if(a[i]+a[i-1]>=pair_mxsum)
        {
            pair_mxsum = a[i] + a[i - 1];
            p = make_pair(a[i - 1], a[i]);
            mxpair[i] = p;
        }
        else
            mxpair[i] = mxpair[i - 1];
    }

    int ans = pref[k+1];
    for (i = 1; i <= z;i++)
    {
        j = k+1 - (2*i-1);

        if(j-1>=1)
            ans = max(pref[j] + (mxpair[j].F + mxpair[j].S) * (i-1) + a[j - 1], ans);
        j--;
        if(j>1)
        {
            ans=max(pref[j]+(mxpair[j].F+mxpair[j].S)*i,ans);
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