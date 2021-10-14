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
#define dbg(...) logger(#__VA_ARGS__,__VA_ARGS__)
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

vector<int> g[10];
int n;

int check(int a,int b)
{
    
    int ans=n;
    if(g[a].size()>0&&g[b].size()>0)
    {
        for(auto jind:g[b])
        {
            int mnind=-1,i=0;

            for(i=0;i<g[a].size()&&g[a][i]<jind;i++)
            {
                mnind=g[a][i];
            }
            if(mnind==-1) continue;
            ans=min(ans,((jind-mnind-1) + (n-jind-1) ));
        }
    }
    return ans;
}

void solve()
{

    int i, j, k;

    string s;
    cin>>s;
    n=s.size();

    f(i,10) g[i].clear();

    for(i=0;i<n;i++)
    {
        g[s[i]-'0'].push_back(i);
    }

    cout<<min({check(2,5),check(5,0),check(7,5),check(0,0)})<<endl;
    

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