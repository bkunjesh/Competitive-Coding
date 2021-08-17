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
int getceil(int x)
{
    return ceil(sqrt(x));
}

void solve()
{
    int i, j, k;
    cin >> n;
    vector<pair<int,int>> moves;
    int h = n;
    for (i = n - 1; i >= 2;i--)
    {
        if(i==getceil(h))
        {
            int x = h;

            moves.push_back({h, i});
            x = ((x + i - 1) / i);
            if(x>1)
            {
                moves.push_back({h, i});
            }
            h = i;
        }
        else
        {
            moves.push_back({i, h});
        }
    }

    cout << moves.size() << endl;
    for(auto it:moves)
        cout << it.F << " " << it.S << endl;

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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif