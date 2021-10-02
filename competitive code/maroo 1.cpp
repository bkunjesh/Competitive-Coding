//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define S second
#define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N=200005;

int n;

vector<string> getans(map<string,int> s_in,map<string,int> s_out)
{
    vector<string> res;
    map<string, int> span;
    int mxspan = 0;
    for(auto it:s_in)
    {
        string id=it.first;
        if(s_out[id]>0)
        {
            span[id] = s_out[id] - s_in[id];
            mxspan = max(maxspan, span[id]);
        }
    }

    for(auto it:span)
    {
        if(it.second==mxspan)
            res.push_back(it.first);
    }
}


void solve()
{
    int i, j, k;
    
    
    
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