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

void simpleSieve(int limit, vector<int> &prime)
{
    bool mark[limit + 1];
    memset(mark, false, sizeof(mark));

    for (int i = 2; i * i <= limit; ++i)
    {
        if (mark[i] == false)
        {
            // If not marked yet, then its a prime
            prime.push_back(i);
            for (int j = i; j <= limit; j += i)
                mark[j] = true;
        }
    }
}
vector<int> primesInRange(int low, int high)
{
    int limit = floor(sqrt(high)) + 1;
    vector<int> prime;
    simpleSieve(limit, prime);
    int n = high - low + 1;
    bool mark[n + 1];
    memset(mark, false, sizeof(mark));

    for (int i = 0; i < prime.size(); i++)
    {
        int loLim = floor(low / prime[i]) * prime[i];
        if (loLim < low)
            loLim += prime[i];
        if (loLim == prime[i])
            loLim += prime[i];
        for (int j = loLim; j <= high; j += prime[i])
            mark[j - low] = true;
    }
    vector<int> primes;
    for (int i = low; i <= high; i++)
        if (!mark[i - low])
            primes.push_back(i);

    return primes;
}

int n;

void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> prime;
    int maxhigh1 = 1e9 + 1e6;
    int maxhigh2 = 1e6;
    int ans = 0;

    int sqroot = sqrt(n);
    int low = max(sqroot - 2000000, 0ll);
    int high = sqroot;

    prime = primesInRange(0, 1000000);
    for (i = 0; i < prime.size() - 1; i++)
    {
        if (prime[i] * prime[i + 1] <= n)
            ans = max(ans, prime[i] * prime[i + 1]);
    }

    // low = max(sqroot - 1000000, 0ll);
    // high = min(sqroot + 1000000, maxhigh1);

    // prime = primesInRange(low, high);

    // for (i = 0; i < prime.size() - 1; i++)
    // {
    //     if (prime[i] * prime[i + 1] <= n)
    //         ans = max(ans, prime[i] * prime[i + 1]);
    // }

    // low = max(sqroot, 0ll);
    // high = min(sqroot + 2 * maxhigh2, maxhigh1);

    // prime = primesInRange(low, high);

    // for (i = 0; i < prime.size() - 1; i++)
    // {
    //     if (prime[i] * prime[i + 1] <= n)
    //         ans = max(ans, prime[i] * prime[i + 1]);
    // }
    low = 0;
    high = 1e6;
    for (j = 1; j < 2 * 1e1; j++)
    {
        prime = primesInRange(low, high);

        for (i = 0; i < prime.size() - 1; i++)
        {
            if (prime[i] * prime[i + 1] <= n)
                ans = max(ans, prime[i] * prime[i + 1]);
        }
        low += 1e6;
        high += 1e6;
        if (high > 1e10)
        {
            break;
        }
    }

    cout << ans << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
    for (int test = 1; test <= t; test++)
    {
        cout << "Case #" << test << ": ";
        solve();
    }
    return 0;
}
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif