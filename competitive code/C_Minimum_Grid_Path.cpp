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

int getans(vector<int> u, vector<int> r, vector<int> c, int k = 1)
{
    int usz = u.size(), rsz = r.size(), i;
    int ans = inf;

    int uminind = min_element(u.begin(), u.end()) - u.begin();
    int rminind = min_element(r.begin(), r.end()) - r.begin();

    int udist = 1, rdist = 1, val = 0;
    int rmncost = r[0], umncost = u[0];
    val += (u[0] + r[0]);
    ans = u[0] * n + r[0] * n;
    for (i = 2; i < n; i++)
    {
        if (i % 2 == k)
        {
            val += (c[i]);
            udist++;
            umncost = min(c[i], umncost);
        }
        else
        {
            val += (c[i]);
            rmncost = min(c[i], rmncost);
            rdist++;
        }

        ans = min(ans, val + rmncost * (n - rdist) + umncost * (n - udist));
    }


    return ans;
}

void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> c, c1, c2;
    f(i, n)
    {
        cin >> j;
        c.push_back(j);
        if (i % 2)
            c1.push_back(j);
        else
            c2.push_back(j);
    }

    cout << min(getans(c1, c2, c, 1), getans(c2, c1, c, 0)) << endl;
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