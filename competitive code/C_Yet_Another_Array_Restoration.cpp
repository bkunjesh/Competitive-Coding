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
    int i, j, k, x, y;

    cin >> n >> x >> y;
    int D = y - x, a, d,dif,minlast=1e9,start;
    for (a = 1; a <= x; a++)
    {
        for (d = 1; d <= D; d++)
        {
            if ((x - a) % d == 0 && (y - x) % d == 0)
            {
                int last = a + (n - 1) * d;
                if(last>=y&&last<minlast)
                {
                    minlast = last;
                    start = a;
                    dif = d;
                }

                
            }
        }
    }
    //cout << "YES";
    int diff = 0;
    while (n)
    {
        cout << start + diff << " ";
        diff += dif;
        n--;
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