//@CodesUp
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
    vector<ll> a(n);
    map<ll, ll> m;
    f(i, n) cin >> a[i], m[a[i]]++;
    ll ans = m[4];
    ans += min(m[1], m[3]);
    m[1] -= min(m[1], m[3]);
    m[3] = m[3] - ans + m[4];
    //cout << ans << " ";
    ans += m[3];
    //cout << ans << " ";
    ans += m[2] / 2;
    m[2] = m[2] % 2;
    ans += m[1] / 4;
    m[1] = m[1] % 4;

    ans = ans + (m[1] + m[2] * 2 + 3) / 4;
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