//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int n;

void solve()
{
    int i, j, k;

    int s;
    cin >> n >> s;
    vector<pair<int, int>> a;
    f(i, n) cin >> j, a.push_back({j, i + 1});

    int l = 0, h = n, ansk = 0;

    auto check = [&](int x) {
        multiset<int> st;
        for (auto it : a)
        {
            st.insert(it.F + it.S * x);
        }
        int cost = 0;
        auto it = st.begin();
        while ((x) && (it != st.end()))
        {
            cost += (*it);
            it++;
            x--;
        }
        //cout << cost << " ";
        return cost <= s;
    };
    while (l <= h)
    {
        int m = l + (h - l) / 2;
        //cout << m << " ";
        if (check(m))
        {
            ansk = m;
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
        //cout << endl;
    }
    multiset<int> st;
    for (auto it : a)
    {
        st.insert(it.F + it.S * ansk);
    }
    int cost = 0;
    auto it = st.begin();
    k = ansk;
    while (k-- && it != st.end())
    {
        cost += (*it);
        it++;
    }
    cout << ansk << " " << cost << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    //cin >> t;
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