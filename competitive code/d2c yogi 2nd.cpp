//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long


int n;

void solve()
{
    int i, j, k,q,ans=0;

    cin >> n >> q;
    unordered_map<int, int> mh;
    mh[1] = 1;

    for (i = 0; i < q;i++)
    {
        int u, v;
        cin >> u >> v;
        if(mh[u]==1)
        {
            ans++;
            mh[v] = 1;
        }
    }
    cout << ans << endl;

    return;
}

signed main()
{
    int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();		
    }
return 0;
}
