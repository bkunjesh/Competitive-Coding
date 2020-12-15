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
bool not_sorted(vector<int> a)
{
    f(i,n-1)
    {
        if(a[i]>a[i+1])
            return 1;
    }
    return 0;
}

void solve()
{
    int i, j, k,x,ans=0;

    cin >> n >> x;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    i = 0;
    while(not_sorted(a))
    {
        ans++;
        while (i<n&&a[i]<=x)
        {
            i++;
        }
        if(i==n)
        {
            cout << -1 << endl;
            return;
        }
        swap(a[i], x);
    }
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