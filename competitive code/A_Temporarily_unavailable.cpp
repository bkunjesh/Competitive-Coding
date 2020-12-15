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
const int N=200005;

int n;

void solve()
{
    int i, j, k;

    int a, b, c, r;
    cin >> a >> b >> c >> r;
    int ans = 0;
    if(a>b)
        swap(a, b);
    if(c-r>b||c+r<a) 
    {
        cout << b - a << endl;
        return;
    }
    int start = max(a, c - r);
    int end = min(b, c + r);
    ans = (start - a) + (b - end);
    cout << ans << endl;


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