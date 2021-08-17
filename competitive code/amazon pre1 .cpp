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

pair<int,int> findTruckSpacePair(int truckSpace,int numPackage,vector<int> &packageSpace)
{
    sort(packageSpace.begin(), packageSpace.end());
    int sumneed = truckSpace - 30;
    if(sumneed < 0)
        return make_pair(-1, -1);
    int i = 0, j = numPackage - 1;

    while(i<j)
    {
        if(packageSpace[i]+packageSpace[j]<sumneed)
            i++;
        else if(packageSpace[i]+packageSpace[j]>sumneed)
            j--;
        else if(packageSpace[i]+packageSpace[j]==sumneed)
            return make_pair(i,j);
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