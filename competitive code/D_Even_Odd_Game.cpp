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

void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n), even, odd;
    f(i, n) cin >> a[i], (a[i] % 2) ? odd.push_back(a[i]) : even.push_back(a[i]);
    sort(odd.begin(), odd.end(), greater<int>());
    sort(even.begin(), even.end(), greater<int>());

    int alice = 0, bob = 0;
    n = even.size(), i = 0, j = 0;
    int m = odd.size();
    bool turn = 0;
    while (i < n && j < m)
    {
        if (turn == 0)
        {
            if (even[i] >= odd[j])
            {
                alice += even[i++];
            }
            else
            {
                j++;
            }
        }
        else
        {
            if (odd[j] >= even[i])
            {
                bob += odd[j++];
            }
            else
            {
                i++;
            }
        }
        turn = !turn;
    }
    while (i < n)
    {
        if (turn == 0)
            alice += even[i];
        i++;
        turn = !turn;
    }
    while (j < m)
    {
        if (turn)
            bob += odd[j];
        j++;
        turn = !turn;
    }
    if (alice > bob)
    {
        cout << "Alice" << endl;
    }
    else if (bob > alice)
    {
        cout << "Bob" << endl;
    }
    else
    {
        cout << "Tie" << endl;
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