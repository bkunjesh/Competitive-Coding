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
    vector<int> a(n),ans;
    f(i, n) cin >> a[i];
    ans.push_back(a[0]);
    for (i = 1; i < n - 1;i++)
    {
        if(a[i-1]<a[i]!=a[i]<a[i+1])
            ans.push_back(a[i]);
    }
    ans.push_back(a[n - 1]);
    cout << ans.size() << endl;
    for(auto it:ans)
        cout << it << " ";
    cout << endl;

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