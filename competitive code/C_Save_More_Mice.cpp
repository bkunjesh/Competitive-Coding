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

void solve()
{

    int i, j, k;

    cin>>n>>k;
    vector<int> a;
    map<int,vector<int>> mp;
    f(i,k)
    {
        cin>>j;
        a.push_back(j);
    }
    sort(a.begin(),a.end());
    auto check=[&](int ind,int t)
    {
        int noofele=0,timetaken=0;
        for(i=ind+1;i<k;i++)
        {
            if(i==(k-1))
            {
                timetaken+=((i-ind)*(a[i]-a[i-1]));
                timetaken+=((i-ind+1)*(n-a[i]));
            }
            else
            {
                timetaken+=((i-ind)*(a[i]-a[i-1]));
            }
        }
        // dbg(timetaken,t);
        if(timetaken<n) return 1;
        else return 0;
    };


    int l=0,h=k-1;
    int ansind=n;
    while(l<=h)
    {

        int mid=(l+h)/2;
        int time=a[mid];
        // dbg(l,h,mid);
        if(check(mid,time))
        {
            ansind=mid;
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<k-ansind<<endl;
    // int curtime=0,ans=0;
    // for(i=k-1;i>=0;i--)
    // {
    //     mp[a[i]].push_back(curtime+(n-a[i]));
    //     curtime=curtime+(n-a[i]);
    //     if(curtime<=a[i]) ans++;
    //     else
    //     {
    //         break;
    //     }
    // }
    // cout<<ans<<endl;



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