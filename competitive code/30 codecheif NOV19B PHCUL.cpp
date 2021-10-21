#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
long double distance(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
vector<long double> n_two_timewala(vector<long int> z,vector<long int> r)
{
    vector<long double> laststep;
    for(auto i=z.begin();i<z.end()-1;)
    {
        double min=1e10;
        for(auto j=r.begin();j<r.end()-1;)
        {
            if(min>distance(*j,*(j+1),*i,*(i+1)))
             min=distance(*j,*(j+1),*i,*(i+1));
             j=j+2;
        }
        laststep.push_back(min);
        i=i+2;
    }
    return laststep;
}
/*long double n_timewala(long int x,long int y,vector<long int> r)       //each a2 take min
{
    long double min=pow(10,9);
        for(auto j=r.begin();j<r.end()-1;)
        {
            if(min>distance(*j,*(j+1),x,y))
             min=distance(*j,*(j+1),x,y);
             j=j+2;
        }
        return min;
}*/
long double n2_timewala(vector<long int> xy,vector<long int> a1,vector<long int> a2,vector<long int> a3)
{
    long double min=1e10;
    vector<long double> laststep=n_two_timewala(a2,a3);
   
    for(auto i=a1.begin();i<a1.end()-1;)
    {
        int k=0;
        for(auto j=a2.begin();j<a2.end()-1;)
        {
            if(min>(distance(xy[0],xy[1],*i,*(i+1))+distance(*i,*(i+1),*j,*(j+1))+laststep[k]))
            {
                min=distance(xy[0],xy[1],*i,*(i+1))+distance(*i,*(i+1),*j,*(j+1))+laststep[k];
                //cout<<*i<<" "<<" "<<*j<<" "<<endl;
            }
            k++;
            j=j+2;
        }
        i=i+2;
    }
    laststep.clear();
    return min;
}

int main()
{
   
        ios::sync_with_stdio(false);
cin.tie(0);
cout << fixed << setprecision(12);
    long int i,element,x,y,t,n,m,k;
    cin>>t;
    while(t--)
    {
        vector<long int> ab,cd,ef,xy;
        cin>>x>>y;
        xy.push_back(x);
        xy.push_back(y);
        cin>>n>>m>>k;
        for(i=0;i<2*n;i++)
        {
            cin>>element;
            ab.push_back(element);
        }
        for(i=0;i<2*m;i++)
        {
            cin>>element;
            cd.push_back(element);
        }
        for(i=0;i<2*k;i++)
        {
            cin>>element;
            ef.push_back(element);
        }
        //path 1 x,y a,b c,d e,f  
        long double p1=n2_timewala(xy,ab,cd,ef);
        long double p2=n2_timewala(xy,cd,ab,ef);
       
        cout<<min(p1,p2)<<endl;
       
    }
   
    return 0;
}


