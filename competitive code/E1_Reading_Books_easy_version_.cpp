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
    int i, j, k,p;

    cin >> n >> p;
    vector<vector<int>> vec(n, vector<int>(3));
    vector<int> a,b,both;
    f(i, n) 
    {
        f(j, 3) 
        {
            cin >> vec[i][j];
        }
        if(vec[i][1]==1&&(vec[i][2]==1))
        {
            both.push_back(vec[i][0]);
        }
        else if(vec[i][1]==1)
        {
            a.push_back(vec[i][0]);
        }
        else if(vec[i][2]==1)
        {
            b.push_back(vec[i][0]);
        }
    }
    sort(vec.begin(), vec.end());
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(both.begin(), both.end());
    int ap=0,bp=0,ans=0;
    i=0,j=0,k=0;
    while(ap<p||bp<p)
    {
        int x = (i < a.size()) ? a[i] : (ap<p)?1e9:0;
        int y = (j < b.size()) ? b[j] : (bp<p)?1e9:0;
        int z = (k < both.size()) ? both[k] : 1e9;
        if (i >= a.size() && j >= b.size() && k >= both.size())
        {
            break;
        }
        if(((ap<p&&i>=a.size())||(bp<p&&j>=b.size()))&&(k>=both.size()))
        {
            break;
        }
        if (k<both.size()&& z<= (x + y))
        {
            ans += z;
            k++, ap++, bp++;
        }
        else
        {
            if(i<a.size()&&ap<p)
            {
                ans += x;
                i++;
                ap++;
            }
            if(j<b.size()&&bp<p)
            {
                ans += y;
                j++;
                bp++;
            }
        }
    }
    if(ap>=p&&bp>=p)
    {
        cout << ans << endl;
        return;
    }
    else
    {
        cout << -1 << endl;
        return;
    }


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