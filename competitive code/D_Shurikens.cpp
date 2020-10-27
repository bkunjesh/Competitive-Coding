//@CodesUp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define f(i, k) for (i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (i = 1; i <= n; i++)
#define rew(i, a, b) for (ll i = a; i <= b; i++)
#define mod 1000000007
const ll inf = 1e10;

ll n;

void solve()
{
    ll i, j, k;

    cin >> n;
    vector<ll> query, ans;
    f(i, 2 * n)
    {
        char c;
        cin >> c;
        if (c == '+')
        {
            query.push_back(inf);
        }
        else
        {
            cin >> j;
            query.push_back(j);
        }
    }
    stack<ll> s;
    reverse(query.begin(), query.end());
    for (auto it : query)
    {
        if (it == inf)
        {
            if (s.empty())
            {
                cout << "NO" << endl;
                return;
            }
            ans.push_back(s.top());
            s.pop();
        }
        else
        {
            if (!s.empty() && s.top() < it)
            {
                cout << "NO" << endl;
                return;
            }
            s.push(it);
        }
    }
    reverse(ans.begin(), ans.end());
    
    cout << "YES" << endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return;
}

int main()
{
    fast;
    ll t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}