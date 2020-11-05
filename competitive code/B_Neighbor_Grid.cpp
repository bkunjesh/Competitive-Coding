//@CodesUp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
const int inf = 1e18;
int N=200005;

pair<int, vector<vector<int>>> check(vector<vector<int>> a, int n, int m)
{
    int i, j;
    if(a[0][0]>2||a[0][m-1]>2||a[n-1][0]>2||a[n-1][m-1]>2)
    {
        return {0,a};
    }
    a[0][0] = 2, a[0][m - 1] = 2, a[n - 1][0] = 2, a[n - 1][m - 1] = 2;
    for (i = 1; i < n - 1; i++)
    {
        if(a[i][0]>3||a[i][m-1]>3)
            return {0,a};
        a[i][0] = 3, a[i][m - 1] = 3;
    }
    for (i = 1; i < m - 1; i++)
    {
        if (a[0][i] > 3 || a[n-1][i] > 3)
            return {0,a};
        a[0][i] = 3, a[n - 1][i] = 3;
    }
    for (i = 1; i < n - 1;i++)
    {
        for (j = 1; j < m - 1;j++)
        {
            if(a[i][j]>4)
                return {0,a};
            a[i][j] = 4;
        }
    }
    return {1, a};
}
int n;
void solve()
{
    int i, j, k,m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    f(i, n) f(j, m) cin >> a[i][j];
    auto temp = check(a, n, m);
    if (!temp.F)
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        a = temp.S;
        cout << "YES" << endl;
        f(i,n)
        {
            f(j, m) cout << a[i][j] << " ";
            cout << endl;
        }
    }
    

    return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        solve();		
    }
return 0;
}