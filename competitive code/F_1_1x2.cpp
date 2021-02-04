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

int n,X,Y;
map<int, int> m;

int rechx(int y)
{
    if(y==X)
    {
        return 0;
    }
    if(y==1)
    {
        return abs(X - y);
    }
    if(m[y]!=0)
        return m[y];

    if(y%2)
        return m[y]=min({abs(X - y), rechx((y + 1) / 2) + 2, rechx((y - 1) / 2) + 2});
    else
        return m[y]=min({abs(X - y), rechx((y) / 2) + 1});

}

void solve()
{
    int i, j, k;
    cin >> X >> Y;
    if(Y<X) 
    {
        cout << X - Y << endl;
        return;
    }
    else
    {
        cout << rechx(Y)<<endl;
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