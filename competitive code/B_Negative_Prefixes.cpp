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
pair<vector<int>, int> sol(vector<int> a, vector<int> status, vector<int> unlocked)
{
    vector<int> ans;
    int negind = -1, ulind = 0, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (status[i] == 1)
        {
            ans.push_back(a[i]);
        }
        else
        {
            ans.push_back(unlocked[ulind++]);
        }
        sum += ans[i - 1];
        if (sum < 0)
            negind = i;
    }
    return {ans, negind};
}

void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n + 1), status(n + 1), unlocked;
    rep(i, n) cin >> a[i];
    rep(i, n)
    {
        cin >> status[i];
        if (status[i] == 0)
        {
            unlocked.push_back(a[i]);
        }
    }
    //sort(unlocked.begin(), unlocked.end());
    //auto one = sol(a, status, unlocked);
    sort(unlocked.begin(), unlocked.end(), greater<int>());
    auto two = sol(a, status, unlocked);
    //cout << one.S << " " << two.S << endl;
    // if (one.S < two.S)
    // {
    //     for (auto it : one.F)
    //     {
    //         cout << it << " ";
    //     }
    // }
    // else
    {
        for (auto it : two.F)
            cout << it << " ";
    }
    cout << endl;

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