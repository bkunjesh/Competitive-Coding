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
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    int u=0, d=0, r=0, l=0;
    n = s.size();
    for(auto it:s)
    {
        if(it=='U')
            u++;
        else if(it=='D')
            d++;
        else if(it=='R')
            r++;
            else
                l++;
    }
    if(x>=0)
    {
        if(r<x)
        {
            cout << "NO" << endl;
            return;
        }

        if(y>=0)
        {
            if(u<y)
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {
            if(d<abs(y))
            {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;

    }
    else
    {
        if(l<abs(x))
        {
            cout << "NO" << endl;
            return;
        }
        if (y >= 0)
        {
            if (u < y)
            {
                cout << "NO" << endl;
                return;
            }
        }
        else
        {
            if (d < abs(y))
            {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
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