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

int factorialNumInverse[N + 1];
// array to precompute inverse of 1! to N!
int naturalNumInverse[N + 1];
// array to store factorial of first N numbers
int fact[N + 1];

// Function to precompute inverse of numbers
void InverseofNumber(int p = mod)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(int p = mod)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;

    // precompute inverse of natural numbers
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}

// Function to calculate factorial of 1 to N
void factorial(int p = mod)
{
    fact[0] = 1;

    // precompute factorials
    for (int i = 1; i <= N; i++)
    {
        fact[i] = (fact[i - 1] * i) % p;
    }
}

// Function to return nCr % p in O(1) time
int ncr(int no, int r, int p = mod)
{
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    if (no < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
    int ans = ((fact[no] * factorialNumInverse[r]) % p * factorialNumInverse[no - r]) % p;
    return ans;
}

int n;

void solve()
{
    int i, j, k;
    int m, lsum = 0, rsum = 0;
    cin >> k >> n;
    vector<int> l(n), r(n);
    f(i, n) cin >> l[i] >> r[i], lsum += l[i], rsum +=(r[i]);
    k -= lsum;
    // k = rsum - k;

    cout << ncr(rsum - k + n - 1, n - 1, mod)<< endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    InverseofNumber(mod);
    InverseofFactorial(mod);
    factorial(mod);
    //cin >> t;
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