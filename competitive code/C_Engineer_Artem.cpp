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

int n;

void solve()
{
    int i, j, k, m;

    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), isinc(n, vector<int>(m));

    f(i, n) f(j, m) cin >> a[i][j],isinc[i][j]=0;

    for (i = 0; i < n;i++)
    {
        for (j = 0; j < m;j++)
        {
            if(i==0&&j==0)
                continue;
            if(i==0||j==0)
            {
                if(i==0)
                {
                    if(a[i][j-1]==a[i][j])
                    {
                        a[i][j]++;
                        isinc[i][j] = 1;
                        continue;
                    }
                }
                else if (j == 0)
                {
                    if (a[i-1][j] == a[i][j])
                    {
                        a[i][j]++;
                        isinc[i][j] = 1;
                        continue;
                    }
                }
                continue;
            }

            if(a[i])

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