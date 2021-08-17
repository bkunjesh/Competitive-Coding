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

    cin >> n;
    vector<pair<int, int>> a;

    f(i, n) cin >> j, a.push_back({j, i + 1});

    sort(a.begin(), a.end());

    int ans[n + 1];
    memset(ans, 0, sizeof(ans));
    int sum = 0;
    ans[n-1] = 1;
    for (i = 0; i < n - 1;i++)
    {
        sum += a[i].F;
        if(sum>=a[i+1].F)
        {
            ans[i] = 1;
        }
    }
    vector<int> sol;
    for (i = n-1; i >= 0;i--)
    {
        if(ans[i]==0)
            break;
        sol.push_back(a[i].S);
    }
    sort(sol.begin(), sol.end());
    cout << sol.size() << endl;
    for(auto it:sol)
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