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

vector<string> splitstring(string s)
{
    vector<string> ans;
    string temp = "";
    for (int i = 0; i < s.size();i++)
    {
        if(s[i]=='=')
        {
            ans.push_back(temp);
            temp = "";
        }
        else
        {
            temp += s[i];
        }
    }
    ans.push_back(temp);
    return ans;
}

int getans(int pos,string x,int cursum,int sum)
{
    if(pos>=x.size())
        return INT_MAX;
    if(cursum>=sum)
        return INT_MAX;

    int &res = dp[pos][cursum];
    if(res!=-1)
        return res;
    


    for (int i = pos;i<min(pos+5,x.size()),i++)
    {
        int tempsum = getsum(pos, i);
        res=min()

    }
}
void solve()
{
    int i, j, k;
    string s;
    cin >> s;
    auto split = splitstring(s);
    string x = split[0], y = split[1];


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