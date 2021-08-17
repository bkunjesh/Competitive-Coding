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

    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    f(i, n) cin >> a[i], cnt[a[i]]++;
    priority_queue<int> q;
    for (auto it : cnt)
        q.push(it.S);

    while (q.size() > 1)
    {
        int first = q.top();
        q.pop();
        int second = q.top();
        q.pop();
        first--;
        second--;
        if (first)
        {
            q.push(first);
        }
        if (second)
        {
            q.push(second);
        }
    }
    if (q.size())
        cout << q.top() << endl;
    else
    {
        cout << 0 << endl;
    }

    // sort(cnt.begin(), cnt.end(), greater<int>());
    // int cur = 0;
    // for (i = 1; i < n; i++)
    // {
    //     while (i < n && cnt[cur] >= cnt[i])
    //     {
    //         cnt[cur] -= cnt[i];
    //         cnt[i] = 0;
    //         i++;
    //     }
    //     if (i >= n)
    //         break;

    //     cnt[i] -= cnt[cur];
    //     cnt[cur] = 0;
    //     cur = i;
    // }
    // sort(cnt.begin(), cnt.end(), greater<int>());

    // int ans = 0;
    // f(i, n) ans += cnt[i];
    // cout << ans << endl;

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