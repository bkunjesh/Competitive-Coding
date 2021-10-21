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

    int h;
    cin>>n>>h;
    vector<int> a(n);
    f(i,n) cin>>a[i];
    sort(a.begin(),a.end(),greater<int>());
    if(a[0]>=h)
    {
        cout<<1<<endl;
        return;
    }
    else
    {
        int sum=a[0]+a[1];
        int p=(h)/sum;
        if(p*sum<h) p++;
        int ans=2*p;
        if(p*sum-a[1]>=h) ans--;
        cout<<ans<<endl;

        // int sum=a[0]+a[1];
        // int p=(h+a[1])/sum;
        // if(a[0]*p+a[1]*(p-1)>=h)
        // {
        //     cout<<2*p-1<<endl;
        // }
        // else
        // {
        //     p=(h)/sum;
        //     int ans=2*p;
        //     if(p*(sum)<h) ans++;
        //     cout<<ans<<endl;
        // }
        // int x=a[0]+a[1];
        // int ans=(h+x-1)*2/x;

        // int tmp=(ans*x)/2-a[1];
        // if(tmp>=h) ans--;

        // cout<<ans<<endl;
        // return;
    }

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