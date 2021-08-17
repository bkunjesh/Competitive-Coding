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

int check(int a)
{
    while (a > 3)
    {
        if (a % 3 == 2)
            return 0;
        a /= 3;
    }
    if (a == 2)
        return 0;

    return 1;
}

void solve()
{
    int i, j, k;

    cin >> n;

    vector<int> p;
    int pos2 = -1;
    while (n)
    {
        p.push_back((n % 3));
        if (p.back() == 2)
            pos2 = p.size() - 1;
        n = n / 3;
    }
    p.push_back(0);
    if (pos2 != -1)
    {
        int pos1 = find(p.begin() + pos2, p.end(), 0) - p.begin();

        p[pos1] = 1;
        for (int i = pos1 - 1; i >= 0; i--)
            p[i] = 0;
    }

    int ans = 0;
    int pw = 1;
    f(i, p.size())
    {
        ans += pw * p[i];
        pw = pw * 3;
    }
    cout << ans << endl;

    // j = n;
    // string s1 = "";
    // int a = n;
    // while (a > 3)
    // {
    //     char ch = ('0' + a % 3);
    //     s1 = ch + s1;
    //     a /= 3;
    // }
    // char ch = ('0' + a % 3);
    // s1 = ch + s1;

    // while (j <= 1e18 && (!check(j++)))
    //     ;

    // string s2 = "";
    // a = j - 1;
    // while (a >= 3)
    // {
    //     char ch = ('0' + a % 3);
    //     s2 = ch + s2;
    //     a /= 3;
    // }
    // ch = ('0' + a % 3);
    // s2 = ch + s2;
    // cout << n << " " << s1 << " " << s2 << " " << j - 1 << endl;

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