//@ikung
#include<bits/stdc++.h>
using namespace std;

int n;

void solve()
{
    int i, j, k,m;
    
    cin>>n>>m;
    vector<int> a(n);
    for (i = 0; i < n;i++) cin>>a[i];

    sort(a.begin(), a.end());

    for (i = 0;i<n;i++)
    {
        if(a[i]==m)
        {
            cout << i << endl;
            return;
        }
    }

        return;
}

int main()
{
    int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();		
    }
return 0;
}