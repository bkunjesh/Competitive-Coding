#include<iostream>
#include<vector>
using namespace std;
vector<int> a,b,c;
void combination(int i,int j)
{
    a.push_back(i+j);
    b.push_back(i-j);
     c.push_back(j-i);
     
}

 int search(vector<int> vec,int k)
{
    for(int i=1;i<vec.size();i++)
    {
       // cout<<vec[i]<< " "<<k<<endl;
        if(k==vec[i]) return 1;
    }
    return 0;
}

string check(int shot[],int k)
{
  
combination(shot[0],shot[1]);
combination(a[0],shot[2]);
combination(b[0],shot[2]);
combination(c[0],shot[2]);
//cout<<a[0]<< " "<<b[0]<<" "<<c[0]<<endl;
 int x=search(a,k);
 //cout<<x;
int y=search(b,k);
int z=search(c,k);
if(x||y||z)
  return "WIN";
    else 
    return "LOSE";
}
int main()
{
    int num;
    cin>>num;
    int shot[3];
    string result;
    for(int i=0;i<num;i++)
    {
        int k;
        cin>>k;
        for(int i=0;i<3;i++) cin>>shot[i];
        result=check(shot,k);
        cout<<result<<endl;
        a.clear();
        b.clear();
        c.clear();
    }
}

