//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;

void solve()
{
    int i, j, k;

    string s,t="BAZINGA";
    cin>>n>>s;

    vector<int> g[26];
    for (i = 0; i < n;i++)
    {
        g[s[i] - 'A'].push_back(i);
    }

    int prev = -1;

    for (i = 0; i < t.size();i++)
    {
        int ind = t[i] - 'A';
        auto it=upper_bound(g[ind].begin(), g[ind].end(), prev);
        if(it!=g[ind].end())
        {
            prev = *it;
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

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