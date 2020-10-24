//@bkunjesh
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (i = 1; i <= n; i++)
#define rew(i, a, b) for (ll i = a; i <= b; i++)
#define mod 1000000007
const ll inf = 1e18;

unsigned long long power(unsigned long long x,
                         ll y, ll p)
{
    unsigned long long res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, ll p)
{
    return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 ll r, ll p)
{
    // Base case
    if (r == 0)
        return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

// Returns n! % p using Wilson's Theorem
int modFact(ll n, ll p)
{
    // n! % p is 0 if n >= p
    // if (p <= n)
    //     return 0;

    // // Initialize result as (p-1)! which is -1 or (p-1)
    // ll res = (p - 1);

    // // Multiply modulo inverse of all numbers from (n+1)
    // // to p
    // for (ll i = n + 1; i < p; i++)
    //     res = (res * modInverse(i, p)) % p;
    // return res;
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return fac[n] % p;
}
ll n;
void solve()
{
    ll i, j, k, x, pos;
    cin >> n >> x >> pos;
    ll ele_gre_tn_x = n - x;
    ll ele_sml_th_x = x - 1;
    ll left = 0, right = n, greater = 0, smaller = 0, ans = 1;
    while (left < right)
    {
        ll mid = (left + right) / 2;
        if (mid == pos)
        {
            left = mid + 1;
            continue;
        }
        if (mid < pos)
        {
            smaller++;
            left = mid + 1;
        }
        else if (mid > pos)
        {
            greater++;
            right = mid;
        }
        else
            left = mid + 1;
    }
    ans = (ans * nCrModPFermat(ele_gre_tn_x, greater, mod)) % mod;
    ans = (ans * modFact(greater, mod)) % mod;
    ans = (ans * nCrModPFermat(ele_sml_th_x, smaller, mod)) % mod;
    ans = (ans * modFact(smaller, mod)) % mod;
    ll rem = n - (greater + smaller + 1);
    ans = (ans * modFact(rem, mod)) % mod;

    cout << ans << endl;

    return;
}

int main()
{
    fast
        ll t = 1,
           i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}