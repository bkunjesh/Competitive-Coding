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
    int i, j, k;
    cin >> n;
    vector<int> p(n), c(n);
    f(i, n) cin >> p[i] >> c[i];
    f(i,n-1)
    {
        if(p[i]<c[i]||p[i]>p[i+1]||c[i]>c[i+1]||p[i+1]-p[i]<c[i+1]-c[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    if((p[n-1]<c[n-1]))
        {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;

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