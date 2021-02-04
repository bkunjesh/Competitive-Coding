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
    int i, j, k, m;

    string s, t, p;
    cin >> s >> t >> p;

    map<char, int> ms, mt, mp;
    for (auto it : s)
        ms[it]++;
    for (auto it : t)
        mt[it]++;
    for (auto it : p)
        mp[it]++;

    for (auto it : s)
    {
        if (mt[it] == 0)
        {
            cout << "NO" << endl;
            return;
        }
    }

    n = s.size(), m = t.size();
    i = 0, j = 0;
    while (i < n && j < m)
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            if (mp[t[j]] == 0)
            {
                cout << "NO" << endl;
                return;
            }
            mp[t[j]]--;
            j++;
        }
    }
    while(j<m)
    {
        if(mp[t[j]]==0)
        {
            cout << "NO" << endl;
            return;
        }
        mp[t[j]]--;
        j++;
    }
    if (i >= n && j >= m)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}