#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, k) for (i = 0; i < k; i++)

void solve()
{
    ll i, j, n, m, k;
    cin >> n >> m;
    vector<vector<ll>> ROWS(n), COLS(n), sol;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> k, ROWS[i].push_back(k);

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            cin >> k, COLS[j].push_back(k);

    auto rowsdup = ROWS;
    auto colsdup = COLS;
    for (i = 0; i < n; i++)
    {
        sort(rowsdup[i].begin(), rowsdup[i].end());
        sort(colsdup[i].begin(), colsdup[i].end());
    }
    for (i = 0; i < n; i++)
    {
        auto col = colsdup[i];
        for (j = 0; j < n; j++)
        {
            auto row = rowsdup[j];

            if (row[0] == col[0])
            {
                sol.push_back(ROWS[j]);
                break;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        f(j, m) cout << sol[i][j] << " ";
        cout << endl;
    }

    return;
}

int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}