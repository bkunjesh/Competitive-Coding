//@CodesUp
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
int N = 200005;

int n;

void solve()
{
    int i, j, k, ans = 0;
    cin >> n >> k;

    string s;
    cin >> s;
    vector<int> blockpref(s.size() + 1, 0), sheetpref(s.size() + 1, 0), magind, ironind;
    for (i = 0; i < s.size(); i++)
    {
        blockpref[i + 1] = (s[i] == 'X') ? blockpref[i] + 1 : blockpref[i];
        sheetpref[i + 1] = (s[i] == ':') ? sheetpref[i] + 1 : sheetpref[i];
        if (s[i] == 'M')
            magind.push_back(i);
        if (s[i] == 'I')
            ironind.push_back(i);
    }
    i = 0, j = 0;
    while (i < magind.size() && j < ironind.size())
    {
        int low = min(magind[i], ironind[j]), high = max(magind[i], ironind[j]);
        if (blockpref[high + 1] - blockpref[low] == 0)
        {
            if (k + 1 - (high - low) - (sheetpref[high + 1] - sheetpref[low]) > 0)
            {
                //cout << low << " " << high << endl;
                ans++;
                (magind[i] > ironind[j]) ? i++ : j++;
            }
        }
        (magind[i] < ironind[j]) ? i++ : j++;
    }
    cout << ans << endl;

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