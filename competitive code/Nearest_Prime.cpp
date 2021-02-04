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
vector<int> prime;
void make_prime_vect()
{
    int MAXN = 4000000;
    vector<int> br(MAXN + 1, 0);
    for (int i = 2; i <= MAXN;i++)
    {
        if(br[i]==0)
        {
            for (int j = i * 2; j <= MAXN;j=j+i)
            {
                br[j] = 1;
            }
        }
    }
    for (int i = 2; i <= MAXN;i++)
    if(br[i]==0)
        prime.push_back(i);
}
void solve()
{
    int i, j, k;

    cin >> n;
    auto it = upper_bound(prime.begin(), prime.end(), n);
    int ans;
    if(it!=prime.end())
    {
        ans = *it;
    }
    it--;
    if((ans-n)>=(n-*it))
    {
        ans = *it;
    }
    cout << ans << endl;
    return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    cin >> t;
    make_prime_vect();
    while (t--)
    {
        solve();		
    }
return 0;
}