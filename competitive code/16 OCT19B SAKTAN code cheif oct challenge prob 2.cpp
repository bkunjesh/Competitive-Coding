#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t,n,m,q,x,y;
    
    cin>>t;
    while(t--)
    {
        int count=0;
        cin>>n>>m>>q;
        vector <int> X(n+1,0),Y(m+1,0);
        int  a[n+1][m+1];
        for(int i=1;i<=q;i++)
        {
            cin>>x>>y;
            X[x]++;
            Y[y]++;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                a[i][j]=X[i]+Y[j];
                if((a[i][j])%2!=0)
                count++;
            }
        }
        cout<<count<<endl;
    }
	
	return 0;
}

