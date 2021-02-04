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
    int m, h;

    cin >> n >> m >> h;
    vector<int> a(m + 1), b(n + 1);
    vector<vector<int>> he(n + 1, vector < int>(m + 1));
    f(i, m) cin >> a[i];
    f(i, n) cin >> b[i];
    f(i, n) 
    {
        f(j, m) 
        {
            cin >> he[i][j];
            if(he[i][j])
            {
                he[i][j] = min(a[j], b[i]);
            }
        }
    }
    f(i, n) 
    {
        f(j, m){
            cout << he[i][j] << " ";
        }
        cout << endl;
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