//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;

vector<int> getans(int n, vector<int> a)
{
    int i;
    vector<int> ans(n, 0);
    unodered_map<int, int> freq;
    int dist = 0;

    for (i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }
    for (i = 0; i < n; i++)
    {
        freq[a[i]]--;
        ans[i] = dist;
        if (freq[a[i]] == 0)
            dist++;
    }
    freq.clear();
    dist = 0;
    for (i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }
    for (i = n - 1; i >= 0; i--)
    {
        freq[a[i]]--;
        ans[i] = abs(ans[i] - dist);
        if (freq[a[i]] == 0)
            dist++;
    }
    for (i = 0; i < n;i++)
        cout << (ans[i]) << " ";
    return ans;
}

void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    getans(n, a);

    return;
}

signed main()
{
    int t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
