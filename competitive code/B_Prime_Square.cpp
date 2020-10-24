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

ll n;
// vector<ll> prime;
// void makeprime()
// {
//     vector<ll> primeno(200005, 0);
//     for (ll i = 2; i <= 200005; i++)
//     {
//         if (primeno[i] == 0)
//         {
//             for (ll j = 2 * i; j <= 200005; j = j + i)
//             {
//                 primeno[j] = 1;
//             }
//         }
//     }
//     for (ll i = 2; i <= 200005; i++)
//     {
//         if (primeno[i] == 0)
//             prime.push_back(i);
//     }
// }
void solve()
{
    ll i, j, k;
    cin >> n;
    vector<ll> a[n];
    f(i, n) f(j, n) a[i].push_back(0);
    for (i = 0; i < n; i++)
    {
        a[i][i] = 1;
        if(i+1<n) a[i][i+1]=1;
    }
    a[n-1][0]=1;
    f(i, n)
    {
        f(j, n) cout << a[i][j] << " ";
        cout << endl;
    }

    return;
}

int main()
{
    fast
        ll t = 1,
           i, j, k;
    cin >> t;
   // makeprime();
    while (t--)
    {
        solve();
    }
    return 0;
}