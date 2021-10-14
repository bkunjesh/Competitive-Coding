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

int n;

void solve()
{

    int i, j, k;

    cin>>n;
    int a[n][5];
    f(i,n) f(j,5) cin>>a[i][j];

    f(i,5)
    {
        for(j=i+1;j<5;j++)
        {
            int ith=0,jth=0,both=0;

            for(k=0;k<n;k++)
            {
                if(a[k][i]==1&&a[k][j]==1) both++;
                else if(a[k][i]==1) ith++;
                else if(a[k][j]==1) jth++;
            }
            int need = n/2-ith + n/2 - jth;
            if(both>=need && ith<=n/2 && jth<=n/2)
            {
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;


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