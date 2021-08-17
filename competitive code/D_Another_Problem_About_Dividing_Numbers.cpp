//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int n;
int fac(int x)
{
    int i, j, cnt = 0;
    vector<int> ans;

    for (i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            while (x % i == 0)
            {
                x /= i;
                cnt++;
            }
        }
    }
    if (x > 1)
        cnt++;
    return cnt;
}

void solve()
{
    int i, j, k, a, b;

    cin >> a >> b >> k;
    // int x = (__gcd(a, b));
    // a /= x, b /= x;
    int x = fac(a);
    int y = fac(b);
    int z = fac(__gcd(a, b));
    // cout << x << " " << y << " " << z << " ";
    if (k > (x + y))
    {
        cout << "NO" << endl;
        return;
    }
    if (k % 2 == 0 && (k <= (x + y)))
    {
        cout << "YES" << endl;
        return;
    }
    int mx = x + y;
    int mn = 0;
    int p = x - z, q = y - z;
    if(k>1)
    {
        cout << "YES" << endl;
        return;
    }
    if(a!=b&&(min(a,b)==__gcd(a,b)))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
        return;

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