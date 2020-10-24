//@bkunjesh
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (i = 1; i <= n; i++)
#define rew(i, a, b) for (ll i = a; i <= b; i++)
#define mod 1000000007
const ll inf = 1e18;

ll n;

void solve()
{
    ll i, j, k;

    cin >> n;
    vector<pair<ll, ll>> a;
    set<pair<ll, ll>> s;
    f(i, n)
    {
        cin >> j >> k;
        a.push_back({j, k}), s.insert({j, k});
    }
    ll ans = 0;
    map<ll, ll> m1, m2;
    map<pair<ll, ll>, ll> m3;
    n = a.size();
    f(i, n)
    {
        m1[a[i].F]++;
        m2[a[i].S]++;
        m3[{a[i].F, a[i].S}]++;
    }
    for (auto it : m1)
    {
        //cout<<it.F<<" "<<it.S<<endl;
        ans += (it.S - 1) * it.S / 2;
    }
    for (auto it : m2)
    {
        //cout << it.F << " " << it.S << endl;
        ans += (it.S - 1) * it.S / 2;
    }
    for (auto it : m3)
    {
        if (it.S > 1)
        {
            ans -= it.S * (it.S - 1) / 2;
        }
    }
    cout << ans << endl;
    return;
}

int main()
{
    fast
        ll t = 1,
           i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}