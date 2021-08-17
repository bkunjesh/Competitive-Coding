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

int maxNoOfUnit(int boxSize,vector<int> &boxes,int unitSize, vector<int> &unitPerBox,int truckSize)
{
    vector<pair<int, int>> a;
    for (int i = 0; i < boxSize;i++) a.push_back({unitPerBox[i], boxes[i]});
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    int ans = 0;
    for (int i = 0; i < a.size();i++)
    {
        if(truckSize>=a[i].second)
        {
            ans += (a[i].first * a[i].second);
            truckSize -= a[i].second;
        }
        else
        {
            ans += (a[i].first * truckSize);
            truckSize -= truckSize;
        }
        if(truckSize<=0)
            break;
    }
    cout << ans << endl;
    return ans;
}

void solve()
{
    int i, j, k;
    vector<int> boxes = {1, 2, 3};
    vector<int> unitPerBox = {3, 2, 1};
    maxNoOfUnit(3, boxes, 3, unitPerBox, 3);

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