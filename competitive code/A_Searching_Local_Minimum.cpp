//@ikung
#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
// #define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
const int inf = 1e9;
const int N=200005;

int n;
int query(int i)
{
    int x;
    cout << "? " << i << endl;
    cin >> x;
    return x;
}
void solve()
{
    int i, j, k;

    cin >> n;
    vector<int> a(n + 2, -1);
    a[0] = inf, a[n + 1] = inf;

    int l = 1, h = n;

    while(l<=h)
    {
        int m = l + (h - l) / 2;
        if(a[m]==-1)
            a[m] = query(m);
        if(a[m+1]==-1)
            a[m + 1] = query(m+1);
        if (a[m - 1] == -1)
            a[m - 1] = query(m - 1);
        if(a[m-1]>a[m]&&a[m]<a[m+1])
        {
            cout << "! " << m << endl;
            return;
        }
        if(a[m]>a[m+1])
        {
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }

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
