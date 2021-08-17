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
    int win=(n-1)/2;
    int loose=(n-1)/2;
    int tie=(n-1)%2;

    vector<vector<int>> a(n+1,vector<int>(3,0));

    if (n % 2)
		{
			for (int i = 1; i < n; i++)
			{
				for (int j = i + 1; j <= n; j++)
				{
					if (j - i <= (n / 2)) cout << "1 ";
					else cout << "-1 ";
 
				}
			}
		}
 
		else {
			for (int i = 1; i < n; i++)
			{
				for (int j = i + 1; j <= n; j++)
				{
					if (j - i < (n / 2)) cout << "1 ";
					else if ((j - i) == (n / 2)) cout << "0 ";
					else cout << "-1 ";
 
				}
			}
 
 
		}
		cout << endl;
    
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