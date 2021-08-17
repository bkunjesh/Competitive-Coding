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

int calc(const string &s, char c)
{
    if (s.size() == 1)
    {
        return s[0] != c;
    }
    int mid = s.size() / 2;
    int cntl = calc(string(s.begin(), s.begin() + mid), c + 1);
    cntl += s.size() / 2 - count(s.begin() + mid, s.end(), c);
    int cntr = calc(string(s.begin() + mid, s.end()), c + 1);
    cntr += s.size() / 2 - count(s.begin(), s.begin() + mid, c);
    return min(cntl, cntr);
}

void solve()
{
    int i, j, k;

    string s;
    cin >> n >> s;
    cout << calc(s, 'a') << endl;

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