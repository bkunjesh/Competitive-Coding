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

int ans;
double maxavg;

vector<int> heighestTenure(EmployeeNode *root)
{
    vector<int> res(2, 0); //sz,sum;

    for (int i = 0; i < root->subEmployeeNode.size();i++)
    {
        vector<int> temp=heighestTenure(root->subEmployeeNode[i]);
        res[0] += temp[0];
        res[1] += temp[1];
    }

    res[0]++;
    res[1] += root->value;

    double val = res[1] / res[0];
    if (val > maxavg && root->subEmployeeNode.size()!=0)
    {
        maxavg = val;
        ans = root->value;
    }

    return res;
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