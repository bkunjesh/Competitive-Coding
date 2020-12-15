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
vector<vector<int>> sp(300000, vector<int>(30 + 1));

int n;
int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b % 2)
        {

            b--;
            res = res * a;
        }
        else
        {
            b = b / 2;
            a = a * a;
        }
    }
    return res;
}
vector<int> a;
int query(int l, int r)
{
    int diff = (r - l + 1);
    int val;
    if (diff > 0)
        val = floor(log2(diff));
    else
    {
        return a[l];
    }

    int x = r - pow(2, val) + 1;
    int ans = (min(a[sp[l][val]], a[sp[x][val]]));
    return ans;
}
void solve()
{
    int i, j, k;
    cin >> n;
    a.clear();
    a.resize(n);
    f(i, n)
            cin >>
        a[i];
    int w = floor(log2(n));

    f(i, n)
        sp[i][0] = i;

    for (j = 1; power(2, j) <= n; j++)
    {
        for (i = 0; i + power(2, j) - 1 < n; i++)
        {
            if (a[sp[i][j - 1]] < a[sp[i + power(2, j - 1)][j - 1]])
            {
                sp[i][j] = sp[i][j - 1];
            }
            else
                sp[i][j] = sp[i + power(2, j - 1)][j - 1];
        }
    }

    int l = 1, r = n + 1, pivote = -1;
    while (l < r)
    {
        int mid = (l + r) / 2;

        set<int> s;
        int len = mid;
        int flag = 0;
        for (i = len - 1; i < n; i++)
        {
            s.insert(query(i - len + 1, i));
        }
        if (s.size() != n - len + 1)
            flag = 1;
        else
        {
            i = 1;
            for (auto x : s)
            {
                if (x != i)
                {
                    flag = 1;
                }
                i++;
            }
        }

        if (flag == 1)
        {
            l = mid + 1;
        }
        else
        {
            pivote = mid;
            r = mid;
        }
    }
    int flag = 0;

    sort(a.begin(), a.end());
    j = 1;
    for (auto x : a)
    {
        if (x != j)
        {
            flag = 1;
            break;
        }
        j++;
    }
    for (i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            if (flag == 0)
                cout << "1";
            else
                cout << "0";
        }
        else
        {
            if (i >= pivote && pivote != -1)
                cout << "1";
            else
                cout << "0";
        }
    }
    cout << endl;

    // cout << ansstring << endl;

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