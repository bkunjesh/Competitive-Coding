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
    int i, j, k;

    cin >> n;

    int no = n, mxcnt = 1, mxcntno = n;
    vector<pair<int, int>> m;

    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            m.push_back({i, cnt});
            if (mxcnt <= cnt)
            {
                mxcnt = cnt;
                mxcntno = i;
            }
        }
    }
    if (n > 1)
    {
        m.push_back({n, 1});
    }

    //cout << mxcnt << " " << mxcntno << " " << endl;

    vector<int> ans(mxcnt, mxcntno);
    if (!m.empty())
        for (auto it : m)
        {
            //cout << it.F << " " << it.S << endl;
            if (it.F == mxcntno)
                continue;
            ans[mxcnt - 1] *= pow(it.F, it.S);
        }

    cout << ans.size() << endl;
    for (auto it : ans)
    {
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