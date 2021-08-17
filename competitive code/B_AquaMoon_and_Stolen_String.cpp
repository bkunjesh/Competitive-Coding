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
    int i, j, k,m;
    cin>>n>>m;
    vector<string> a(n),b(n-1);
    f(i, n) cin >> a[i];
    f(i, n - 1) cin >> b[i];
    set<int> suspect;
    f(i, n) suspect.insert(i);

    f(j,m)
    {
        int bfreq[26];
        memset(bfreq, 0, sizeof(bfreq));
        f(i, n - 1) bfreq[b[i][j] - 'a']++;
        vector<int> afreq[26];
        f(i,n) afreq[a[i][j]-'a'].push_back(i);

        f(i,26)
        {
            if(bfreq[i]==afreq[i].size())
            {
                for(auto ind:afreq[i])
                {
                    suspect.erase(ind);
                }
            }
        }
        if(suspect.size()==1)
        {
            cout << a[(*suspect.begin())] << endl;
            return;
        }
    }
    cout << a[(*suspect.begin())] << endl;
    return;

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