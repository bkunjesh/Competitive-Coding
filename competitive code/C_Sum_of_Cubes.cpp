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

vector<int> cubes;

void solve()
{
    int i, j, k;

    int x;
    cin >> x;

    for (i = 1; i*i*i < x;i++)
    {
        int p = x - i * i * i;
        if(binary_search(cubes.begin(),cubes.end(),p))
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;

    return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    cin >> t;
    rep(i, 1e4 + 1) cubes.push_back(i * i * i);
    while (t--)
    {
        solve();		
    }
return 0;
}