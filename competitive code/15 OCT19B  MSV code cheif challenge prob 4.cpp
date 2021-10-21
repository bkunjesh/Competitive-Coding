#include <iostream>
#include<vector>
using namespace std;

int main() {
    int t,element,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector <long long> a;
        for(int i=0;i<n;i++)
        {
            cin>>element;
            a.push_back(element);
        }
        int max_star=0;
        vector<long long>::iterator j,k;
        for(j=a.begin()+1;j<a.end();j++)
        {
        	cout<<endl<<*j;
            int star=0;
        
            for(k=j-1;k>=a.begin();k--)
            {
            	cout<<endl<<"k "<<*k<<endl;
                if(*k%*j==0)
                star++;
            }
            if(star>max_star)
            max_star=star;
        }
        cout<<max_star<<endl;
    }
    return 0;
}

