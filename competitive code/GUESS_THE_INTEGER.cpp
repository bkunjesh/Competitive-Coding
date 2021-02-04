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
    vector<int> l,r;
    char ch;

    f(i, n) cin >> ch >> j, (ch == 'L') ? l.push_back(j) : r.push_back(j);
    sort(r.begin(), r.end(), greater<int>());
    sort(l.begin(), l.end());
    int L, R;

    L = r[0], R = l[0];

    if (l.size() == 0 || r.size() == 0 || R - L <= 1)
    {
        cout << -1 << endl;
        return;
    }
    cout << R - L - 1 << endl;


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