//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long


#define mod 1000000007
const int inf = 1e18;
const int N=200005;

void getans(int n,vector<int> a)
{
    for (int i = 0; i < n;i++)
    {
        if(a[i]<i) 
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

void solve()
{
    int i, j, k,n;
    cin >> n;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    getans(n,a);
    

    return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
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