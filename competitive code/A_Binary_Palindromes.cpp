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

void solve()
{
    int i, j, k,zcnt=0,ocnt=0,ans,socnt=0,secnt=0;
    
    cin>>n;
    vector<int> a;
    f(i,n)
    {
        string s;
        cin>>s;
        a.push_back(s.size());

        if(s.size()%2==0) secnt++;
        else socnt++;

        for(auto it:s) 
        if(it=='1') ocnt++;
        else zcnt++;
    }

    if(socnt==0&&ocnt%2==1&&zcnt%2==1)
    {
        cout<<n-1<<endl;
    }
    else
    {
        cout<<n<<endl;
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