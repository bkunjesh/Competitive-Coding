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

vector<int> prime;
void make_prime_vect()
{
    int MAXN = 4000000;
    vector<int> br(MAXN + 1, 0);
    for (int i = 2; i <= MAXN; i++)
    {
        if (br[i] == 0)
        {
            for (int j = i * 2; j <= MAXN; j = j + i)
            {
                br[j] = 1;
            }
        }
    }
    for (int i = 2; i <= MAXN; i++)
        if (br[i] == 0)
            prime.push_back(i);
}

void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n + 1);
    rep(i, n) cin >> a[i];

    vector<int> e, b, c, d;
    j = 0;
    for (i = 1; i < n; i++)
    {
        e.push_back(i);
        b.push_back(i + 1);
        int x = min(a[i], a[i + 1]);
        int y = *upper_bound(prime.begin(), prime.end(), max(a[i], a[i + 1]));
        if (i > 1 && __gcd(x, a[i - 1]) == 1)
        {
            a[i] = x;
            a[i + 1] = y;
            c.push_back(x);
            d.push_back(y);
        }
        else
        {
            if (i > 1 && __gcd(y, a[i - 1]) == 1)
            {
                a[i] = y;
                a[i + 1] = x;
                c.push_back(y);
                d.push_back(x);
            }
            else if (i > 1)
            {
                y = *upper_bound(prime.begin(), prime.end(), max(a[i - 1], x));
                a[i] = y;
                a[i + 1] = x;
                c.push_back(y);
                d.push_back(x);
            }
            else
            {
                a[i] = y;
                a[i + 1] = x;
                c.push_back(y);
                d.push_back(x);
            }
        }
    }
    // for (i = 1; i <= n; i++)
    //     cout << a[i] << " ";
    // cout << endl;
    cout << e.size() << endl;
    for (i = 0; i < e.size(); i++)
    {
        cout << e[i] << " " << b[i] << " " << c[i] << " " << d[i] << endl;
    }

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
    make_prime_vect();
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