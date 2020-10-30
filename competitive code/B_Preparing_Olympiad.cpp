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

    int l, r, x,ans=0;
    cin >> n >> l >> r >> x;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    i = 1 << (n);
    while(i>0)
    {
        int sum = 0,mn=INT_MAX,mx=INT_MIN;
        j = i;
        int cnt = n-1;
        while(cnt>=0)
        {
            if((j&(1<<cnt)))
            {
                sum += a[n - cnt - 1];
                mn = min(mn, a[n - cnt - 1]);
                mx = max(mx, a[n - cnt - 1]);
            }
            cnt--;
        }
        if(sum>=l&&sum<=r&&(mx-mn)>=x)
            ans++;
        i--;
    }
    cout << ans << endl;
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