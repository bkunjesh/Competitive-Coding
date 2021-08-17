//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
// #define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
const int inf = 1e18;
const int N=200005;

int n;

void solve()
{
    int i, j, k,t;
    cin >> n >> t>>k;
    int zeros[n + 2];
    memset(zeros, 0, sizeof(zeros));
    int ones,l=1,r=n;
    cout << "? 1 "<<n<< endl;
    cin >> ones;
    zeros[n] =zeros[r-1]+((r - l) + 1) - ones;
    int ans;
    while(l<=r)
    {
        int m = l + (r - l) / 2;
        cout << "? " << l << " " << m << endl;
        cin >> ones;
        zeros[m] = zeros[l - 1] + ((m - l) + 1) - ones;
        
        if(zeros[m]>=k)
        {
        	if(zeros[m]==k)
	        {
	            ans=m;
	        }
            r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << "! " << ans << endl;

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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif
