//@CodesUp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define mod 1000000007
const int inf = 1e18;
int N = 200005;

int n;

void solve()
{
    int i, j, k, sum = 0, flag = 1;
    cin >> n;
    vector<int> a(n);
    f(i, n) cin >> a[i],sum+=a[i];
    sort(a.begin(),a.end());
    int mx=a[n-1];
    // rep(i,n-1)
    // {
    //     mx[i]=a[n-1];
    //     if(i==n-1) mx[i]=a[n-2];
    // }
     if ((mx * (n - 1) >= sum))
        {
            cout << abs(mx * (n - 1) - sum) << endl;
        }
        else {
 
            int x = (sum % (n - 1));
            if (x != 0) cout << (n - 1 - x) << endl;
            else cout << "0" << endl;
 
 
        }
 
    // vector<int> ans;
    // for(i=0;i<n;i++)
    // {
    //     int osum=sum-a[i];
    //     int needsum=mx[i]*(n-1)-osum-a[i];
    //     if(needsum>0)
    //     {
    //         ans.push_back(needsum);      
    //     }
    //     else if(needsum<0)
    //     {
    //         needsum=-needsum;
    //         int temp=needsum%(n-1);
    //         if(temp==0) continue;
    //         ans.push_back(n-1-(temp));
    //     }
    // }
    // if (ans.size()==0) 
    // {
    //     cout<<0<<endl;
    //     return;
    // }

    // int as=ans[0];
    // for(i=1;i<ans.size();i++)
    // {
    //     as=as*ans[i]/__gcd(as,ans[i]);
    // }
    // cout<<as<<endl;


    // // sort(a.begin(), a.end());
    // // f(i, n)
    // // {
    // //     diff[i] = a[n - 1] - a[i], sum += diff[i];
    // // }
    // // // if (flag)
    // // // {
    // // //     cout << 0 << endl;
    // // //     return;
    // // // }
    // // i = 0;
    // // //f(i, n)
    // // {
    // //     int cursum = sum - diff[i];

    // //     int curans;
    // //     if(a[i]==cursum)
    // //     {
    // //         curans = 0;
    // //     }
    // //     else if (a[i] > cursum)
    // //     {
    // //         int temp = a[i] - cursum;
    // //         curans = ((n - 1) - temp % (n - 1));
    // //     }
    // //     else
    // //     {
    // //         curans = cursum - a[i];
    // //     }

    // //     // cout << cursum << " ";
    // //     // if ((cursum % (n - 2)) == 0)
    // //     //     cursum = 0;
    // //     ans = max(ans, curans);
    // // }
    // // cout << ans << endl;

    return;
}

signed main()
{
    fast int t = 1, i, j, k;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}