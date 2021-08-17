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
vector<int> nearestmin(vector<int> &a, int x, int k)
{
    vector<int> ans(n + 2, 0);
    stack<int> st;
    for (int i = x; i >= 1 && i <= n; i += k)
    {
        while (!st.empty() && a[st.top()] >= a[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = i;
        }
        else
            ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n + 2, 0), left(n + 2, 0), right(n + 2, 0);
    rep(i, n) cin >> a[i];
    auto leftmin = nearestmin(a, 1, 1);
    auto rightmin = nearestmin(a, n, -1);

    rep(i, n)
    {
        if (leftmin[i] == i)
            left[i] = i * a[i];
        else
            left[i] = left[leftmin[i]] + (i - leftmin[i]) * a[i];
    }
    for (i = n; i > 0; i--)
    {
        if (rightmin[i] == i)
            right[i] = (n - i + 1) * a[i];
        else
            right[i] = right[rightmin[i]] + (rightmin[i] - i) * a[i];
    }

    int mxval = 0, ind;
    rep(i, n) if (left[i] + right[i] - a[i] > mxval) ind = i, mxval = left[i] + right[i] - a[i];

    vector<int> ans(n + 2);
    ans[ind] = a[ind];
    for (i = ind - 1; i >= 1; i--)
    {
        ans[i] = min(ans[i + 1], a[i]);
    }
    for (i = ind + 1; i <= n; i++)
    {
        ans[i] = min(ans[i - 1], a[i]);
    }

    rep(i, n) cout << ans[i] << " ";
    cout << endl;

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