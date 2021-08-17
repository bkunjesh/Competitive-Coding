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

map<int, int> lm, rm;

void removesame()
{
    for (auto it : lm)
    {
        int x = min(it.S, rm[it.F]);
        lm[it.F] -= x;
        rm[it.F] -= x;
    }
    for (auto it : rm)
    {
        int x = min(it.S, lm[it.F]);
        rm[it.F] -= x;
        lm[it.F] -= x;
    }
}
vector<int> totele()
{
    vector<int> a(2, 0);
    for (auto it : lm)
    {
        a[0] += it.S;
    }
    for (auto it : rm)
    {
        a[1] += it.S;
    }
    return a;
}
void solve()
{
    int i, j, k, ans = 0;
    lm.clear();
    rm.clear();
    int l, r;
    cin >> n >> l >> r;
    vector<int> left, right;
    f(i, l) cin >> j, left.push_back(j), lm[j]++;
    f(i, r) cin >> j, right.push_back(j), rm[j]++;
    removesame();
    auto sum = totele();

    // cout << sum[0] << " " << sum[1] << endl;
    if (sum[0] > sum[1])
    {
        //left>right

        for (auto it : lm)
        {
            int tot = sum[0] + sum[1];
            int cnt = it.S;
            int left = tot / 2 - sum[1];
            int inc = (cnt) / 2;
            if (left == 0)
                break;
            if (inc <= left)
            {
                lm[it.F] -= inc;
                rm[it.F] += inc;
                sum[0] -= inc;
                sum[1] += inc;
                ans += inc;
            }
            else
            {
                lm[it.F] -= left;
                rm[it.F] += left;
                sum[0] -= left;
                sum[1] += left;
                ans += left;
            }
        }
    }
    else if (sum[0] < sum[1])
    {
        // cout << "Y";
        for (auto it : rm)
        {
            int tot = sum[0] + sum[1];
            int cnt = it.S;
            int left = tot / 2 - sum[0];
            int inc = (cnt) / 2;
            if (left == 0)
                break;

            if (inc <= left)
            {
                rm[it.F] -= inc;
                lm[it.F] += inc;
                sum[1] -= inc;
                sum[0] += inc;
                ans += inc;
            }
            else
            {
                rm[it.F] -= left;
                lm[it.F] += left;
                sum[1] -= left;
                sum[0] += left;
                ans += left;
            }
        }
        // cout << sum[0] << " " << sum[1] << endl;
    }

    removesame();

    sum = totele();

    if (sum[0] > sum[1])
    {
        //left>right

        for (auto it : lm)
        {
            int tot = sum[0] + sum[1];
            int cnt = it.S;
            int left = tot / 2 - sum[1];
            int inc = (cnt+1) / 2;
            if (left == 0)
                break;
            if (inc <= left)
            {
                lm[it.F] -= inc;
                rm[it.F] += inc;
                sum[0] -= inc;
                sum[1] += inc;
                ans += inc;
            }
            else
            {
                lm[it.F] -= left;
                rm[it.F] += left;
                sum[0] -= left;
                sum[1] += left;
                ans += left;
            }
        }
    }
    else if (sum[0] < sum[1])
    {
        // cout << "Y";
        for (auto it : rm)
        {
            int tot = sum[0] + sum[1];
            int cnt = it.S;
            int left = tot / 2 - sum[0];
            int inc = (cnt+1) / 2;
            if (left == 0)
                break;

            if (inc <= left)
            {
                rm[it.F] -= inc;
                lm[it.F] += inc;
                sum[1] -= inc;
                sum[0] += inc;
                ans += inc;
            }
            else
            {
                rm[it.F] -= left;
                lm[it.F] += left;
                sum[1] -= left;
                sum[0] += left;
                ans += left;
            }
        }
        // cout << sum[0] << " " << sum[1] << endl;
    }

    removesame();

    sum = totele();
    
    ans += min(sum[0], sum[1]);
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif