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
    int i, j, k, bcnt = 0, wcnt = 0;

    cin >> n;
    string s;
    cin >> s;
    vector<int> ans;

    f(i, n) (s[i] == 'B') ? bcnt++ : wcnt++;
    if(bcnt%2==1&&wcnt%2==1)
    {
        cout << -1 << endl;
        return;
    }
    if(bcnt==n||wcnt==n)
    {
        cout << 0 << endl;
        return;
    }
    if(bcnt%2==0)
    {
        f(i,n-1)
        {
            if(s[i]=='W')
            {
                s[i] = 'B';
                s[i + 1] = (s[i + 1] == 'B') ? 'W' : 'B';
                ans.push_back(i);
            }
        }
        f(i, n - 1)
        {
            if (s[i] == 'B')
            {
                s[i] = 'W';
                s[i + 1] = (s[i + 1] == 'B') ? 'W' : 'B';
                ans.push_back(i);
            }
        }
    }
    else
    {
        f(i, n - 1)
        {
            if (s[i] == 'B')
            {
                s[i] = 'W';
                s[i + 1] = (s[i + 1] == 'B') ? 'W' : 'B';
                ans.push_back(i);
            }
        }
        f(i, n - 1)
        {
            if (s[i] == 'W')
            {
                s[i] = 'B';
                s[i + 1] = (s[i + 1] == 'B') ? 'W' : 'B';
                ans.push_back(i);
            }
        }
    }
    cout << ans.size() << endl;
    for(auto it:ans)
        cout << it+1 << " ";
    cout << endl;

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