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

void solve()
{
    int i, j, k;
    cin >> n;
    vector<int> a;
    while(n--)
    {
        int x;
        cin >> x;
        if(x!=1){
            while(a.size()>0&&a.back()+1!=x)
            {
                a.pop_back();
            }
            if(a.size()>0&&a.back()+1==x)
            {
                a.pop_back();
            }
            a.push_back(x);
        }
        else {
            a.push_back(x);
        }

        for (i = 0; i < a.size() - 1;i++)
        {
            cout << a[i] << ".";
        }
        cout << a[a.size() - 1] << endl;
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