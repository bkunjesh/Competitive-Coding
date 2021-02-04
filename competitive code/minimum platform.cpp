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
int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    int i, j, k;
    multimap<int, int> s;
    for (i = 0; i < n;i++)
    {
        s.insert({arr[i], 1});
        s.insert({dep[i], -1});
    }
    int cnt = 0, ans = 0;
    for(auto it:s)
    {
        cnt += it.S;
        ans = max(cnt, ans);
    }
    return ans;
}
void solve()
{
    int i, j, k;
    
    cin>>n;
    int arr[n], dep[n];
    f(i, n) cin >> arr[i];
    f(i, n) cin >> dep[i];
    cout << findPlatform(arr, dep, n);



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