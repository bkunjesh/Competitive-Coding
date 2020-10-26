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

ll maxSubArraySum(vector<ll> a, ll size)
{
    ll max_so_far = INT_MIN, max_ending_here = 0,
       start = 0, end = 0, s = 0;

    for (ll i = 0; i < size; i++)
    {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    return max_so_far;
}

void solve()
{
    ll i, j, k;

    cin >> n;
    vector<ll> a, b;
    f(i, n)
    {
        cin >> j;
        if (i % 2 == 0)
            a.push_back(j);
        else
            b.push_back(j);
    }
    ll one = maxSubArraySum(a, a.size());
    ll two = maxSubArraySum(b, b.size());
    cout << max(one, two) << endl;
    return;
}

int main()
{
    fast
        ll t = 1,
           i, j, k;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}