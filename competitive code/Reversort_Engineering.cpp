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

    int c;
    cin >> n >> c;
    vector<int> a;
    int flag = 0;
    for (int i = 1; i <= n;i++)
    {
        a.push_back(i);
    }
    do{
        vector<int> temp(a);
        int ans = 0;
        for (i = 0; i < n-1;i++)
        {
            for (int j = i; j < n;j++)
            {
                if(temp[j]==(i+1))
                {
                    ans += (j - i + 1);
                    reverse(temp.begin() + i, temp.begin() + j + 1);
                    break;
                }
            }
        }

        if(ans==c)
        {
            flag = 1;
            break;
            
        }

    } while (next_permutation(a.begin(), a.end()));

    if(flag)
    {
        for(auto it:a)
            cout << it << " ";
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }

        return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    cin >> t;
    rep(test, t)
    {
        cout << "Case #" << test << ": ";
        solve();
    }
return 0;
}
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif