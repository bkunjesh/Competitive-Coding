//@ikung
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
const int N=200005;

int n;

void solve()
{
    int i, j, k;

    cin >> n;
    char a[n][n];
    pair<int, int> c[2];
    int cnt = 0;
    f(i,n) 
    {
        f(j, n) 
        {
            cin >> a[i][j];
            if(a[i][j]=='*')
            {
                c[cnt] = make_pair(i, j);
                cnt++;
            }
        }
    }
    if(c[0].F!=c[1].F&&c[0].S!=c[1].S)
    {
        a[c[0].F][c[1].S] = '*';
        a[c[1].F][c[0].S] = '*';
    }
    else
    {
        if (c[0].F == c[1].F)
        {
            int x = c[0].F + 1;
            if(x>=n)
                x = c[0].F - 1;

            a[x][c[1].S] = '*';
            a[x][c[0].S] = '*';
        }
        else
        {
            int y = c[0].S + 1;
            if (y >= n)
                y = c[0].S - 1;

            a[c[0].F][y] = '*';
            a[c[1].F][y] = '*';
        }
    }

    f(i,n) 
    {
        f(j,n)
        {
            cout << a[i][j];
        }
        cout << endl;
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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif