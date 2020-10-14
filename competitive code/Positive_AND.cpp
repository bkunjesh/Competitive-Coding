//@bkunjesh
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,k) for(i=0;i<k;i++)
#define endl "\n"
#define rep(i,n) for(i=1;i<=n;i++)
ll n;
int main()
{
    ll test = 1, i, j, k;
    cin >> test;
    while (test--)
    {
        cin>>n;
        vector<ll> arr(n+1);
        rep(i,n) arr[i]=i;

        i=2;
        bool flag=1;
        while(i<=n)
        {
            if(i==n)
            {
                flag=0;
                break;
            }
            swap(arr[i],arr[i+1]);
            i<<=1;
        }
        if(n>3) swap(arr[1],arr[3]);
        if(flag)
        {
            rep(i,n) cout<<arr[i]<<" ";
            cout<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
        

    }
return 0;
}