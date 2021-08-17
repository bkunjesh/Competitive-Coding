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
int check(string s, char ch)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ch)
            cnt++;
        else
            cnt--;

        if (cnt < 0)
            return 0;
    }
    if (cnt == 0)
        return 1;
    else
        return 0;
}
int check2(string s, char ch)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ch)
            cnt--;
        else
            cnt++;

        if (cnt < 0)
            return 0;
    }
    if (cnt == 0)
        return 1;
    else
        return 0;
}

void solve()
{
    int i, j, k;
    string s;
    map<char, int> m;
    cin >> s;
    for (auto it : s)
        m[it]++;

    if (check(s, 'A') || check(s, 'B') || check(s, 'C') || check2(s, 'A') || check2(s, 'B') || check2(s, 'C'))
    {
        // cout << check(s, 'A') << check(s, 'B') << check(s, 'C') << " ";
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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