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
    
    cin>>n;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    int ans = 0;
    f(i,n-1)
    {
        int mnind = min_element(a.begin() + i, a.end())-a.begin();
        reverse(a.begin() + i, a.begin() + mnind + 1);
        ans += (mnind - i + 1);
        // cout << mnind - i + 1 << " ";
    }
    cout << ans << endl;

    return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    cin >> t;
    rep(test,t)
    {
        cout << "Case #" << test << ": ";
        solve();		
    }
return 0;
}
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif