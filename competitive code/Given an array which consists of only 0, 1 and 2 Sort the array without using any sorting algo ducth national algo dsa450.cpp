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
void sort012(int a[], int n)
    {
        // coode here 
        int i=0,j=0,k=n-1; //i-> low , j-> mid, k-> high
        for(;j<=k;)
        {
            if(a[j]==1) j++;
            else if(a[j]==0)
            {
                swap(a[i++],a[j++]);
            }
            else if(a[j]==2)
            {
                swap(a[k--],a[j]);
            }
        }
    }
void solve()
{
    int i, j, k;
    cin >> n;
    int a[n];
    f(i, n) cin >> a[i];
    sort012(a, n);
    f(i, n) cout << a[i] << " ";

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