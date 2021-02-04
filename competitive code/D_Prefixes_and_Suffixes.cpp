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

vector<int> prefix_function(string s)
{
    int n = s.size();
    vector<int> pi(n + 1);
    int i, j = 0;
    for (i = 1; i < n;i++)
    {
        j = pi[i - 1];
        while(j>0&&s[j]!=s[i])
            j = pi[j - 1];
        if(s[j]==s[i])
            j++;
        pi[i] = j;
    }
    f(i, n) cout << pi[i] << " ";

    return pi;
}

void solve()
{
    int i, j, k;

    string s;
    cin >> s;
    n = s.size();
    auto pi=prefix_function(s);
    map<int, int> m;
    for(auto it:pi)
        m[it]++;
    
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