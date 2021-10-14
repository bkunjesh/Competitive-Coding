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
bool cmp(pair<int,int> &a,pair<int,int> &b)
{
    int diffa=a.F-a.S;
    int diffb=b.F-b.S;

    return diffa>diffb;

}

void solve()
{

    int i, j, k,sumb=0,suma=0;

    cin>>n;
    vector<int> a(n),b(n);
    vector<pair<int,int>> p;

    f(i,n) cin>>a[i]>>b[i],suma+=a[i],sumb+=b[i],p.push_back({a[i],b[i]});
    sort(p.begin(),p.end(),cmp);
    int ans=0;
    f(i,n) 
    {
        int d=p[i].F-p[i].S;
        int tmp=p[i].F*(i)+p[i].S*(n-(i+1));
        // int tmp=d*i + n*p[i].S - p[i].F;

        // dbg(p[i].F,p[i].S,tmp);
        
        ans+=(tmp);

    }
    cout<<ans<<endl;


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