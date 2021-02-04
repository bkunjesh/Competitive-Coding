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

int n, m;

vector<int> findUnion(int a1[], int a2[], int n, int m)
{
    int i = 0, j = 0;
    vector<int> v;
    while (i < n && j < m)
    {
        // if ((i > 0 && a1[i] == a1[i - 1]) || (j > 0 && a2[j] == a2[j - 1]))
        // {
        if (i > 0 && a1[i] == a1[i - 1])
        {
            i++;
            continue;
        }
        if (j > 0 && a2[j] == a2[j - 1])
        {
            j++;
            continue;
        }
        //     continue;
        // }
        if (a1[i] < a2[j])
        {
            v.push_back(a1[i++]);
        }
        else if (a2[j] < a1[i])
        {
            v.push_back(a2[j++]);
        }
        else
        {
            v.push_back(a2[j]);
            i++;
            j++;
        }
    }
    // cout << i << " " << j<<" ";
    while (i < n)
    {
        if (i == 0)
        {
            v.push_back(a1[i++]);
        }
        else if (i > 0 && a1[i] != a1[i - 1])
            v.push_back(a1[i++]);
        else if (a1[i] == a1[i - 1])
        {
            i++;
        }
    }
    //j++;
    while (j < m)
    {

        if (j > 0 && a2[j] != a2[j - 1])
            v.push_back(a2[j]), j++;
        else if (j == 0)
        {
            v.push_back(a2[j]), j++;
        }
        else if (a2[j] == a2[j - 1])
        {
            j++;
        }
    }
    for (auto it : v)
        cout << it << " ";
    cout << endl;
    return v;
}

void solve()
{
    int i, j, k;

    cin >> n >> m;
    int a1[n], a2[m];
    f(i, n) cin >> a1[i];
    f(i, m) cin >> a2[i];
    sort(a2, a2 + m);
    sort(a1, a1 + n);
    findUnion(a1, a2, n, m);
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