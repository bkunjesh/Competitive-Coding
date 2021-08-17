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
const int N = 20005;

int n, m;
vector<string> a(N);
vector<vector<pair<int, int>>> ans;
void getans(int x, int y)
{
    vector<pair<int, int>> one, zero;
    f(i, 2) f(j, 2)(a[x + i][y + j] == '0') ? zero.push_back({x + i, y + j}) : one.push_back({x + i, y + j});

    // for(auto it:zero)
    // {
    //     cout << it.F << " " << it.S << endl;
    // }

    int step = zero.size();
    if (step == 4)
        return;
    if (step == 0)
        step = 4;

    if (step == 4)
    {
        vector<pair<int, int>> temp;
        f(i, 3) zero.push_back(one[i]), temp.push_back(one[i]);
        f(i, 3) one.erase(one.begin());
        ans.push_back(temp);
        step--;
    }

    if (step == 3)
    {
        vector<pair<int, int>> temp;
        f(i, 1) zero.push_back(one[i]), temp.push_back(one[i]);
        f(i, 1) one.erase(one.begin());
        f(i, 2) one.push_back(zero[i]), temp.push_back(zero[i]);
        f(i, 2) zero.erase(zero.begin());
        ans.push_back(temp);
        step--;
    }

    if (step == 2)
    {
        vector<pair<int, int>> temp;
        f(i, 1) zero.push_back(one[i]), temp.push_back(one[i]);
        f(i, 1) one.erase(one.begin());
        f(i, 2) one.push_back(zero[i]), temp.push_back(zero[i]);
        f(i, 2) zero.erase(zero.begin());
        ans.push_back(temp);
        step--;
    }

    if (step == 1)
    {
        vector<pair<int, int>> temp;
        f(i, 3) zero.push_back(one[i]), temp.push_back(one[i]);
        f(i, 3) one.erase(one.begin());
        ans.push_back(temp);
        step--;
    }
}
void solve()
{
    int i, j, k;
    cin >> n >> m;
    a.clear();
    ans.clear();
    f(i, n) cin >> a[i];

    for (i = 0; i < n - 1; i+=2)
    {
        for (j = 0; j < m - 1; j += 2)
        {
            getans(i, j);
            f(p, 2) f(q, 2) a[p + i][q + j] = '0';
        }
        if (m % 2)
        {
            getans(i, m - 2);
            int x = i, y = m - 2;
            f(p, 2) f(q, 2) a[p + x][q + y] = '0';
        }
    }

    if(n%2)
    {
        i = n - 2;
        for (j = 0; j < m - 1; j += 2)
        {
            getans(i, j);
            f(p, 2) f(q, 2) a[p + i][q + j] = '0';
        }
        if (m % 2)
        {
            getans(i, m - 2);
            int x = i, y = m - 2;
            f(p, 2) f(q, 2) a[p + x][q + y] = '0';
        }
    }

    cout << ans.size() << endl;
    for (auto vec : ans)
    {
        for (auto it : vec)
        {
            cout << it.F + 1 << " " << it.S + 1 << " ";
        }
        cout << endl;
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif