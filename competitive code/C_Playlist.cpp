//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int n;
bool cmp1(pair<int, int> &a, pair<int, int> &b)
{
    return (a.F > b.F);
}

void solve()
{
    int i, j, k;
    cin >> n >> k;

    vector<pair<int, int>>  bt;
    f(i, n)
    {
        int u, v;
        cin >> u >> v;
        bt.push_back({v, u});
    }
    sort(bt.begin(), bt.end(), greater<pair<int, int>>());

    vector<int> mxsum(n, 0);
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0;
    j = 0;
    while (k > 1 && j < n)
    {
        if (pq.size() < k - 1)
        {
            pq.push(bt[j].S);
            sum += bt[j].S;
        }
        else
        {
            pq.push(bt[j].S);
            sum += bt[j].S;
            sum -= pq.top();
            pq.pop();
        }
        mxsum[j] = sum;
        j++;
    }
    int ans = bt[0].F * bt[0].S;

    for (i = 1; i < n; i++)
    {
        ans = max(ans, (mxsum[i - 1] + bt[i].S) * bt[i].F);
    }
    cout << ans << endl;
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