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
    int i, j, k;
    
    cin>>n;
    vector<int> a(n);
    map<int,int> eleFreq;
    f(i,n) cin>>a[i],eleFreq[a[i]]++;
    map<int,int> freqOfFreq;
    for(auto it:eleFreq) freqOfFreq[it.S]++;

    int ans=n;
    
    for(auto cur=freqOfFreq.begin();cur!=freqOfFreq.end();cur++)
    {
        int val=0;
        int j=0;
        auto prev=freqOfFreq.begin();
        while(prev!=cur)
        {
            val+=(prev->F)*(prev->S);
            prev++;
        }
        auto next=cur;
        while(next!=freqOfFreq.end())
        {
            val+=(next->F-cur->F)*(next->S);
            next++;
        }
        ans=min(ans,val);
    }

    cout<<ans<<endl;
    
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