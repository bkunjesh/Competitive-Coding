#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int t,n,element,count;
	vector <int> p;
	cin>>t;
	while(t--)
	{
		count=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>element;
			p.push_back(element);
		}
		vector <int> v(5,751);
		
		vector<int>::iterator i;
		
		for(i=p.begin();i!=p.end();i++)
		{
			
			v.push_back(*i);
			
			int j=1;
	        vector<int>::iterator k,m;
	           for(k=v.end()-5;k!=v.end()-1;k++)
	          {	          	cout<<endl<<v.back()<<endl;
	          		if(*k<v.back())
		             {
		             	//cout<<"in"<<endl;
			            j=0;
			            break;
		             }		             		             
	          }
			
			if(j==1)
			count++;
		}
		cout<<count;
	}
}

/*int min(vector<int> v)
{
	int j=1;
	vector<int>::iterator i;
	
	for(i=v.end()-5;i<v.end();i++)
	{
		if(*i<*v.end())
		{
			j=0;
			break;
		}
	}
	return j;
}*/
