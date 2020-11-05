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

    int a, b;
    cin >> a >> b;
    int d = b - a;
    if(d==0)
    {
        cout << 0 << endl;
        return;
    }
    if((d>0&&d%2!=0)||(d<0&&d%2==0))
    {
        cout << 1 << endl;
        return;
    }
    if(d<0&&d%2!=0)
    {
        cout << 2 << endl;
        return;
    }
    if((d>0&&d%2==0))
    {
        if(d%4==0)
        {
            cout << 3 << endl;
            return;
        }
        else
        {
            cout << 2 << endl;
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