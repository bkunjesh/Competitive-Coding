//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
// #define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
const int inf = 1e18;
const int N=200005;

int n;
map<pair<int,int>,int> ans;
int query(int start,int end)
{
	if(ans.count({start,end})) return ans[{start,end}];

    if(start==end) return -1;
	
	cout<<"? "<<start<<" "<<end<<endl;
	int x;
	cin>>x;
	
	return ans[{start,end}]=x;
}
void answer(int x)
{
	cout<<"! "<<x<<endl;
    exit(0);
}
void solve()
{
    int i, j, k,left,right,sol;
    
    cin>>n;
    int start=1,end=n;
    int x=query(start,end);
    if(query(start,x)==x)
    {
    	end=x-1;
    	while(start<=end)
    	{
    		int mid=(start+(end-start)/2);
    		
    		if(query(mid,x)==x)
    		{
    			sol=mid;
    			start=mid+1;
			}
			else
			{
				end=mid-1;
			}
		}
	}
	else
	{
		start=x+1;
		while(start<=end)
		{
			int mid=(start+(end-start)/2);
    		
    		if(query(x,mid)==x)
    		{
    			sol=mid;
    			end=mid-1;
			}
			else
			{
				start=mid+1;
			}
		}
	}
	answer(sol);
    
    
    // cout<<"? "<<start<<" "<<end<<endl;
    // cin>>x;
    // while(1)
    // {
    //     cout<<"? "<<start<<" "<<end<<endl;
    //     cin>>x;
    //     if(x-start==1)
    //     {
    //         cout<<"! "<<start<<endl;
    //         break;
    //     }
    //     else if(end-x==1)
    //     {
    //         cout<<"! "<<end<<endl;
    //         break;
    //     }

    //     if(x-start==0)
    //     {
    //         start=x+1;
    //         continue;
    //     }
    //     else if(end-x==0)
    //     {
    //         end=x-1;
    //         continue;
    //     }

    //     if(x-start>1)
    //     {
    //         cout<<"? "<<start<<" "<<x<<endl;
    //         cin>>left;
    //         if(left==x)
    //         {
    //             end=x-1;
    //             continue;
    //         }
    //     }
    //     if(end-x>1)
    //     {
    //         cout<<"? "<<x<<" "<<end<<endl;
    //         cin>>right;
    //         if(right==x) 
    //         {
    //             start=x+1;
    //             continue;
    //         }
    //     }

    // }
//
//    while(1)
//    {
//        int overall,l,r;
//        int mid=(start+end)/2;
//
//        cout<<"? "<<start<<" "<<end<<endl;
//        cin>>overall;
//
//        if(end-start==1)
//        {
//            if(overall==start)
//            {
//                cout<<"! "<<end<<endl;
//                break;
//            }
//            else
//            {
//                cout<<"! "<<start<<endl;
//                break;
//            }
//        }
//
//        if(mid-start>0)
//        {
//            cout<<"? "<<start<<" "<<mid<<endl;
//            cin>>l;
//            if(overall==l)
//            {
//                end=mid-1;
//                continue;
//            }
//        }
//        
//        if(end-mid>0)
//        {
//            cout<<"? "<<mid<<" "<<end<<endl;
//            cin>>r;
//            if(overall==r)
//            {
//                start=mid+1;
//                continue;
//            }
//        }
//
//	   }        
    

    
    
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