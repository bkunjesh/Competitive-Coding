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
const int N = 1e6 + 2;
int dp[N];

int n;
void precalc()
{
    int i, j, k;
    vector<int> prime(N, -1);
    for (i = 2; i < N; i++)
    {
        if (prime[i] == -1)
        {
            for (j = i + i; j < N; j+=i)
            {
                if (prime[j] == -1)
                    prime[j] = i;
            }
        }
    }

    for (i = 2; i < N - 1; i++)
    {
        j = i;
        while (prime[j] != -1)
        {
            int x = j / prime[j];
            if ((x * x) > abs(x - i))
            {
                dp[x] = 1;
                dp[i] = 1;
            }

            x = prime[j];
            if ((x * x) > abs(x - i))
            {
                dp[x] = 1;
                dp[i] = 1;
            }
            j = j / prime[j];
        }
    }
    rew(i, 2, 20)
    {
        cout << i << " " << prime[i] << " " << dp[i] << endl;
    }
}

void solve()
{
    int i, j, k;

    cin >> n;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    precalc();
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