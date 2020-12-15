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
const int inf = 1e8;
int N = 200005;

int n;
set<int> sums;
vector<int> a, prefsum(100005);
int sum(int l, int r)
{
    return prefsum[r] - prefsum[l];
}
void divide(int l, int r)
{
    //cout << l << " " << r << endl;
    sums.insert(sum(l - 1, r));
    if (l == r)
        return;

    int midsum = (a[l] + a[r]) / 2;
    int midind = upper_bound(a.begin() + 1, a.end(), midsum) - a.begin();

    if (midind > l && midind != r + 1)
        divide(l, midind - 1);

    if (midind <= r && midind != l)
        divide(midind, r);
}

void solve()
{
    int i, j, k, q;

    cin >> n >> q;
    sums.clear();
    prefsum.clear();
    memset(&prefsum, 0, prefsum.size() * sizeof(prefsum[0]));
    a.resize(n + 1);
    rep(i, n)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());

    for (i = 1; i <= n; i++)
    {
        prefsum[i] = prefsum[i - 1] + a[i];
        //cout << prefsum[i + 1] << " ";
    }

    divide(1, n);

    // for (auto s : sums)
    //     cout << s << " ";
    // cout << endl;
    while (q--)
    {
        int s;
        cin >> s;
        if (sums.find(s) != sums.end())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

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